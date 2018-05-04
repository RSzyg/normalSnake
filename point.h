#ifndef POINT_H
#define POINT_H

class Point {
    public:
        Point(const int x, const int y): _x(x), _y(y) {}
        void Block();
        void Circle();
        void Clear();
        int x();
        int y();
    private:
        int _x, _y;
};

#endif