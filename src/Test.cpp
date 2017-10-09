#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
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
bool isValid(Stack<char>& stack, const std::string& exp);

/**
 * @brief Program's entry point.
 *
 * Prompts the user to input an expression. The expression is validated
 * and its validity is then displayed to the user.
 */
int main() {
    std::string exp;
    Stack<char> stack;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, exp);

    isValid(stack, exp) ? std::cout << "\nIt's a valid expression."
                        : std::cout << "\nIt's NOT a valid expression.";
}

bool isValid(Stack<char>& stack, const std::string& exp) {
    const std::unordered_set<char> left = {'(', '[', '{'};
    const std::unordered_set<char> right = {')', ']', '}'};

    for (const char c : exp) {
        if (stack.full()) {
            // Expression is too long.
            return false;
        }

        if (left.count(c)) {
            // Push only left characters onto the stack; right characters are
            // never pushed.
            stack.push(c);
        } else if (!stack.empty() &&
                   right.count(c) &&
                   std::abs(stack.top() - c) <= 2) {
             /*
              * If the stack is empty, this means the current right character
              * has no left pair.
              *
              * The pair is determined by how close the ASCII decimal
              * equivalents of the characters are to each other. The three
              * pairs of characters have a difference far greater than 2
              * between one another.
              *
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
    return stack.empty();
}
