#include <algorithm>
#include <stdexcept>

#include "Queue.hpp"

template<typename T>
Queue<T>::Queue(const std::size_t size)
        : front(size),
          back(size),
          size(size + 1),
          c(new T[this->size]) {
    // std::fill(c, c + this->size, T());
}

template<typename T>
Queue<T>::~Queue() {
    delete[] c;
}

template<typename T>
void Queue<T>::push(T& data) {
    if (full()){
        throw std::logic_error("Cannot push onto a full queue.");
    }

    back = (back + 1) % size;
    c[back] = data;
}

template<typename T>
void Queue<T>::push(T&& data) {
    if (full()){
        throw std::logic_error("Cannot push onto a full queue.");
    }

    back = (back + 1) % size;
    c[back] = data;
}

template<typename T>
void Queue<T>::pop() {
    if (empty()) {
        throw std::logic_error("Cannot pop an empty queue.");
    }

    front = (front + 1) % size;
    // c[front] = T();
}

template<typename T>
T& Queue<T>::getFront() const {
    return c[(front + 1) % size];
}

template<typename T>
bool Queue<T>::empty() const {
    return front == back;
}

template<typename T>
bool Queue<T>::full() const {
    return front == (back + 1) % size;
}

template<typename T>
typename Queue<T>::iterator Queue<T>::begin() {
    if (empty()) {
        return end();
    }

    return Queue<T>::iterator(c + ((front + 1) % size), c, size);
}

template<typename T>
typename Queue<T>::iterator Queue<T>::end() {
    return Queue<T>::iterator(c + ((back + 1) % size), c, size);
}

template<typename T>
typename Queue<T>::const_iterator Queue<T>::begin() const {
    if (empty()) {
        return end();
    }

    return Queue<T>::const_iterator(c + ((front + 1) % size), c, size);
}

template<typename T>
typename Queue<T>::const_iterator Queue<T>::end() const {
    return Queue<T>::const_iterator(c + ((back + 1) % size), c, size);
}
