#include <iostream>
#include "creature.h"
#include <fstream>
#include <string>

void saveGame(Creature creature, std::string path) {

    if (creature.getName().find("Enemy") != std::string::npos) {
        std::ofstream fout(path, std::ios::binary | std::ios::app);
        if (fout.good()) {
            fout.write(creature.getName().c_str(), sizeof(creature.getName()))<<std::endl;                             //name
            fout.write(reinterpret_cast<const char *>(creature.getHealth()), sizeof(creature.getHealth()))<<std::endl;  //health
            fout.write(reinterpret_cast<const char *>(creature.getDamage()),
                       sizeof(creature.getDamage()))<<std::endl;   //damage
            fout.write(reinterpret_cast<const char *>(creature.getArmor()), sizeof(creature.getArmor()))<<std::endl;
            fout.write(reinterpret_cast<const char *>(creature.coordinate.x), sizeof(creature.coordinate.x))<<std::endl;
            fout.write(reinterpret_cast<const char *>(creature.coordinate.y), sizeof(creature.coordinate.y))<<std::endl;
        } else
            throw "File \"Enemies.bin\" is not access\n";
    } else {
        std::ofstream fout(path, std::ios::binary);
        if (fout.good()) {
            fout << creature.getName()<<std::endl;
            fout << creature.getHealth()<<std::endl;
            fout << creature.getDamage()<<std::endl;
            fout << creature.getArmor()<<std::endl;
            fout << creature.coordinate.x<<std::endl;
            fout << creature.coordinate.y<<std::endl;
            fout.close();
        } else {
            throw "File \"Personage.bin\" is not access\n";
        }
    }
}