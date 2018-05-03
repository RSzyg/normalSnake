#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"

class Snake {
    public:
        Snake() {
            body.emplace_back(5, 8);
            body.emplace_back(5, 7);
            body.emplace_back(5, 6);
        }
        void Move();
    private:
        std::deque<Point> body;
        int direction;
};

#endif