#ifndef FOOD_H
#define FOOD_H

#include "point.h"
#include <stdlib.h>

class Food {
    public:
        Food() {
            apple = new Point(rand() % 22 + 1, (rand() % 22 + 1) * 2);
            apple->Food();
        }
        void Remove();
        bool CheckPos(int x, int y);
    private:
        Point *apple;
};

#endif