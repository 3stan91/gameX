#ifndef CREATURE_H_
#define CREATURE_H_
#include <iostream>
#include "coordinate.h"
#include <cstdlib>
#include <string>
#include<vector>
#include "state_enemy.h"

void generateUniqueCoordinates(Coordinate &, std::vector<Coordinate> &, int);

struct Creature {
private:
    std::string name;
    int health;
    int damage;
    int armor;

public:
    Coordinate coordinate;

    void stateCreature();

    inline void setName(const std::string &name) {
        this->name = name;
    }

    inline void setHealth(int health) {
        this->health = health;
    }

    inline void setArmor(int armor) {
        this->armor = armor;
    }

    inline void setDamage(int damage) {
        this->damage = damage;
    }

    inline const std::string &getName() const {
        return name;
    }

    inline int getHealth() const {
        return health;
    }

    inline int getDamage() const {
        return damage;
    }

    inline int getArmor() const {
        return armor;
    }


    std::string &create(char creature, int number = 0) {
        using namespace std;
        static vector<Coordinate> generatedCoordinate;
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
            //generateUniqueCoordinates(coordinate, generatedCoordinate, number);
        } else {
            name = "Enemy #" + to_string(number + 1);
            health = rand() % 101 + 50;
            damage = rand() % 16 + 15;
            armor = rand() % 51;
            coordinate.x = rand() % 20;
            coordinate.y = rand() % 20;
            if(number>0)
            	generateUniqueCoordinates(coordinate, generatedCoordinate, number);
            else
                generatedCoordinate.push_back(coordinate);
        }
        return name;
    }

    bool move(char direction, Creature &victim) {
        bool haveStrike = false;
        if (direction == 'w') {
            if (this->coordinate.y == 0)
                this->coordinate.y = 0;
            else if (this->coordinate.x == victim.coordinate.x && (this->coordinate.y - 1) == victim.coordinate.y)
                haveStrike = true;
            else
                this->coordinate.y--;
        }

        if (direction == 's') {
            if (this->coordinate.y == 19)
                this->coordinate.y = 19;
            else if (this->coordinate.x == victim.coordinate.x && (this->coordinate.y + 1) == victim.coordinate.y)
                haveStrike = true;
            else
                this->coordinate.y++;
        }

        if (direction == 'a') {
            if (this->coordinate.x-1 == 0)
                this->coordinate.x = 0;
            else if ((this->coordinate.x - 1) == victim.coordinate.x && this->coordinate.y == victim.coordinate.y)
                haveStrike = true;
            else
                this->coordinate.x--;
        }

        if (direction == 'd') {
            if (this->coordinate.x == 19)
                this->coordinate.x = 19;
            else if ((this->coordinate.x + 1) == victim.coordinate.x && this->coordinate.y == victim.coordinate.y)
                haveStrike = true;
            else
                this->coordinate.x++;
        }
        std::cout<<"++++++ move of enemy +++++++\n";
        std::cout<<this->getName()<<std::endl;
        std::cout<<"x = "<< this->coordinate.x<<std::endl;
        std::cout<<"y = "<< this->coordinate.y<<std::endl<<std::endl;

        return haveStrike;
    }

    bool move(char direction, Creature *victim, int n, int positionPlayer) {

        bool haveStrike = false;
        if (direction == 'w') {
            for (int i = 0; i < n; i++) {
                if (i == positionPlayer)
                    continue;
                if (this->coordinate.x == victim[i].coordinate.x &&
                    (this->coordinate.y - 1) == victim[i].coordinate.y)
                    haveStrike = true;
            }

            if (this->coordinate.y == 0)
                this->coordinate.y = 0;
            else
                this->coordinate.y--;
        }

        if (direction == 's') {
            for (int i = 0; i < n; i++) {
                if (i == positionPlayer)
                    continue;
                if (this->coordinate.x == victim[i].coordinate.x &&
                    (this->coordinate.y + 1) == victim[i].coordinate.y)
                    haveStrike = true;
            }

            if (this->coordinate.y == 19)
                this->coordinate.y = 19;
            else
                this->coordinate.y++;
        }

        if (direction == 'a') {
            for (int i = 0; i < n; i++) {
                if (i == positionPlayer)
                    continue;
                if ((this->coordinate.x - 1) == victim[i].coordinate.x
                    && this->coordinate.y == victim[i].coordinate.y)
                    haveStrike = true;
            }

            if (this->coordinate.x == 0)
                this->coordinate.x = 0;
            else
                this->coordinate.x--;
        }

        if (direction == 'd') {
            for (int i = 0; i < n; i++) {
                if (i == positionPlayer)
                    continue;
                if ((this->coordinate.x + 1) == victim[i].coordinate.x &&
                    this->coordinate.y == victim[i].coordinate.y)
                    haveStrike = true;
            }

            if (this->coordinate.x == 19)
                this->coordinate.x = 19;
            else
                this->coordinate.x++;
        }
        return haveStrike;
    }

    char generateDirection() {
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
        return direction;
    }

    STATE_ENEMY strike(Creature &victim) {
        STATE_ENEMY state;

        if ((victim.getArmor() - this->getDamage()) > 0) {
            victim.setArmor(victim.getArmor() - this->getDamage());
            state = STATE_ENEMY::DAMAGE;

        } else if ((victim.getDamage() - this->getDamage()) > 0) {
            victim.setArmor(0);
            victim.setDamage(victim.getDamage() - this->getDamage());
            state = STATE_ENEMY::DAMAGE;

        } else if ((victim.getHealth() - this->getDamage()) > 0) {
            victim.setDamage(0);
            victim.setHealth(victim.getHealth() - this->getDamage());
            state = STATE_ENEMY::DAMAGE;

        } else {
            victim.setHealth(0);
            state = STATE_ENEMY::KILL;
        }
      //  stateCreature();
        return state;
    }

};

inline void Creature::stateCreature() {
    std::cout << "Armor " << getArmor() << std::endl;
    std::cout << "Damage " << getDamage() << std::endl;
    std::cout << "Health " << getHealth() << std::endl;
}

#endif
