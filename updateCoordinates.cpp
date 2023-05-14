#include <vector>
#include "creature.h"

void updateCoordinates(std::vector<Coordinate> &coordinate, int position, Creature *creature) {
    coordinate[position] = creature->coordinate;
}