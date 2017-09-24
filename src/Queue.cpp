#include "Queue.hpp"

template<typename T>
Queue<T>::Queue(const int size)
        : front(size),
          back(size),
          size(size + 1),
          c(new std::unique_ptr<T>[this->size]) { }


template<typename T>
Queue<T>::~Queue() {
    delete[] c;
}

template<typename T>
void Queue<T>::push(std::unique_ptr<T> data) {

}

template<typename T>
void Queue<T>::pop() {

}

template<typename T>
std::unique_ptr<T> Queue<T>::getFront() {
    return nullptr;
}

template<typename T>
bool Queue<T>::empty() {
    return false;
}

template<typename T>
bool Queue<T>::full() {
    return false;
}
