#include <iostream>
#include <stdexcept>
#include <string>

#include "Airline.hpp"
#include "Queue.hpp"

/**
 * Represents a menu selection.
 */
enum Selection {
    ADD = 1,
    DELETE = 2,
    SHOW = 3,
    EXIT = 4
};

/**
 * Displays a menu with selectable options to the user and prompts the user to
 * make a @c Selection.
 *
 * After the selected operation completes, the user is displayed the menu and
 * is prompted for a selection again until @c Selection::EXIT is selected.
 *
 * If the selection is not in the range [1,4], the user is prompted to make a
 * new selection.
 *
 * @return          The @c Selection made.
 */
Selection menu();

int main() {
    Airline airline = Airline();
    Selection selection;

    while (selection != Selection::EXIT) {
        selection = menu();

        switch (selection) {
            case Selection::ADD:
                airline.add();
                break;
            case Selection::DELETE:
                airline.remove();
                break;
            case Selection::SHOW:
                airline.show();
                break;
            default:
                break;
        }

        std::cout << '\n';
    }
}

Selection menu() {
    std::cout << "Menu\n";
    std::cout << "========\n";
    std::cout << "1. Add Passenger\n";
    std::cout << "2. Delete Passenger\n";
    std::cout << "3. Show Passengers\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter a selection: ";

    std::string selection;

    while (true) {
        std::getline(std::cin, selection);

        try {
            const int i = std::stoi(selection);

            if (i < 1 || i > 4) {
                throw std::invalid_argument("The selection is out of the valid "
                                                    "range [1,4].");
            }

            return static_cast<Selection>(i);
        } catch (std::invalid_argument& e) {
            std::cout << "Invalid selection, try again: ";
        }
    }
}
