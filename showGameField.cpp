#include <iostream>
#include "coordinate.h"
#include <vector>

void sort(std::vector<Coordinate> &dataCoordinate) {
    for (int i = 1; i < dataCoordinate.size() - 1; ++i)
        for (int j = i + 1; j < dataCoordinate.size(); ++j) {
            if (dataCoordinate[i].y > dataCoordinate[j].y) {
                std::swap(dataCoordinate[i].y, dataCoordinate[j].y);
                std::swap(dataCoordinate[i].x, dataCoordinate[j].x);
            }
        }
}

void showGameField(std::vector<char> &dataCreature, std::vector<Coordinate> &dataCoordinate) {
    //system("cls");
    sort(dataCoordinate);
    int index = 0;
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 20; ++col) { ;
            if (dataCoordinate[index].x == col && dataCoordinate[index].y == row) {
                std::cout << dataCreature[index];
                index++;
            } else
                std::cout << "-";
        }
        std::cout << std::endl;
    }
}

/*
[[maybe_unused]]
void showGameField(Coordinate &dataCoordinate, char creature = 'E') {
    system("cls");
    //int c = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; ++j) { ;
            if (dataCoordinate.x == j && dataCoordinate.y == i) {
                std::cout << creature;
                //c++;
            } else
                std::cout << "-";
        }
        std::cout << std::endl;
    }
}
*/