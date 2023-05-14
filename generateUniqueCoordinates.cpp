#include <vector>
#include "creature.h"

void generateUniqueCoordinates(Coordinate &coordinate, std::vector<Coordinate> &generatedCoordinate, int number){
    for (int i = 0; i < number; i++) {
        while (coordinate.x == generatedCoordinate[i].x && coordinate.y == generatedCoordinate[i].y) {
            coordinate.x = std::rand() % 20;
            coordinate.y = std::rand() % 20;
        }
    }
    generatedCoordinate.push_back(coordinate);
}

