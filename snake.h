#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <ncurses.h>
#include "point.h"

class Snake {
    public:
        Snake() {
            body.emplace_back(5, 10);
            body.emplace_back(5, 8);
            body.emplace_back(5, 6);
            direction = KEY_RIGHT;
        }
        void Init();
        void Move();
        int ChangeDirection(int);
        Point Head();
    private:
        std::deque<Point> body;
        int direction;
};

#endif