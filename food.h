#ifndef FOOD_H
#define FOOD_H

#include "point.h"
#include <stdlib.h>

class Food {
    public:
        Food() {
            apple = new Point(rand() % 22 + 1, rand() % 43 + 2);
            apple->Circle();
        }
        void Remove();
    private:
        Point *apple;
};

#endif