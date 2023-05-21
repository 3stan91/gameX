#include <iostream>
#include "creature.h"
#include <string>

void loadGame(Creature *creature, const char* path);

void saveGame(Creature *creature, const char* path);

int pauseScreen(Creature * personages, int size, int positionPlayer) {
    std::cout << "Game is stopped\n";
    std::cout << "Do you want to resume game or exit?\n";
    std::cout << "Choose r or q\n";
    std::cout << "r -> resume\n";
    std::cout << "q -> quit\n-> ";
    char choice;
    std::cin >> choice;

    int statusOperation = 0;
    switch (choice) {
        case 'r':
            try {

                loadGame(personages, "Personage.bin");
                statusOperation = 1;
            }
            catch (const std::string &s) {
                std::cerr << "Error on loading the file Personage.bin\n";
            }
            break;
        case 'q':
            try {
                // for (std::string filePath: path)
             //   for (int i = 0; i < size; ++i){
               //     if (i == positionPlayer)
               //         continue;
              //  saveGame(personages, "Enemies.bin");
           // }
                saveGame(personages, "Personage.bin");
                statusOperation = 2;
            }
            catch (const std::string &s) {
                std::cerr << "Error on saving the file Personage.bin\n";
            }
            break;
        default:
            std::cerr << "You chose a wrong operation\n";
    }
    return statusOperation;
}
