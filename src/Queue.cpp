#include "Queue.hpp"

template<typename T>
Queue::Queue(const int size) : front(size), back(size), size(size + 1) {
    c = new T[size];
}

Queue::~Queue() {
    delete[] c;
}

template<class T>
void Queue::push(T& data) {

}

void Queue::pop() {

}

template<class T>
T* Queue::getFront() {
    return T();
}

bool Queue::empty() {
    return false;
}

bool Queue::full() {
    return false;
}
