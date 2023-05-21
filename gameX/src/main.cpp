#include <iostream>
#include "coordinate.h"
#include "creature.h"
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "state_enemy.h"

int showGameField(const Creature *, std::string);

bool move(char , Creature &);

void saveGame(Creature *, const char *);

void loadGame(Creature *, const char *);

int pauseScreen(Creature *, int, int);

inline bool isFileExist(const char *fileName) {
    std::ifstream infile(fileName);
    return infile.good();
}

STATE_ENEMY strike(Creature &);

void sort(Creature *personages, int size);

int main() {
    constexpr short countPersonages = 6;
    srand(static_cast<unsigned int>(std::time(nullptr)));
    std::string personageName;

    Creature personages[countPersonages];
    if (!isFileExist("Personage.bin")) {
        for (int i = 0; i < countPersonages - 1; ++i)
            personages[i].create('E', i);
    } else {
        loadGame(personages, "Personage.bin");
    }

    personages[countPersonages - 1].create('P');
    personageName = personages[countPersonages - 1].getName();

    sort(personages, countPersonages);
    int positionPlayer = showGameField(personages, personageName);
    std::cout << std::endl;
    char direction;
    int status;
    do {
        int index = 0;

        //ходят враги
        while (index < countPersonages) {
            if (positionPlayer == index) { //кроме игрока
                index++;
                continue;
            }
            if (personages[index].move(personages[index].generateDirection(), personages[positionPlayer])) {
                if (personages[index].strike(personages[positionPlayer]) == STATE_ENEMY::KILL) {
                    std::cout << "Game is over\n";
                    std::cout << "Your personage is killed\n";
                    std::cout << "You lose\n";
                    exit(EXIT_SUCCESS);
                }
            }
            index++;
        }

        positionPlayer = showGameField(personages, personageName);

        std::cout << "Choose direction's letter\n" << "'w'->up, 's'->down, 'a'->left, 'd'->right\n";
        std::cout << "or 'p'->pause, 'q'->quit\n";
        std::cin >> direction;
        while (direction != 'w' && direction != 's' && direction != 'a'
               && direction != 'd' && direction != 'p' && direction != 'q') {
            std::cout << "Choose functional letter\n" << "'w'->up, 's'->down, 'a'->left, 'd'->right\n";
            std::cout << "or 'p'->pause, 'q'->quit\n";
            std::cin >> direction;
        }
        //system("cls");

        positionPlayer = showGameField(personages, personageName);

        if (direction == 'p') {
            try {
                saveGame(personages, "Personage.bin");
            }
            catch (std::string &s) {
                std::cout << s;
            }
            status = pauseScreen(personages, countPersonages, positionPlayer);
            if (status == 1)
                std::cout << "File loaded successful\n";
            else if (status == 2)
                std::cout << "File saved successful\n";
        } else {
            index = 0;
            if (personages[positionPlayer].move(direction, personages, countPersonages, positionPlayer)) {
                while (index < countPersonages) {
                    if (positionPlayer == index) {
                        index++;
                        continue;
                    }
                    if (personages[positionPlayer].strike(personages[index]) == STATE_ENEMY::KILL) {
                        personages[index].setName("-");
                    }
                    index++;
                }
            }
        }
    }while (direction != 'q' || status == 2);
    std::cout << "Program finished\n";
    return 0;
}
