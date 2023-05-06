#ifndef GAME_CREATURE_H
#define GAME_CREATURE_H

#include <iostream>
#include "coordinate.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include<vector>

void showGameField(std::vector<char> &dataCreature, std::vector<Coordinate> &dataCoordinate);

//void showGameField(Coordinate &dataCoordinate, char enemy = 'E');

struct Creature {
private:
    std::string name;
    int health;
    int damage;
    int armor;

public:
    Coordinate coordinate;

    void setName(const std::string &name) {
        this->name = name;
    }

    void setHealth(int health) {
        this->health = health;
    }

    void setArmor(int armor) {
        this->armor = armor;
    }

    void setDamage(int damage) {
        this->damage = damage;
    }

    const std::string &getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getDamage() const {
        return damage;
    }

    int getArmor() const {
        return armor;
    }

    void create(char creature, int number = 0) {
        using std::cin;
        using std::cout;
        srand(std::time(0));
        if (creature == 'P') {
            // cout << "Enter a name of the game's personage\n";
            //std::getline(cin, name);
            name = "John";
            // cout << "Enter health of the personage\n";
            // cin >> health;
            health = 100;
            // cout << "Enter damage of the personage\n";
            // cin >> damage;
            damage = 20;
            // cout << "Enter armor\n";
            // cin >> armor;
            armor = 30;
            coordinate.x = std::rand() % 20;
            coordinate.y = std::rand() % 20;
        } else {
            name = "Enemy #" + std::to_string(number + 1);
            health = (std::rand() % 101) + 50;
            damage = (std::rand() % 16) + 15;
            armor = std::rand() % 51;
            coordinate.x = std::rand() % 20;
            coordinate.y = std::rand() % 20;
        }
    }

    void move(std::vector<char> &dataCreature, Coordinate &dataCoordinate, char direction) {
        if (direction == 'w') {
            if (dataCoordinate.y < 0)
                dataCoordinate.y = 0;
            dataCoordinate.y--;
        }
        if (direction == 's') {
            if (dataCoordinate.y > 19)
                dataCoordinate.y = 19;
            dataCoordinate.y++;
        }
        if (direction == 'a') {
            if (dataCoordinate.x < 0)
                dataCoordinate.x = 0;
            dataCoordinate.x--;
        }
        if (direction == 'd') {
            if (dataCoordinate.x > 19)
                dataCoordinate.x = 19;
            dataCoordinate.x++;
        }
    }

    void moveEnemy(std::vector<char> &dataCreature, Coordinate &dataCoordinate) {
        srand(static_cast<unsigned int>(time(0)));
        int direction = rand() % 4;
        if (direction == 0) {
            dataCoordinate.y--;
        }
        if (direction == 1) {
            coordinate.y++;
        }
        if (direction == 2) {
            coordinate.x--;
        }
        if (direction == 3) {
            coordinate.x++;
        }
    }
};

#endif