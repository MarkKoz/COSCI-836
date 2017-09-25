#include <iostream>
#include <stdexcept>
#include <string>

#include "Queue.hpp"

/**
 * A container for the booked and waiting @c Queues of @c Passengers.
 */
struct PassengerQueues {
    Queue<Passenger> booked = Queue<Passenger>(3);
    Queue<Passenger> waiting = Queue<Passenger>(3);
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
Selection menu();

/**
 * @brief Adds a @c Passenger to a @c Queue.
 *
 * The user is prompted to enter the @c Passenger's name. An attempt is made to
 * add the @c Passenger to either the booked @c Queue (takes precedence) or the
 * waiting list @c Queue - each has a total capacity of 3.
 *
 * A message is displayed indicating the success or failure of the addition.
 * A failure occurs if both queues are full.
 *
 * @param   queues  @c Queues for booked and waiting list.
 */
void addPassenger(PassengerQueues& queues);

/**
 * @brief Removes the front-most @c Passenger from the booked @c Queue.
 *
 * If there are @c Passengers in the waiting list @c Queue, the front-most of
 * those @c Passengers is moved to the back of the booked @c Queue.
 *
 * A message is displayed indicating the success or failure of the removal.
 * A failure occurs if no @c Passenger is left for deletion.
 *
 * @param   queues  @c Queues for booked and waiting list.
 */
void deletePassenger(PassengerQueues& queues);

/**
 * @brief Lists all passengers.
 *
 * Displays a list of all passengers in each @c Queue (booked and waiting list).
 *
 * @param   queues  @c Queues for booked and waiting list.
 */
void showPassengers(PassengerQueues& queues);

int main() {
    PassengerQueues queues = PassengerQueues();
    Selection selection;

    do {
        selection = menu();

        switch (selection) {
            case Selection::ADD:
                addPassenger(queues);
                break;
            case Selection::DELETE:
                deletePassenger(queues);
                break;
            case Selection::SHOW:
                showPassengers(queues);
                break;
            default:
                break;
        }

        std::cout << '\n';
    } while (selection != Selection::EXIT);
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

void addPassenger(PassengerQueues& queues) {
    std::cout << "Enter the name: ";

    std::string name;
    std::getline(std::cin, name);

    if (!queues.booked.full()) {
        queues.booked.push(Passenger(name));
        std::cout << "Booking " << name << " for the flight.\n";
    } else if (!queues.waiting.full()) {
        queues.waiting.push(Passenger(name));
        std::cout << "Sorry, the plane is fully booked. Adding " << name
                  << " to the waiting list.\n";
    } else {
        std::cout << "Sorry, the plane and waiting list are both fully booked; "
                     "try again later.\n";
    }
}

void deletePassenger(PassengerQueues& queues) {
    if (!queues.booked.empty()) {
        std::cout << "Removing " << queues.booked.getFront()
                  << " from the booked passengers queue.\n";
        queues.booked.pop();

        if (!queues.waiting.empty()) {
            Passenger& front = queues.waiting.getFront();

            std::cout << "Booking " << front
                      << " from the waiting list.\n";
            queues.booked.push(std::move(front));
            queues.waiting.pop();
        }
    } else {
        std::cout << "There are no passengers to delete.\n";
    }
}

void showPassengers(PassengerQueues& queues) {
    if (queues.booked.empty()) {
        std::cout << "Queue is empty.\n";
    } else {
        std::cout << "\nBooked Passengers\n=================\n";

        for (const Passenger& p : queues.booked) {
            std::cout << p << '\n';
        }

        if (!queues.waiting.empty()) {
            std::cout << "\nWaiting List\n=================\n";

            for (const Passenger& p : queues.waiting) {
                std::cout << p << '\n';
            }
        }
    }
}
