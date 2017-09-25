#ifndef ASSIGNMENT_3_AIRLINE_HPP
#define ASSIGNMENT_3_AIRLINE_HPP

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
    void add();

    /**
     * @brief Removes the front-most @c Passenger from @c booked.
     *
     * If there are @c Passengers in @c waiting, the front-most of those @c
     * Passengers is moved to the back of @c booked.
     *
     * A message is displayed indicating the success or failure of the removal.
     * A failure occurs if no @c Passenger is left for deletion.
     */
    void remove();

    /**
     * @brief Lists all @c Passengers.
     *
     * Displays a list of all @c Passengers in each @c Queue. If there are no
     * @c Passengers to list, a message indicating this is instead displayed.
     */
    void show();
};

#endif
