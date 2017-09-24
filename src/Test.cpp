#include <array>
#include <iostream>

#include "Queue.hpp"

struct Passenger {
    /**
    * Determines which queue a @c Passenger is in.
    */
    static enum Status {
        BOOKED,
        WAITING,
        NONE
    };

    std::string name = "";
    Status status = Status::NONE;

    Passenger() = default;

    explicit Passenger(std::string& name) : name(name) { };

    Passenger(std::string& name, Status status)
            : name(name), status(status) { };
};

struct Queues {
    Queue booked = Queue(3);
    Queue waiting = Queue(3);

    // Queues() = default;

    // Queues(Queue booked, Queue waiting) : booked(booked), waiting(waiting) { };
};

/**
 * Represents a menu selection.
 */
enum Selection {
    ADD,
    DELETE,
    SHOW,
    EXIT
};

/**
 * Displays a menu with selectable options to the user and prompts the user to
 * make a @c Selection.
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
void addPassenger(Queues& queues);

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
void deletePassenger(Queues& queues);

/**
 * @brief Lists all passengers.
 *
 * Displays a list of all passengers in each @c Queue (booked and waiting list).
 *
 * @param   queues  @c Queues for booked and waiting list.
 */
void showPassengers(Queues& queues);

int main() {
    Queues queues = Queues();
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

    int selection;
    std::cin >> selection;

    return static_cast<Selection>(selection);
}

void addPassenger(Queues& queues) {

}

void deletePassenger(Queues& queues) {

}

void showPassengers(Queues& queues) {

}
