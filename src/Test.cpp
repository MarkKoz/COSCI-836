#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unordered_set>

#include "Stack.hpp"

bool isValid(Stack& stack, const char* exp);
bool checkSide(const char cmp, const std::unordered_set<char>& set);

int main() {
    char exp[21];
    Stack stack;

    std::cout << "Enter an expression: ";
    std::cin >> exp;

    isValid(stack, exp) ? std::cout << "\nIt's a valid expression."
                        : std::cout << "\nIt's NOT a valid expression.";
}

bool isValid(Stack& stack, const char* exp) {
    std::unordered_set<char> left = {'(', '[', '{'};
    //std::unordered_set<const char> right = {')', ']', '}'};

    for (char c = *exp; c != 0; c = *++exp) {
        if (stack.isFull()) {
            // Expression is too long.
            return false;
        }

        if (checkSide(c, left)) {
            // Push all left characters onto the stack. Right characters are
            // never pushed.
            stack.push(c);
        } else if (!stack.isEmpty() && std::abs(stack.top() - c) <= 2) {
            // Since it's not left, it's assumed it's right. If the stack is
            // empty, this means the current right character has no left pair.
            // If the top of the stack is a pair with the current character,
            // pop the stack. The pair is determined by how close the ASCII
            // decimal representations of the characters are to each other.
            stack.pop();
        } else {
            // Expression is invalid.
            return false;
        }
    }

    // If the stack isn't empty, it means there is a dangling left character
    // without a right pair.
    return stack.isEmpty();
}

bool checkSide(const char cmp, const std::unordered_set<char>& set) {
    return std::any_of(set.cbegin(),
                       set.cend(),
                       [cmp](const char c){
                           return c == cmp;
                       });
}
