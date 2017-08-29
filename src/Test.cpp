#include <iostream>
#include "Date.hpp"

using namespace std;

int main() {
    Date d1;
    int m, d, y;

    cout << "Enter month, day and year separated by spaces: ";
    cin >> m >> d >> y;

    d1.setDate(m, d, y);
    d1.printDate();

    return 0;
}
