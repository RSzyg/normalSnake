#ifndef MAP_H
#define MAP_H

#include <vector>
#include "point.h"

class Map {
    public:
        Map() {
            for (int i = 0; i < 24; i++) {
                map0.emplace_back(0, i * 2);
            }
            for (int i = 1; i < 24; i++) {
                map0.emplace_back(i, 0);
            }
            for (int i = 1; i < 24; i++) {
                map0.emplace_back(23, i * 2);
            }
            for (int i = 1; i < 23; i++) {
                map0.emplace_back(i, 46);
            }
        }
        void PrintMap();
    private:
        std::vector<Point> map0;
};

#endif