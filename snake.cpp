#include "snake.h"
#include <ncurses.h>

void Snake::Init() {
    for (auto& point: body) {
        point.Circle();
    }
}

void Snake::Move() {
    switch(direction) {
        case KEY_DOWN:
            body.emplace_front(body.front().x() + 2, body.front().y());
            break;
        case KEY_UP:
            body.emplace_front(body.front().x() - 2, body.front().y());
            break;
        case KEY_RIGHT:
            body.emplace_front(body.front().x(), body.front().y() + 2);
            break;
        case KEY_LEFT:
            body.emplace_front(body.front().x(), body.front().y() - 2);
            break;
        default:
            break;
    }
    body.front().Circle();
    body.back().Clear();
    body.pop_back();
}