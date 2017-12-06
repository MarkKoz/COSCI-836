#ifndef ASSIGNMENT_4_PERSONLIST_HPP
#define ASSIGNMENT_4_PERSONLIST_HPP

#include <string>

#include "List.hpp"

struct Person {
    std::string name;
    unsigned long bribe;
};

/**
 * @brief A wrapper class for a @c List of @c Persons.
 *
 * Provides functions for adding to the @c List and displaying its contents to
 * the user.
 */
class PersonList : List<Person> {
public:
    /**
     * @brief Adds a @c Person to the @c List.
     *
     * The @c List is sorted in descending order based on the @c bribe of a
     * @c Person. It is secondarily sorted in chronological order i.e. in the
     * case of a tie, the @c Person which was inserted earlier will be higher
     * on the @c List.
     */
    void add();

    /**
     * Formats and prints the @c List as an indexed table with columns for names
     * and contributions.
     */
    void show();
private:
    /**
     * Prompts the user to input a person's name and contribution. Constructs
     * a Person object from the given information and returns it.
     *
     * No input validation is performed.
     *
     * @return          A @c Person constructed from the given information.
     */
    Person getPerson();
};

#endif
