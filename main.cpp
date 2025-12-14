#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

bool useQuadtree = false;
bool paused = false;
int page = 0;

class Ball {
public:
    float x, y;
    float dx, dy;
    int r;
    int color;

    Ball() {
        r = 18;
        x = rand() % (getmaxx() - 2 * r) + r;
        y = rand() % (getmaxy() - 2 * r) + r;
        dx = (rand() % 3 + 2) * (rand() % 2 ? 1 : -1);
        dy = (rand() % 3 + 2) * (rand() % 2 ? 1 : -1);
        color = rand() % 12 + 1;
    }

    void move() {
        x += dx;
        y += dy;
        if (x - r < 0 || x + r > getmaxx()) dx = -dx;
        if (y - r < 0 || y + r > getmaxy()) dy = -dy;
    }

    void draw() {
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        fillellipse((int)x, (int)y, r, r);
    }

    void collide(Ball& other) {
        float dx_ = other.x - x;
        float dy_ = other.y - y;
        float dist2 = dx_ * dx_ + dy_ * dy_;
        float minDist = r + other.r;

        if (dist2 < minDist * minDist && dist2 > 0.0001f) {
            float dist = sqrt(dist2);

            float nx = dx_ / dist;
            float ny = dy_ / dist;

            float overlap = 0.5f * (minDist - dist);
            x -= nx * overlap;
            y -= ny * overlap;
            other.x += nx * overlap;
            other.y += ny * overlap;

            float tx = -ny;
            float ty = nx;

            float v1n = dx * nx + dy * ny;
            float v1t = dx * tx + dy * ty;

            float v2n = other.dx * nx + other.dy * ny;
            float v2t = other.dx * tx + other.dy * ty;

            dx = v2n * nx + v1t * tx;
            dy = v2n * ny + v1t * ty;

            other.dx = v1n * nx + v2t * tx;
            other.dy = v1n * ny + v2t * ty;
        }
    }
};

class Quadtree {
public:
    int x, y, w, h;
    int kapasitas;
    Ball* objects[10];
    int jumlah;
    bool divided;
    Quadtree *nw, *ne, *sw, *se;

    Quadtree(int _x, int _y, int _w, int _h, int cap = 4) {
        x = _x; y = _y; w = _w; h = _h;
        kapasitas = cap;
        jumlah = 0;
        divided = false;
        nw = ne = sw = se = NULL;
    }

    bool contains(Ball* b) {
        return (b->x >= x && b->x <= x + w &&
                b->y >= y && b->y <= y + h);
    }

    void subdivide() {
        int hw = w / 2;
        int hh = h / 2;
        nw = new Quadtree(x, y, hw, hh, kapasitas);
        ne = new Quadtree(x + hw, y, hw, hh, kapasitas);
        sw = new Quadtree(x, y + hh, hw, hh, kapasitas);
        se = new Quadtree(x + hw, y + hh, hw, hh, kapasitas);
        divided = true;
    }

    void insert(Ball* b) {
        if (!contains(b)) return;
        if (jumlah < kapasitas) objects[jumlah++] = b;
        else {
            if (!divided) subdivide();
            nw->insert(b); ne->insert(b);
            sw->insert(b); se->insert(b);
        }
    }
};

void query(Quadtree* qt, Ball* target, Ball* hasil[], int& count) {
    if (!qt->contains(target)) return;
    for (int i = 0; i < qt->jumlah; i++)
        hasil[count++] = qt->objects[i];
    if (qt->divided) {
        query(qt->nw, target, hasil, count);
        query(qt->ne, target, hasil, count);
        query(qt->sw, target, hasil, count);
        query(qt->se, target, hasil, count);
    }
}

void bruteForceCollision(Ball balls[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            balls[i].collide(balls[j]);
}

void quadtreeCollision(Ball balls[], int n) {
    Quadtree root(0, 0, getmaxx(), getmaxy());
    for (int i = 0; i < n; i++) root.insert(&balls[i]);

    for (int i = 0; i < n; i++) {
        Ball* kandidat[50];
        int jumlah = 0;
        query(&root, &balls[i], kandidat, jumlah);
        for (int k = 0; k < jumlah; k++)
            if (kandidat[k] != &balls[i])
                balls[i].collide(*kandidat[k]);
    }
}

int main() {
    initwindow(1200, 650);
    srand(time(NULL));

    const int N = 4504;
    Ball balls[N];

    while (true) {
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        if (kbhit()) {
            char c = getch();
            if (c == 'w') useQuadtree = false;
            else if (c == 'q') useQuadtree = true;
            else if (c == ' ') paused = !paused;
            else if (c == 27) break;
        }

        setcolor(WHITE);
        if (paused)
            outtextxy(10, 10, (char*)"PAUSED");
        else if (useQuadtree)
            outtextxy(10, 10, (char*)"MODE: QUADTREE (Q)");
        else
            outtextxy(10, 10, (char*)"MODE: BRUTEFORCE (W)");

        if (!paused) {
            for (int i = 0; i < N; i++) balls[i].move();
            if (useQuadtree) quadtreeCollision(balls, N);
            else bruteForceCollision(balls, N);
        }

        for (int i = 0; i < N; i++) balls[i].draw();

        page = 1 - page;
        delay(10);
    }

    return 0;
}
