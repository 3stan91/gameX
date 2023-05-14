#include "creature.h"

bool doPlayerDamage(Creature *hunter, Creature *victim) {

    if (hunter->coordinate.x == victim->coordinate.x && hunter->coordinate.y == victim->coordinate.y) {

        if ((victim->getArmor() - hunter->getDamage()) > 0) {
            victim->setArmor(victim->getArmor() - hunter->getDamage());
        } else if ((victim->getDamage() - hunter->getDamage()) > 0) {
            victim->setArmor(0);
            victim->setDamage(victim->getDamage() - hunter->getDamage());
        } else if ((victim->getHealth() - hunter->getDamage()) > 0) {
            victim->setDamage(0);
            victim->setHealth(victim->getHealth() - hunter->getDamage());
        }
    }

    if (victim->getHealth() == 0 && victim->getDamage() == 0 && victim->getArmor() == 0)
        return true;
    else
        return false;
}