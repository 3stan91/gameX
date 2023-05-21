#include <iostream>
#include "creature.h"
#include <fstream>
#include <string>

void saveGame(Creature *creature, const char *path) {

        std::ofstream fout(path, std::ios::binary);
        if (fout.is_open()) {
            fout.write((char *) &creature, sizeof(creature))<<std::endl;
            fout.close();
        } else
            throw "File \"Personage.bin\" is not access\n";
    }
