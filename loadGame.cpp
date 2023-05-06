//#include <iostream>
#include "creature.h"
#include <fstream>
#include <string>

void loadGame(Creature creature, std::string path) {
    std::ifstream fin;
    fin.open(path, std::ios::binary);

    if (fin.good()) {
        while (!fin.eof()) {
            //fin>>;
        }
    } else {
        throw "Error when loading a file";
    }

    fin.close();
}

