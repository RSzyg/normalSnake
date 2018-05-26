#include "map.h"

void Map::PrintMap() {
    for (auto& point: map0) {
        point.Clear();
        point.Block();
    }
}