#ifndef FOOD_H
#define FOOD_H

#include "point.h"
#include <stdlib.h>
#include "snake.h"

class Snake;
class Food {
    public:
        Food() {
            x = 0;
            y = 0;
            apple = new Point(x, y);
        }
        void RandomNum(Snake* nsnake);
        void PrintApple();
    private:
        Point *apple;
        int x, y;
        friend class Snake;
};

#endif