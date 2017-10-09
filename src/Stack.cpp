#include <algorithm>
#include <stdexcept>
#include <utility>

#include "Stack.hpp"

template<typename T>
Stack<T>::Stack() : back(-1), size(21), c(new T[size]) {
    // std::fill(c, c + size, T());
}

template<typename T>
Stack<T>::~Stack() {
    delete[] c;
}

template<typename T>
void Stack<T>::push(const T& data) {
    if (full()) {
        throw std::logic_error("Cannot push onto a full stack.");
    }

    ++back;
    c[back] = data;
}

template<typename T>
void Stack<T>::push(T&& data) {
    if (full()) {
        throw std::logic_error("Cannot push onto a full stack.");
    }

    ++back;
    c[back] = std::move(data);
}

template<typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw std::logic_error("Cannot pop an empty stack.");
    }

    // c[back] = T();
    --back;
}

template<typename T>
T& Stack<T>::top() {
    if (empty()) {
        throw std::logic_error("Cannot retrieve the top of an empty stack.");
    }

    return c[back];
}

template<typename T>
const T& Stack<T>::top() const {
    if (empty()) {
        throw std::logic_error("Cannot retrieve the top of an empty stack.");
    }

    return c[back];
}

template<typename T>
bool Stack<T>::empty() const {
    return back == -1;
}

template<typename T>
bool Stack<T>::full() const {
    return back == size;
}
