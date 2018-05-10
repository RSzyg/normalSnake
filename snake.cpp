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
            body.emplace_front(body.front().getX() + 1, body.front().getY());
            break;
        case KEY_UP:
            body.emplace_front(body.front().getX() - 1, body.front().getY());
            break;
        case KEY_RIGHT:
            body.emplace_front(body.front().getX(), body.front().getY() + 2);
            break;
        case KEY_LEFT:
            body.emplace_front(body.front().getX(), body.front().getY() - 2);
            break;
        default:
            break;
    }
    body.front().Circle();
    body.back().Clear();
    body.pop_back();
}

void Snake::ChangeDirection(int newDirection) {
    direction = newDirection;
}

Point Snake::Head() {
    return body.front();
}
