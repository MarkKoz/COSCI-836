#include <iostream>
#include <string>

#include "Queue.hpp"

using namespace std;

enum choice {
    BOOKED,
    WAITING
};

const int LINES = 2;

int showMenu();

void addPassenger(CQueue*);

void deletePassenger(CQueue*);

void showPassengers(CQueue*);

int main() {
    CQueue qPassengers[LINES];
    int x;

    do {
        x = showMenu();

        switch (x) {
            case 1:
                addPassenger(qPassengers);
                break;
            case 2:
                deletePassenger(qPassengers);
                break;
            case 3:
                showPassengers(qPassengers);
                break;
        }
    } while (x != 4);

    return 0;
}

int showMenu() {
    int select;

    cout << "Menu\n";
    cout << "========\n";
    cout << "1. Add Passenger\n";
    cout << "2. Delete Passenger\n";
    cout << "3. Show Passengers\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin >> select;

    return select;
}

// To do: implement addPassenger, deletePassenger and showPassengers
