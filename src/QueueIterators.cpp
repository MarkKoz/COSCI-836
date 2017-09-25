#include "QueueIterators.hpp"

template<typename T>
QueueIterator<T>::QueueIterator(pointer pos, pointer c, const std::size_t size)
        : pos(pos), c(c), size(size) { }

template<typename T>
QueueIterator<T> QueueIterator<T>::operator++() {
    QueueIterator<T> it = *this;

    if (pos == c + size - 1) {
        pos = c;
    } else {
        ++pos;
    }

    return it;
}

template<typename T>
QueueIterator<T> QueueIterator<T>::operator++(int) {
    if (pos == c + size - 1) {
        pos = c;
    } else {
        ++pos;
    }

    return *this;
}

template<typename T>
typename QueueIterator<T>::reference QueueIterator<T>::operator*() const {
    return *pos;
}

template<typename T>
typename QueueIterator<T>::pointer QueueIterator<T>::operator->() const {
    return pos;
}

template<typename T>
bool QueueIterator<T>::operator==(const QueueIterator<T>& rhs) const {
    return pos == rhs.pos;
}

template<typename T>
bool QueueIterator<T>::operator!=(const QueueIterator<T>& rhs) const {
    return pos != rhs.pos;
}

template<typename T>
QueueIteratorConst<T>::QueueIteratorConst(pointer pos,
                                          pointer c,
                                          const std::size_t size)
        : pos(pos), c(c), size(size) { }

template<typename T>
QueueIteratorConst<T> QueueIteratorConst<T>::operator++() {
    QueueIteratorConst<T> it = *this;

    if (pos == c + size - 1) {
        pos = c;
    } else {
        ++pos;
    }
    return it;
}

template<typename T>
QueueIteratorConst<T> QueueIteratorConst<T>::operator++(int) {
    if (pos == c + size - 1) {
        pos = c;
    } else {
        ++pos;
    }

    return *this;
}

template<typename T>
typename QueueIteratorConst<T>::reference
QueueIteratorConst<T>::operator*() const {
    return *pos;
}

template<typename T>
typename QueueIteratorConst<T>::pointer
QueueIteratorConst<T>::operator->() const {
    return pos;
}

template<typename T>
bool QueueIteratorConst<T>::operator==(const QueueIteratorConst<T>& rhs) const {
    return pos == rhs.pos;
}

template<typename T>
bool QueueIteratorConst<T>::operator!=(const QueueIteratorConst<T>& rhs) const {
    return pos != rhs.pos;
}
