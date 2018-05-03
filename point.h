#ifndef POINT_H
#define POINT_H

class Point {
    public:
        Point(const int inx, const int iny): x(inx), y(iny) {}
        void Block();
        void Circle();
    private:
        int x, y;
};

#endif