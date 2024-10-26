#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    int choice = 0;
    while (choice != 4) {
        choice = main_menu();
        if (choice == 1) {
            //add goat
        }
        else if (choice == 2) {
            //delete goat
        }
        else if (choice == 3) {
            //list goats
        }
       // else if (choice == 4) {
            //quit so just put nothing ehre
      //  }
    }


    return 0;
}

int main_menu() {
    cout << "\t*** GOAT MANAGER 3001 ***\n";
    cout << "\t[1] Add a goat\n";
    cout << "\t[2] Delete a goat\n";
    cout << "\t[3] List goats\n";
    cout << "\t[4] Quit\n";
    cout << "\tChoice --> ";
    int choice;
    cin >> choice;
    return choice;
}

void add_goat(list<Goat> &trip, string names[], string colors[]) {
    string name, color;
    int age;
    name = names[rand() % SZ_NAMES];
    color = colors[rand() % SZ_COLORS];
    age = rand() % MAX_AGE;

    Goat addedGoat(name, age, color);
    trip.push_back(addedGoat);
    cout << "Goat added, Name: " << name << ", Age: " << age << ", Color: " << color;
}
