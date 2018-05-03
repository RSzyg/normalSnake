#include "point.h"
#include "tools.h"
#include <iostream>
using std::cout;

void Point::Block() {
    SetCursorPos(x, y);
    cout << "◼";
    fflush(stdout);
}

void Point::Circle() {
    SetCursorPos(x, y);
    cout << "●";
    fflush(stdout);
}