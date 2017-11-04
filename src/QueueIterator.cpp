#include "QueueIterator.hpp"

template<typename T>
QueueIterator<T>::QueueIterator(T* pos, T* c, const std::size_t size)
        : pos(pos), c(c), size(size) { }

template<typename T>
QueueIterator<T>& QueueIterator<T>::operator++() {
    if (pos == c + size - 1) {
        // Wraps around to the start.
        pos = c;
    } else {
        ++pos;
    }

    return *this;
}

template<typename T>
QueueIterator<T>& QueueIterator<T>::operator++(int) {
    QueueIterator<T> it(*this);
    operator++();

    return it;
}

template<typename T>
T& QueueIterator<T>::operator*() const {
    return *pos;
}

template<typename T>
T* QueueIterator<T>::operator->() const {
    return pos;
}

template<typename T>
bool QueueIterator<T>::operator==(const QueueIterator<T>& rhs) const {
    return pos == rhs.pos;
}

template<typename T>
bool QueueIterator<T>::operator!=(const QueueIterator<T>& rhs) const {
    return !operator==(rhs);
}
