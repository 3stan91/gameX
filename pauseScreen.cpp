#include <iostream>
#include "creature.h"
#include <string>

void loadGame(Creature creature, std::string path);
void saveGame(Creature creature, std::string path);

void pauseScreen(Creature creature) {
    std::cout << "Game is stopped\n";
    std::cout << "Do you want to resume game or exit?\n";
    std::cout << "Choose 1 or 2\n";
    std::cout << "1. Resume\n";
    std::cout << "2. Exit\n-> ";
    short int choice;
    std::cin >> choice;
    const std::string path[]{"Enemies.bin", "Personage.bin"};
    switch (choice) {
        case 1:
            try {
                for (std::string filePath: path)
                    loadGame(creature, filePath);
            }
            catch (const std::string &s) {
                std::cerr << "Exception opening/reading file";
            }
            break;
        case 2:
            try {
                for (std::string filePath: path)
                    saveGame(creature, filePath);
            }
            catch (const std::string &s) {
                std::cerr << "Error";
            }
            break;
        default:
            std::cerr << "You chose a wrong operation\n";
    }
}
