#include "food.h"

void Food::Remove() {
    apple->Clear();
}

void Food::RandomNum(Snake* nsnake) {
    x = rand() % 21 + 1;
    y = (rand() % 21 + 1) * 2;
    for (auto& point: nsnake->body) {
        while (point.getX() == x && point.getY() == y) {
            x = rand() % 22 + 1;
            y = (rand() % 22 + 1) * 2;
        }
    }
    apple->setX(x);
    apple->setY(y);
    apple->Food();
}