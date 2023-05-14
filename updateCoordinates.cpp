#include <vector>
#include "creature.h"

void updateCoordinates(std::vector<Coordinate> &coordinate, Creature *creature, int position) {
    coordinate[position] = creature->coordinate;
}