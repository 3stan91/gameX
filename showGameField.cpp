#include <iostream>
#include "coordinate.h"
#include <vector>

void sort(std::vector<Coordinate> &dataCoordinate) {
    for (int i = 0; i < dataCoordinate.size() - 1; ++i)
        for (int j = i + 1; j < dataCoordinate.size(); ++j) {

            if (dataCoordinate[i].y > dataCoordinate[j].y)
                std::swap(dataCoordinate[i], dataCoordinate[j]);

            if ((dataCoordinate[i].y == dataCoordinate[j].y) && (dataCoordinate[i].x > dataCoordinate[j].x))
                std::swap(dataCoordinate[i], dataCoordinate[j]);
        }
}

void showGameField(const std::vector<char> &creatures, std::vector<Coordinate> &coordinates) {
    //system("cls");
    sort(coordinates);
    int index = 0;
    std::cout<<0;
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 20; ++col) {
            if (coordinates[index].x == col && coordinates[index].y == row) {
                std::cout << creatures[index];
                index++;
            } else
                std::cout << "-";
        }
        std::cout << std::endl;
        std::cout << row+1;
    }
}