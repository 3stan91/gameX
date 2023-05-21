#include "creature.h"

void sort(Creature *personages, int size) {
    for (int i = 0; i < size-1; ++i)
        for (int j = i + 1; j < size; ++j) {

            if (personages[i].coordinate.y > personages[j].coordinate.y) {
                std::swap(personages[i], personages[j]);
            }

            if ((personages[i].coordinate.y == personages[j].coordinate.y) &&
                (personages[i].coordinate.x > personages[j].coordinate.x)) {
                std::swap(personages[i], personages[j]);
            }
        }
}
