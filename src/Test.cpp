#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

#include "List.hpp"

/**
 * Represents a menu selection.
 */
enum Selection {
    ADD = 1,
    SHOW = 2,
    EXIT = 3
};

/**
 * Displays a menu with selectable options to the user and prompts the user to
 * make a @c Selection.
 *
 * After the selected operation completes, the user is displayed the menu and
 * is prompted for a selection again until @c Selection::EXIT is selected.
 *
 * If the selection is not in the range [1,3], the user is prompted to make a
 * new selection.
 *
 * @return          The @c Selection made.
 */
Selection menu();

int main() {
    Selection selection;

    while (selection != Selection::EXIT) {
        selection = menu();

        switch (selection) {
            case Selection::ADD:
                std::string name, contribution;

                std::cout << "Enter the person's name: ";
                std::getline(std::cin, name);

                std::cout << "Enter the person's contribution: ";
                std::getline(std::cin, contribution);

                const int bribe = std::stoi(contribution);

                break;
            case Selection::SHOW:
                // show();

                // Print as a table: position #, name, bribe
                // Find the max width of each column in the data set
                // and set all rows column's to those widths.
                break;
            default:
                break;
        }

        std::cout << '\n';
    }
}

Selection menu() {
    std::cout << "     Menu\n";
    std::cout << "==============\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Show List\n";
    std::cout << "3. Exit\n\n";
    std::cout << "Enter a selection: ";

    std::string selection;

    while (true) {
        std::getline(std::cin, selection);

        try {
            const int i = std::stoi(selection);

            if (i < 1 || i > 4) {
                throw std::invalid_argument("The selection is out of the valid "
                                            "range [1,3].");
            }

            return static_cast<Selection>(i);
        } catch (std::invalid_argument& e) {
            std::cout << "Invalid selection, try again: ";
        }
    }
}
