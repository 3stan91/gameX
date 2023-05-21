#include <iostream>

void welcome() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; ++j) {
            if (i == 5 && j == 6) {
                std::cout << "WELCOME";
                j = 12;
            }
            else if (i == 6 && j == 8) {
                std::cout << "TO";
                j = 9;
            }
            else if (i == 7 && j == 7) {
                std::cout << "BATLE";
                j = 11;
            }
            else if (i == 8 && j == 7) {
                std::cout << "GAME";
                j = 10;
            }
            else
                std::cout << "-";
        }
        std::cout << std::endl;
    }
}
