//#include <iostream>
#include "creature.h"
#include <fstream>
#include <string>

void loadGame(Creature creature, std::string path) {
  /*  std::ifstream fin;
    fin.open(path, std::ios::binary | std::ios::in);

    if (fin.good()) {
        while (!fin.eof()) {
            char *str;
            fin.read(str, sizeof(str));
            creature.setName(str);
            int health;
            fin.read((char *) &health, sizeof(health));
            creature.setHealth(health);
            int damage;
            fin.read((char *) &damage, sizeof(damage));
            creature.setDamage(damage);
            int armor;
            fin.read((char *) &armor, sizeof(armor));
            creature.setArmor(armor);
            int x, y;
            fin.read((char *) &x, sizeof(x));
            creature.coordinate.x = x;
            fin.read((char *) &y, sizeof(y));
            creature.coordinate.y = y;
            fin.close();
        }
    } else {
        throw "Error when loading a file";
    }

    fin.close();
    */
    return;
}

