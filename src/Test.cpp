#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unordered_set>

#include "Stack.hpp"

/**
 * Validates an expression using a @c Stack.
 *
 * An expression is valid if:
 * <ul>
 *     <li>Characters only consist of [, ], (, ), {, and }.</li>
 *     <li>
 *         The right-most not-compared left character completes the pair for
 *         each right character.
 *     </li>
 * </ul>
 *
 * @param   stack   The @c Stack to use for the validation process.
 * @param   exp     The expression to validate.
 * @return          @c true if valid; @c false otherwise.
 */
bool isValid(Stack& stack, const char* exp);

/**
 * @brief Program's entry point.
 *
 * Prompts the user to input an expression. The expression is validated
 * and its validity is then displayed to the user.
 */
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

        if (left.count(c)) {
            // Push all left characters onto the stack. Right characters are
            // never pushed.
            stack.push(c);
        } else if (!stack.isEmpty() && std::abs(stack.top() - c) <= 2) {
             /*
              * Since it's not left, it's assumed it's right.
              *
              * If the stack is empty, this means the current right character
              * has no left pair.
              *
              * The pair is determined by how close the ASCII decimal
              * equivalents of the characters are to each other. Because it is
              * assumed that only valid characters will be entered, this is a
              * safe method to use; the three pairs of characters have a
              * difference far greater than 2 between one another.
              * If the top of the stack is a pair with the current character,
              * pop the stack.
              */
            stack.pop();
        } else {
            // Expression is invalid.
            return false;
        }
    }

    // If the stack isn't empty, it means there is at least one dangling left
    // character without a right pair.
    return stack.isEmpty();
}
