#include <stdexcept>
#include "Stack.hpp"

Stack::Stack() : topVal(-1) {
    std::fill(data, data + 21, 0);
}

void Stack::push(const char c) {
    if (isFull()) {
        throw std::logic_error("Cannot push onto a full stack.");
    }

    ++topVal;
    data[topVal] = c;
}

void Stack::pop() {
    if (isEmpty()) {
        throw std::logic_error("Cannot pop an empty stack.");
    }

    data[topVal] = 0;
    --topVal;
}

char Stack::top() const {
    if (isEmpty()) {
        throw std::logic_error("Cannot retrieve the top of an empty stack.");
    }

    return data[topVal];
}

bool Stack::isEmpty() const {
    return topVal == -1;
}

bool Stack::isFull() const {
    return topVal == 21;
}
