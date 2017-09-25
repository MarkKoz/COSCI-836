#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "Queue.hpp"

template<typename T>
Queue<T>::Queue(const std::size_t size)
        : front(size),
          back(size),
          size(size + 1),
          c(new T [this->size]) {
    std::fill(c, c + this->size, Passenger());
}

template<typename T>
Queue<T>::~Queue() {
    /*for (int i = 0; i < size; ++i) {
        delete c[i];
    }*/

    delete[] c;
}

template<typename T>
void Queue<T>::push(T&& data) {
    if (full()){
        throw std::logic_error("Cannot push onto a full queue.");
    }

    back = (back + 1) % size;
    c[back] = std::forward<T>(data);
}

template<typename T>
void Queue<T>::pop() {
    if (empty()) {
        throw std::logic_error("Cannot pop an empty queue.");
    }

    front = (front + 1) % size;
    // delete c[front];
    c[front] = Passenger();
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
QueueIterator<T> Queue<T>::begin() {
    return QueueIterator<T>(c + ((front + 1) % size), c, size);
}

template<typename T>
QueueIterator<T> Queue<T>::end() {
    return QueueIterator<T>(c + ((back + 1) % size), c, size);
}

template<typename T>
QueueIteratorConst<T> Queue<T>::begin() const {
    return QueueIteratorConst<T>(c + ((front + 1) % size), c, size);
}

template<typename T>
QueueIteratorConst<T> Queue<T>::end() const {
    return QueueIteratorConst<T>(c + ((back + 1) % size), c, size);
}
