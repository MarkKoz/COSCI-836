#include <cstring>
#include <cstdlib>
#include <iostream>

#include "Stack.hpp"

bool isValid(Stack& stack, char* exp);

int main() {
    char exp[21];
    Stack stack;

    std::cout << "Enter an expression: ";
    std::cin >> exp;

    isValid(stack, exp) ? std::cout << "\nIt's a valid expression."
                        : std::cout << "\nIt's NOT a valid expression.";
}

bool isValid(Stack& stack, char* exp) {
    return false;
}
