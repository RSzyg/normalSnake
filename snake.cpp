#include "snake.h"
#include <ncurses.h>

void Snake::Init() {
    for (auto& point: body) {
        point.Circle();
    }
}

void Snake::Move(Food& nfood) {
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

    if (nfood.x != body.front().getX() || nfood.y != body.front().getY()) {
        body.pop_back();
    } else {
        nfood.RandomNum(this);
    }
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

int Snake::getLength() {
    return body.size();
}

bool Snake::HitSelf() {
    for (auto& point: body) {
        if (&point == &body.front()) continue;
        if (point.getX() == body.front().getX()
            && point.getY() == body.front().getY()
        ) {
            return false;
        }
    }
    return true;
}

Point Snake::Head() {
    return body.front();
}
