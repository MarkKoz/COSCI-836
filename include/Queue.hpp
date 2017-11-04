#ifndef ASSIGNMENT_3_QUEUE_HPP
#define ASSIGNMENT_3_QUEUE_HPP

#include <cstddef>

#include "QueueIterator.hpp"

using Passenger = std::string;

/**
 * A container which enforces first in first out (FIFO) behaviour. Wraps
 * around an array.
 *
 * @tparam  T   The type of the object to contain.
 */
template<typename T>
class Queue {
public:
    using iterator = QueueIterator<T>;
    using const_iterator = QueueIterator<const T>;

    /**
     * Constructs an empty queue.
     */
    explicit Queue(const std::size_t size);

    /**
     * @brief Destructor.
     *
     * Deletes the underlying container.
     */
    ~Queue();

    /**
     * Creates a new element at the back of the queue and assigns to it the
     * given data. The new element is initialised as a copy of @c data.
     *
     * @param   data    The data to insert.
     * @throws  std::logic_error    Thrown if the stack is full.
     */
    void push(T& data);

    /**
     * Creates a new element at the back of the queue and assigns to it the
     * given data. @c data is moved into the new element.
     *
     * @param   data    The data to insert.
     * @throws  std::logic_error    Thrown if the stack is full.
     */
    void push(T&& data);

    /**
     * Removes the front element.
     *
     * @throws  std::logic_error    Thrown if the stack is empty.
     */
    void pop();

    /**
     * Returns a reference to a pointer to the element at the front of the
     * queue.
     *
     * @return          A pointer to the element at the front of the queue.
     * @throws  std::logic_error    Thrown if the stack is empty.
     */
    T& getFront() const;

    /**
     * Checks whether the queue is empty.
     *
     * @return          @c true if empty; @c false otherwise.
     */
    bool empty() const;

    /**
     * Checks whether the queue is full.
     *
     * @return          @c true if full; @c false otherwise.
     */
    bool full() const;

    /**
     * Returns an iterator to the first element of the container.
     *
     * If the container is empty, the returned iterator will be equal to @c
     * end().
     *
     * @return          An iterator to the first element.
     */
    iterator begin();

    /**
     * Returns an iterator to the element following the last element of
     * the container (past-the-last).
     *
     * @return          An iterator to the past-the-last element.
     */
    iterator end();

    /**
     * Returns a const-qualified iterator to the first element of the container.
     *
     * If the container is empty, the returned iterator will be equal to @c
     * end().
     *
     * @return          A const-qualified iterator to the first element.
     */
    const_iterator begin() const;

    /**
     * Returns a const-qualified iterator to the element following the last
     * element of the container (past-the-last).
     *
     * @return          A const-qualified iterator to the past-the-last element.
     */
    const_iterator end() const;

private:
    std::size_t front; // Index of the element before the front-most element.
    std::size_t back; // Index of the back-most element.
    const std::size_t size; // Number of elements in the array.
    T* c; // The underlying container.
};

#include "Queue.cpp"

#endif
