#include <algorithm>
#include <stdexcept>

#include "Queue.hpp"

template<typename T>
Queue<T>::Queue(const int size)
        : front(size),
          back(size),
          size(size + 1),
          c(new const T* [this->size]) {
    std::fill(c, c + size, nullptr);
}


template<typename T>
Queue<T>::~Queue() {
    for (int i = 0; i < size; ++i) {
        delete c[i];
    }

    delete[] c;
}

template<typename T>
void Queue<T>::push(const T* const data) {
    if (full()){
        throw std::logic_error("Cannot push onto a full queue.");
    }

    back = (back + 1) % size;
    c[back] = data;
}

template<typename T>
void Queue<T>::pop() {
    if (empty()) {
        throw std::logic_error("Cannot pop off an empty queue.");
    }

    front = (front + 1) % size;
    delete c[back];
    c[back] = nullptr;
}

template<typename T>
const T*& Queue<T>::getFront() {
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
