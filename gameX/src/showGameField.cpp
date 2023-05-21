#include <iostream>
#include "coordinate.h"
#include <vector>
#include "creature.h"


int showGameField(const Creature *personages, std::string playerName) {
    constexpr int sizeField = 20;
    int index = 0;
    int positionPlayer;
    for (int row = 0; row < sizeField; row++) {
        if (row < 10)
            std::cout << row << "   ";
        else
            std::cout << row << "  ";

        for (int col = 0; col < sizeField; ++col) {
            if (personages[index].coordinate.x == col && personages[index].coordinate.y == row) {
                if (personages[index].getName().compare(playerName) == 0) {
                    std::cout << 'P';
                    positionPlayer = index;
                    index++;
                }
                else if (personages[index].getName().find("Enemy") != std::string::npos){
                    std::cout << 'E';
                    index++;
                }
            } else
                std::cout << '-';
        }
        std::cout << std::endl;
    }
    return positionPlayer;
}
