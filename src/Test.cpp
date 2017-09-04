#include <iostream>

#include "Date.hpp"

int main() {
    Date d1;
    int m, d, y;

    std::cout << "Enter month, day and year separated by spaces: ";
    std::cin >> m >> d >> y;

    d1.set(m, d, y);
    d1.print();
}
