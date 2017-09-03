#include <iostream>
#include "Date.hpp"

Date::Date() : month(1), day(1), year(1900) { }

void Date::setDate(const int m, const int d, const int y) {
    if (!setMonth(m) || !setDay(d) || !setYear(y)) {
        month = 9;
        day = 2;
        year = 2008;
    }
}

bool Date::setMonth(int m) {
    month = m;

    return m >= 1 && m <= 12;
}

bool Date::setDay(const int d) {
    day = d;

    return d >= 1 && d <= 31;
}

bool Date::setYear(const int y) {
    year = y;

    return y >= 1900 && y <= 2008;
}

void Date::printDate() const {
    std::cout << month << '/' << day << '/' << year << '\n';
}
