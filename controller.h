#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "map.h"

class Controller {
    public:
        Controller(): speed(300), score(0) {}
        void Start();
        void CreateScene(Map*);
        void Main();
        void Select();
        int Game(Map*);
        int Menu();
    private:
        int speed;
        int score;
};

#endif // CONTROLLER_H