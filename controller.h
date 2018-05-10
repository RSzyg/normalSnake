#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
    public:
        Controller(): speed(300), score(0) {}
        void Start();
        void CreateScene();
        void Main();
        void Select();
        void Game();
    private:
        int speed;
        int score;
};

#endif // CONTROLLER_H