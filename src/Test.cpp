#include <iostream>
#include <stdexcept>
#include <string>

#include "Queue.hpp"

/**
 * Represents an airline within two @c Queues - one for booked @c Passengers and
 * the other a waiting list of @c Passengers. Each has a total capacity of 3.
 */
struct Airline {
    Queue<Passenger> booked = Queue<Passenger>(3);
    Queue<Passenger> waiting = Queue<Passenger>(3);

    /**
     * @brief Adds a @c Passenger to a @c Queue.
     *
     * The user is prompted to enter the @c Passenger's name. An attempt is made
     * to add the @c Passenger to either @c booked (takes precedence) or @c
     * waiting.
     *
     * A message is displayed indicating the success or failure of the addition.
     * A failure occurs if both queues are full.
     */
    void add() {
        std::cout << "Enter the name: ";

        std::string name;
        std::getline(std::cin, name);

        if (!booked.full()) {
            booked.push(Passenger(name));
            std::cout << "Booking " << name << " for the flight.\n";
        } else if (!waiting.full()) {
            waiting.push(Passenger(name));
            std::cout << "Sorry, the plane is fully booked. Adding " << name
                      << " to the waiting list.\n";
        } else {
            std::cout << "Sorry, the plane and waiting list are both fully "
                         "booked; try again later.\n";
        }
    }

    /**
     * @brief Removes the front-most @c Passenger from @c booked.
     *
     * If there are @c Passengers in @c waiting, the front-most of those @c
     * Passengers is moved to the back of @c booked.
     *
     * A message is displayed indicating the success or failure of the removal.
     * A failure occurs if no @c Passenger is left for deletion.
     */
    void remove() {
        if (!booked.empty()) {
            std::cout << "Removing " << booked.getFront()
                      << " from the booked passengers queue.\n";
            booked.pop();

            if (!waiting.empty()) {
                Passenger& front = waiting.getFront();

                std::cout << "Booking " << front
                          << " from the waiting list.\n";
                booked.push(std::move(front));
                waiting.pop();
            }
        } else {
            std::cout << "There are no passengers to delete.\n";
        }
    }

    /**
     * @brief Lists all @c Passengers.
     *
     * Displays a list of all @c Passengers in each @c Queue. If there are no
     * @c Passengers to list, a message indicating this is instead displayed.
     */
    void show() {
        if (booked.empty()) {
            std::cout << "Queue is empty.\n";
        } else {
            std::cout << "\nBooked Passengers\n=================\n";

            for (const Passenger& p : booked) {
                std::cout << p << '\n';
            }

            if (!waiting.empty()) {
                std::cout << "\nWaiting List\n=================\n";

                for (const Passenger& p : waiting) {
                    std::cout << p << '\n';
                }
            }
        }
    }
};

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

int main() {
    Airline airline = Airline();
    Selection selection;

    do {
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
    } while (selection != Selection::EXIT);
}
