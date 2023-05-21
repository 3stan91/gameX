#include "creature.h"
#include <fstream>
//#include <string>

void loadGame(Creature *creature, const char *path) {
    std::ifstream fin;
    fin.open(path, std::ios::binary);
    Creature *cr;
    if (fin.is_open()) {

        while (!fin.eof()) {
            fin.read((char*)&cr, sizeof(cr));
            creature->setName(cr->getName());
            creature->setHealth(cr->getHealth());
            creature->setDamage(cr->getDamage());
            creature->setArmor(cr->getArmor());
            creature->coordinate.x = cr->coordinate.x;
            creature->coordinate.y = cr->coordinate.y;
            fin.close();
        }
    } else {
        throw "Error when loading a file";
    }
}

