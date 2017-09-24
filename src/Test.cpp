#include <iostream>
#include <stdexcept>
#include <string>

#include "Queue.hpp"

/**
 * Determines which queue a @c Passenger is in.
 */
enum Status {
    BOOKED,
    WAITING
};

struct Passenger {
    std::string name;
    Status status;

    Passenger(std::string name, Status status)
            : name(std::move(name)), status(status) { };
};

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
    } while (selection != Selection::EXIT);
}

Selection menu() {
    std::cout << "Menu\n";
    std::cout << "========\n";
    std::cout << "1. Add Passenger\n";
    std::cout << "2. Delete Passenger\n";
    std::cout << "3. Show Passengers\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter choice: ";

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
    queues.booked.push(new Passenger("John", Status::BOOKED));
    queues.booked.push(new Passenger("Mary", Status::BOOKED));
    queues.booked.push(new Passenger("Lucas", Status::BOOKED));
}

void deletePassenger(PassengerQueues& queues) {
    queues.booked.pop();
}

void showPassengers(PassengerQueues& queues) {
    if (queues.booked.empty()) {
        std::cout << "Queue is empty.\n";
    } else {
        std::cout << queues.booked.getFront()->name << '\n';
    }
}
