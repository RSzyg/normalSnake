#include "point.h"
#include "tools.h"
#include <iostream>
#include <ncurses.h>

void Point::Block() {
    move(_x, _y);
    printw("◼ ");
    refresh();
}

void Point::Circle() {
    move(_x, _y);
    printw("● ");
    refresh();
}

void Point::Clear() {
    move(_x, _y);
    printw("  ");
    refresh();
}

int Point::x() {
    return _x;
}

int Point::y() {
    return _y;
}