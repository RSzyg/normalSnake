#ifndef POINT_H
#define POINT_H

class Point {
    public:
        Point(const int x, const int y): x(x), y(y) {}
        void Block();
        void Circle();
        void Food();
        void Clear();
        int getX();
        int getY();
        int setX(int nx);
        int setY(int ny);
    private:
        int x, y;
};

#endif