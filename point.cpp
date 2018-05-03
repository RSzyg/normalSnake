#include "point.h"
#include "tools.h"
#include <iostream>
using std::cout;

void Point::Block() {
    SetCursorPos(_x, _y);
    cout << "◼";
    fflush(stdout);
}

void Point::Circle() {
    SetCursorPos(_x, _y);
    cout << "●";
    fflush(stdout);
}

int Point::x() {
    return _x;
}

int Point::y() {
    return _y;
}