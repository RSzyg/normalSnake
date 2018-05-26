#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <ncurses.h>
#include "map.h"

class Controller {
    public:
        Controller(): speed(300), score(0) {}
        void Start();
        void CreateScene(Map*);
        void Main();
        void Select();
        void Game(Map*);
        void Menu(WINDOW *menu);
    private:
        int speed;
        int score;
};

#endif // CONTROLLER_H