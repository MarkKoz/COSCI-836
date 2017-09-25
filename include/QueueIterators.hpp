#ifndef ASSIGNMENT_3_QUEUEITERATORS_HPP
#define ASSIGNMENT_3_QUEUEITERATORS_HPP

#include <cstddef>
#include <iterator>

#include "Queue.hpp"

template <typename T>
class QueueIterator {
public:
    typedef std::forward_iterator_tag iterator_category;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;

    QueueIterator(pointer pos, pointer c, const std::size_t size);

    QueueIterator operator++();

    QueueIterator operator++(int);

    reference operator*() const;

    pointer operator->() const;

    bool operator==(const QueueIterator& rhs) const;

    bool operator!=(const QueueIterator& rhs) const;

private:
    pointer pos; // Pointer to the current position in the container.
    pointer c; // Pointer to the container.
    const std::size_t size; // Size of the container.
};

template <typename T>
class QueueIteratorConst {
public:
    typedef std::forward_iterator_tag iterator_category;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef const T* pointer;
    typedef const T& reference;

    QueueIteratorConst(pointer pos, pointer c, const std::size_t size);

    QueueIteratorConst operator++();

    QueueIteratorConst operator++(int);

    reference operator*() const;

    pointer operator->() const;

    bool operator==(const QueueIteratorConst& rhs) const;

    bool operator!=(const QueueIteratorConst& rhs) const;

private:
    pointer pos; // Pointer to the current position in the container.
    pointer c; // Pointer to the container.
    const std::size_t size; // Size of the container.
};

#include "QueueIterators.cpp"

#endif
