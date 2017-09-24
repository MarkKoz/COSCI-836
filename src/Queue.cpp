#include "Queue.hpp"

template<typename T>
Queue<T>::Queue(const int size) : front(size), back(size), size(size + 1) {
    c = new T[size];
}

template<typename T>
Queue<T>::~Queue() {
    delete[] c;
}

template<typename T>
void Queue<T>::push(T& data) {

}

template<typename T>
void Queue<T>::pop() {

}

template<typename T>
T* Queue<T>::getFront() {
    return T();
}

template<typename T>
bool Queue<T>::empty() {
    return false;
}

template<typename T>
bool Queue<T>::full() {
    return false;
}
