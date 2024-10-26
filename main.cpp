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

    list<Goat> trip;

    int choice = 0;
    while (choice != 4) {
        choice = main_menu();
        if (choice == 1) {
            //add goat
            add_goat(trip, names, colors);
        }
        else if (choice == 2) {
            //delete goat
            delete_goat(trip);
        }
        else if (choice == 3) {
            //list goats
            display_trip(trip);
        }
        else if (choice == 4) {
            //quit so just put nothing ehre
        }
        else {
            cout << "Invalid choice \n";
        }
    }
    //first run attempt resulted in lots of errors with the auto type specifier have to update my coderuner
    //actually can ust try other thing to run it

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

//add goat to list
void add_goat(list<Goat> &trip, string names[], string colors[]) {
    string name, color;
    int age;
    name = names[rand() % SZ_NAMES];
    color = colors[rand() % SZ_COLORS];
    age = rand() % MAX_AGE;

    Goat addedGoat(name, age, color);
    trip.push_back(addedGoat);
    cout << "\tGoat added, Name: " << name << ", Age: " << age << ", Color: " << color;
}

//display the trip so that we can see all elements in list for deleting (use select with this and then use delete with the select)
void display_trip(list<Goat> trip) {
    int i = 1;
    for (auto it = trip.begin(); it!= trip.end(); ++it) {
        cout << "[" << i << "] " << it->get_name() << " (" << it->get_age() << ", " << it->get_color() << ")\n";
        i++;
    }
}

//select number of goat for now to be used to delete
int select_goat(list<Goat> trip) {
    display_trip(trip);

    int choice;
    cout << "Enter the number of the goat you want to perform this action on: ";
    cin >> choice;

    return choice; 
}

void delete_goat(list<Goat> &trip) {
    auto it = trip.begin();
    int choice = select_goat(trip);
    for (int i = 0; i < choice; i++) {
        it++;
    }
    trip.erase(it);
}

