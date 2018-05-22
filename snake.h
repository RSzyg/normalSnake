#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <ncurses.h>
#include "point.h"
#include "food.h"

class Food;
class Snake {
    public:
        Snake() {
            body.emplace_back(5, 10);
            body.emplace_back(5, 8);
            body.emplace_back(5, 6);
            direction = KEY_RIGHT;
        }
        void Init();
        void Move(Food& nfood);
        int ChangeDirection(int);
        Point Head();
    private:
        std::deque<Point> body;
        friend class Food;
        int direction;
};

#endif