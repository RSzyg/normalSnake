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

int Snake::ChangeDirection(int ch) {
    switch (ch) {
        case KEY_UP:
            if (direction != KEY_DOWN) {
                direction = ch;
            }
            return 2;
        case KEY_DOWN:
            if (direction != KEY_UP) {
                direction = ch;
            }
            return 2;
        case KEY_RIGHT:
            if (direction != KEY_LEFT) {
                direction = ch;
            }
            return 2;
        case KEY_LEFT:
            if (direction != KEY_RIGHT) {
                direction = ch;
            }
            return 2;
        case ERR:
            return 2;
        case 27:
            return 0;
        default:
            return 1;
    }
}

Point Snake::Head() {
    return body.front();
}
