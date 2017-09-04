#include <stdexcept>
#include "Stack.hpp"

Stack::Stack() : t(-1) {
    std::fill(container, container + 21, 0);
}

void Stack::push(const char data) {
    if (full()) {
        throw std::logic_error("Cannot push onto a full stack.");
    }

    ++t;
    container[t] = data;
}

void Stack::pop() {
    if (empty()) {
        throw std::logic_error("Cannot pop an empty stack.");
    }

    container[t] = 0;
    --t;
}

const char& Stack::top() const {
    if (empty()) {
        throw std::logic_error("Cannot retrieve the top of an empty stack.");
    }

    return container[t];
}

bool Stack::empty() const {
    return t == -1;
}

bool Stack::full() const {
    return t == 21;
}
