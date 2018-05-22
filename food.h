#ifndef FOOD_H
#define FOOD_H

#include "point.h"
#include <stdlib.h>
#include "snake.h"

class Food {
    public:
        Food() {
            x = 0;
            y = 0;
            apple = new Point(x, y);
        }
        void RandomNum();
        void Remove();
    private:
        Point *apple;
        int x, y;
        friend class Snake;
};

#endif