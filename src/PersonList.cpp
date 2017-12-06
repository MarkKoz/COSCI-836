#include <iostream>
#include <string>

#include "PersonList.hpp"

void PersonList::add() {
    Person person = getPerson();
    const_iterator prev = cbefore_begin();

    for (const_iterator node = cbegin(); node != cend(); ++node) {
        /*
         * If true, node is currently at the position right after the last
         * Person to bribe the same amount. Therefore, the previous node is
         * the node to insert after.
         */
        if ((*node).bribe < person.bribe) {
            break;
        }

        prev = node;
    }

    insertAfter(prev, std::move(person));
}

void PersonList::show() {
    // TODO: Make the output prettier.
    std::cout << "# Name Contribution\n";
    unsigned int i = 1;

    for (const Person& p : *this) {
        std::cout << i << " " << p.name << " $" << p.bribe << '\n';
        ++i;
    }
}

Person PersonList::getPerson() {
    std::string name, contribution;

    std::cout << "Enter the person's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter the person's contribution: ";
    std::getline(std::cin, contribution);

    return {name, std::stoul(contribution)};
}
