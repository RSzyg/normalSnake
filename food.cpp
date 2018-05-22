#include "food.h"

void Food::Remove() {
    apple->Clear();
}

void Food::RandomNum() {
    x = rand() % 22 + 1;
    y = (rand() % 22 + 1) * 2;
    apple->setX(x);
    apple->setY(y);
    apple->Food();
}