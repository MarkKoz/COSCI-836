#include <iostream>
#include <string>

#include "Airline.hpp"

void Airline::add() {
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
        std::cout << "Sorry, the plane and waiting list are both fully booked; "
                     "try again later.\n";
    }
}

void Airline::remove() {
    if (!booked.empty()) {
        std::cout << "Removing " << booked.getFront()
                  << " from the booked passengers queue.\n";
        booked.pop();

        if (!waiting.empty()) {
            Passenger& front = waiting.getFront();

            std::cout << "Booking " << front  << " from the waiting list.\n";

            booked.push(std::move(front));
            waiting.pop();
        }
    } else {
        std::cout << "There are no passengers to delete.\n";
    }
}

void Airline::show() {
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
