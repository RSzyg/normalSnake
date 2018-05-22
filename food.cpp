#include "food.h"

void Food::Remove() {
    apple->Clear();
}

bool Food::CheckPos(int x, int y) {
    if (apple->getX() == x && apple->getY() == y) {
        return true;
    } else return false;
}