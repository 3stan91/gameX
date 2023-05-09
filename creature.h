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
        using namespace std;
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
            coordinate.x = rand() % 20;
            coordinate.y = rand() % 20;
        } else {
            name = "Enemy #" + std::to_string(number + 1);
            health = rand() % 101 + 50;
            damage = rand() % 16 + 15;
            armor = rand() % 51;
            coordinate.x = rand() % 20;
            coordinate.y = rand() % 20;
        }
        return;
    }

    void move(char direction) {
        if (direction == 'w') {
            if (this->coordinate.y < 0)
                this->coordinate.y = 0;
            this->coordinate.y--;
        }
        if (direction == 's') {
            if (this->coordinate.y > 19)
                this->coordinate.y = 19;
            this->coordinate.y++;
        }
        if (direction == 'a') {
            if (this->coordinate.x < 0)
                this->coordinate.x = 0;
            this->coordinate.x--;
        }
        if (direction == 'd') {
            if (this->coordinate.x > 19)
                this->coordinate.x = 19;
            this->coordinate.x++;
        }
        return;
    }

    void generateDirection() {
        int codeDirection = rand() % 4;
        char direction;
        switch (codeDirection) {
            case 0:
                direction = 'w';
                break;
            case 1:
                direction = 's';
                break;
            case 2:
                direction = 'a';
                break;
            case 3:
                direction = 'd';
                break;
        }
        move(direction);
        return;
    }

};

#endif