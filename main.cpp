#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

class Ball {
public:
    float x, y;
    float dx, dy;
    int r;
    int color;

    Ball() {
        r = 20;
        x = rand() % (getmaxx() - 2*r) + r;
        y = rand() % (getmaxy() - 2*r) + r;

        dx = (rand() % 3 + 2) * (rand() % 2 ? 1 : -1);
        dy = (rand() % 3 + 2) * (rand() % 2 ? 1 : -1);

        color = rand() % 14 + 1;
    }

    void move() {
        x += dx;
        y += dy;

        dx *= 0.999;
        dy *= 0.999;

        if (x - r < 0 || x + r > getmaxx()) dx = -dx;
        if (y - r < 0 || y + r > getmaxy()) dy = -dy;
    }

    void draw() {
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        fillellipse((int)x, (int)y, r, r);
    }
};

void improvedCollision(Ball b[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            float dx = b[i].x - b[j].x;
            float dy = b[i].y - b[j].y;
            float dist2 = dx*dx + dy*dy;
            float minDist = b[i].r + b[j].r;

            if (dist2 <= minDist * minDist) {

                float dist = sqrt(dist2);
                if (dist == 0) dist = 1;
                float nx = dx / dist;
                float ny = dy / dist;

                b[i].x += nx * 1.5;
                b[j].x -= nx * 1.5;
                b[i].y += ny * 1.5;
                b[j].y -= ny * 1.5;

                float tempdx = b[i].dx;
                float tempdy = b[i].dy;
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

    bool paused = false;

    while (true) {

        if (kbhit()) {
            char ch = getch();

            if (ch == ' ') {
                paused = !paused;
            }
            else if (ch == 27) {
                break;
            }
        }

        cleardevice();

        if (!paused) {
            for (int i = 0; i < N; i++)
                balls[i].move();

            improvedCollision(balls, N);
        }

        for (int i = 0; i < N; i++)
            balls[i].draw();

        delay(10);
    }

    return 0;
}
