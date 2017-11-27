#ifndef ASSIGNMENT_4_PERSONLIST_HPP
#define ASSIGNMENT_4_PERSONLIST_HPP

#include <iostream>
#include <string>

#include "List.hpp"

struct Person {
    std::string name;
    unsigned long bribe;
};

struct PersonList : List<Person> {
    void add() {
        std::string name, contribution;

        std::cout << "Enter the person's name: ";
        std::getline(std::cin, name);

        std::cout << "Enter the person's contribution: ";
        std::getline(std::cin, contribution);

        Person person {
            name,
            std::stoul(contribution)
        };

        if (empty()) {
            insertAfter(cbefore_begin(), std::move(person));
            return;
        }

        const_iterator prev = cbefore_begin();

        for (const_iterator node = cbegin(); node != cend(); ++node) {
            // If true, node is currently at the position right after the
            // last Person to bribe the same amount.
            // Therefore, the previous node (pos) will be the node to insert
            // after.
            if ((*node).bribe < person.bribe) {
                break;
            }

            prev = node;
        }

        insertAfter(prev, std::move(person));
    }

    void show() {
        // TODO: Make the output prettier.
        std::cout << "# Name Contribution\n";
        unsigned int i = 1;

        for (const Person& p : *this) {
            std::cout << i << " " << p.name << " $" << p.bribe << '\n';
            ++i;
        }
    }
};

#endif
