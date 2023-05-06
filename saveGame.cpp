//#include <iostream>
#include "creature.h"
#include <fstream>
#include <string>

void saveGame(Creature creature, std::string path) {

    if (creature.getName().find("Enemy") != std::string::npos) {
        std::ofstream fout(path, std::ios::binary);
        if (fout.good()) {
            fout.write(creature.getName().c_str(), sizeof(creature.getName()));                             //name
            fout.write(reinterpret_cast<const char *>(creature.getHealth()), sizeof(creature.getHealth())); //health
            fout.write(reinterpret_cast<const char *>(creature.getDamage()),
                       sizeof(creature.getDamage()));  //damage
            fout.write(reinterpret_cast<const char *>(creature.getArmor()), sizeof(creature.getArmor()));
            fout.write(reinterpret_cast<const char *>(creature.coordinate.x), sizeof(creature.coordinate.x));
            fout.write(reinterpret_cast<const char *>(creature.coordinate.y), sizeof(creature.coordinate.y));
        } else
            throw "File \"Enemies.bin\" is not access\n";
    } else {
        std::ofstream fout(path, std::ios::binary);
        if (fout.good()) {
            fout << creature.getName();
            fout << creature.getHealth();
            fout << creature.getDamage();
            fout << creature.getArmor();
            fout << creature.coordinate.x;
            fout << creature.coordinate.y;
            fout.close();
        } else {
            throw "File \"Personage.bin\" is not access\n";
        }
    }
}