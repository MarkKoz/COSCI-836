#include <stdexcept>
#include "Stack.hpp"

Stack::Stack() : topIndex(-1) {
    std::fill(container, container + 21, 0);
}

void Stack::push(const char data) {
    if (full()) {
        throw std::logic_error("Cannot push onto a full stack.");
    }

    ++topIndex;
    container[topIndex] = data;
}

void Stack::pop() {
    if (empty()) {
        throw std::logic_error("Cannot pop an empty stack.");
    }

    container[topIndex] = 0;
    --topIndex;
}

const char& Stack::top() const {
    if (empty()) {
        throw std::logic_error("Cannot retrieve the top of an empty stack.");
    }

    return container[topIndex];
}

bool Stack::empty() const {
    return topIndex == -1;
}

bool Stack::full() const {
    return topIndex == 21;
}
