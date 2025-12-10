#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

class Ball {
public:
    int x, y;
    int dx, dy;
    int r;
    int color;

    Ball() {
        r = 23;
        x = rand() % (getmaxx() - 2*r) + r;
        y = rand() % (getmaxy() - 2*r) + r;

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
        fillellipse(x, y, r, r);
    }
};


void simpleCollision(Ball b[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int dx = b[i].x - b[j].x;
            int dy = b[i].y - b[j].y;
            int dist2 = dx*dx + dy*dy;
            int minDist = b[i].r + b[j].r;

            if (dist2 <= minDist * minDist) {
                // tukar kecepatan
                int tempdx = b[i].dx;
                int tempdy = b[i].dy;
                b[i].dx = b[j].dx;
                b[i].dy = b[j].dy;
                b[j].dx = tempdx;
                b[j].dy = tempdy;
            }
        }
    }
}

int main() {
    initwindow(800, 600);
    srand(time(NULL));

    const int N = 40;
    Ball balls[N];

    while (!kbhit()) {
        cleardevice();

        // gerakkan bola
        for (int i = 0; i < N; i++)
            balls[i].move();

        // deteksi & tangani tabrakan
        simpleCollision(balls, N);

        // gambar bola
        for (int i = 0; i < N; i++)
            balls[i].draw();

        delay(10);
    }

    return 0;
}
