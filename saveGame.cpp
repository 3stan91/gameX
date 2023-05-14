#include <iostream>
#include "creature.h"
#include <fstream>
#include <string>

void saveGame(Creature creature, std::string path) {

    if (creature.getName().find("Enemy") != std::string::npos) {
        std::ofstream fout(path, std::ios::binary | std::ios::app);
        if (fout.good()) {
            fout.write(creature.getName().c_str(), sizeof(creature.getName()))<<std::endl;
            int armor = creature.getArmor();
            int damage = creature.getDamage();
            int health = creature.getHealth();
            fout.write((char *) &armor, sizeof(armor))<<std::endl;
            fout.write((char *) &damage, sizeof(damage))<<std::endl;
            fout.write((char *) &health, sizeof(health))<<std::endl;
            fout.write((char *) &creature.coordinate.x, sizeof(creature.coordinate.x))<<std::endl;
            fout.write((char *) &creature.coordinate.y, sizeof(creature.coordinate.y))<<std::endl;
        } else
            throw "File \"Enemies.bin\" is not access\n";
    } else {
        std::ofstream fout(path, std::ios::binary);
        if (fout.good()) {
            fout << creature.getName()<<std::endl;
            int armor = creature.getArmor();
            int damage = creature.getDamage();
            int health = creature.getHealth();
            fout.write((char *) &armor, sizeof(armor))<<std::endl;
            fout.write((char *) &damage, sizeof(damage))<<std::endl;
            fout.write((char *) &health, sizeof(health))<<std::endl;
            fout << creature.coordinate.x<<std::endl;
            fout << creature.coordinate.y<<std::endl;
            fout.close();
        } else {
            throw "File \"Personage.bin\" is not access\n";
        }
    }
 }