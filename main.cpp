/*
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;

struct SalaryReport {
    std::string name;
    std::string lastName;
    std::string date;
    int sum = 0;
};

void showList(SalaryReport &sr) {

    std::ifstream fin("salary_report.txt");
    if (!fin.is_open()) {
        std::cerr << "Error. File not found\n";
    }
    while (!fin.eof()) {
        fin >> sr.name;
        cout << "Name " << sr.name << std::endl;
        fin >> sr.lastName;
        cout << "Last name " << sr.lastName << std::endl;
        fin >> sr.date;
        cout << "Date " << sr.date << std::endl;
        fin >> sr.sum;
        cout << "Sum " << sr.sum << std::endl;
    }
    fin.close();
}

void addToList(SalaryReport &sr) {
    std::ofstream fout("salary_report.txt", std::ios::app);
    if (!fout.is_open()) {
        std::cerr << "Error. File not found\n";
    }

    fout << sr.name << std::endl;
    fout << sr.lastName << std::endl;
    fout << sr.date << std::endl;
    fout << sr.sum << std::endl;
    fout.close();
}

void checkUserInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    } else
        cin.ignore(INT_MAX, '\n');
}

void enterData(SalaryReport &sr) {
    cout << "Enter name\n";
    cin >> sr.name;
   // checkUserInput();
    cout << "Enter last name\n";
    cin >> sr.lastName;
    //checkUserInput();
    cout << "Enter date\n";
    cin >> sr.date;
   // checkUserInput();
    cout << "Enter sum\n";
    cin >> sr.sum;
    checkUserInput();
}

int main() {
    std::cout << "----------Enter command----------" << std::endl;
    std::string command;
    SalaryReport sr;
    while (std::getline(cin, command)) {

        if (command == "list") {
            showList(sr);
        } else if (command == "add") {
            enterData(sr);
            addToList(sr);
        } else {
            std::cerr << "Error. INcorrect command\n";
            std::cerr << "Please try to repeat again\n";
            std::cout << "Enter command" << std::endl;
        }
        std::cout << "\n----------------Enter command-------------" << std::endl;
    }
    return 0;
}


#include <iostream>
#include "structure.h"

struct Floor {
    Room rooms[4];
    int heightCeiling;
};

struct Build {
    std::string nameBuild;
    Floor floor[3];
    int area;
    bool chimney;
};

struct LandPlot {
    int id;
    Build build;
};

bool hasChimney(char chimney) {
    while (chimney != 'y' && chimney != 'n') {
        std::cerr << "Error. You entered wrong count of the rooms.\nTry to enter again : ";
        std::cin >> chimney;
    }
    if (chimney == 'y')
        return true;
    else
        return false;
}

int enterCountRooms() {
    std::cout << "Enter the count of the rooms: ";
    int countRoom;
    std::cin >> countRoom;
    while (countRoom <= 0 || countRoom > 5) {
        std::cerr << "Error. You entered wrong count of the rooms\nTry to enter again : ";
        std::cin >> countRoom;
    }
    return countRoom;
}

int main() {
    using namespace std;
    cout << "Enter count of the land plot: ";
    int countLandPlot;
    cin >> countLandPlot;
    for (int cl = 0; cl < countLandPlot; ++cl) {
        LandPlot land;
        cout << "Enter the id number of land plot #" << cl + 1 << ": ";
        cin >> land.id;
        cout << "Enter count of build on the land plot #" << cl + 1 << ": ";
        int countBuild;
        cin >> countBuild;

        for (int cb = 0; cb < countBuild; ++cb) {
            cout << "Enter the name of build on the land plot #" << cl + 1 << ": ";
            cin >> land.build.nameBuild;
            cout << "Enter the area of build on the land plot #" << cl + 1 << ": ";
            cin >> land.build.area;
            cout << "Is there a chimney in the build?  y/n :";
            char chimney;
            cin >> chimney;
            land.build.chimney = hasChimney(chimney);

            cout << "Enter the count of the floors: ";
            int countFloor;
            cin >> countFloor;
            while (countFloor < 1 || countFloor > 3) {
                cerr << "Error. You entered wrong count of the floors\nTry to enter again\n";
                cin >> countFloor;
            }
            for (int cf = 1; cf <= countFloor; cf++) {
                cout << "Enter height of ceiling of "<< cf << "floor\n";
                cin >> land.build.floor[cf].heightCeiling;

                int countRoom = enterCountRooms();

                for (int cr = 0; cr < countRoom; cr++) {
                    if (cr == bed_room) {
                        cout << "Enter the area of the bed room :";
                        cin >> land.build.floor[cf].rooms[cr].area;
                    } else if (cr == living_room) {
                        cout << "Enter the area of the living room :";
                        cin >> land.build.floor[cf].rooms[cr].area;
                    } else if (cr == kitchen) {
                        cout << "Enter the area of the kitchen :";
                        cin >> land.build.floor[cf].rooms[cr].area;
                    } else if (cr == bath_room) {
                        cout << "Enter the area of the bath room :";
                        cin >> land.build.floor[cf].rooms[cr].area;
                    } else if (cr == children_room) {
                        cout << "Enter the area of the children room :";
                        cin >> land.build.floor[cf].rooms[cr].area;
                    }
                }
            }
        }
    }
    return 0;
}
 */

#include <iostream>
#include "coordinate.h"
#include "creature.h"
#include <vector>
#include <unistd.h>

void welcome();

void showGameField(std::vector<char> &dataCreature, std::vector<Coordinate> &dataCoordinate);

void pauseScreen(Creature creature);

int main() {
    //welcome();
    //sleep(1);
   // system("cls");

    Creature enemy[5];
    for (int i = 0; i < 5; ++i) {
        enemy[i].create('E', i);
    }

    Creature personage;
    personage.create('P');

    std::vector<char> dataCreature;
    std::vector<Coordinate> dataCoordinate;

    dataCreature.push_back('P');
    dataCoordinate.push_back(personage.coordinate);
    for (int i = 0; i < 5; i++) {
        dataCreature.push_back('E');
        dataCoordinate.push_back(enemy[i].coordinate);
    }

    showGameField(dataCreature, dataCoordinate);
    char key;
    int index = 0;
    do {
        while (index < 5) {
            enemy[index].moveEnemy(dataCreature, dataCoordinate[index + 1]);
            showGameField(dataCreature, dataCoordinate);
            index++;
        }
        std::cin >> key;
        system("cls");
        personage.move(dataCreature, dataCoordinate[0], key);
        showGameField(dataCreature, dataCoordinate);
        if (key == 'p')
            pauseScreen(personage);
    } while (key != 'q');

    return 0;
}