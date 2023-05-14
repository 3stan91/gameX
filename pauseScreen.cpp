#include <iostream>
#include "creature.h"
#include <string>

void loadGame(Creature &creature, const char* path);

void saveGame(Creature &creature, std::string path);

int pauseScreen(Creature &personage, Creature enemies[], int n) {
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
               // for (std::string filePath: path)
                    for (int i = 0; i < n; ++i)
                        loadGame(enemies[i], "Enemies.bin");
                loadGame(personage, "Personage.bin");
                statusOperation = 1;
            }
            catch (const std::string &s) {
                std::cerr << "Exception opening/reading file";
            }
            break;
        case 'q':
            try {
               // for (std::string filePath: path)
                    for (int i = 0; i < n; ++i)
                        saveGame(enemies[i], "Enemies.bin");
                saveGame(personage, "Personage.bin");
                statusOperation = 2;
            }
            catch (const std::string &s) {
                std::cerr << "Error";
            }
            break;
        default:
            std::cerr << "You chose a wrong operation\n";
    }
    return statusOperation;
}
