#ifndef ASSIGNMENT_3_QUEUE_HPP
#define ASSIGNMENT_3_QUEUE_HPP

#include <cstddef>

#include "QueueIterators.hpp"

typedef std::string Passenger;

/**
 * A container which enforces first in first out (FIFO) behaviour. Wraps
 * around an array.
 *
 * @tparam  T   The type of the object to contain.
 */
template<typename T>
class Queue {
public:
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
     * given data.
     *
     * @param   data    A pointer to the data to insert.
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

    QueueIterator<T> begin();

    QueueIterator<T> end();

    QueueIteratorConst<T> begin() const;

    QueueIteratorConst<T> end() const;
private:
    std::size_t front; // Index of the element before the front-most element.
    std::size_t back; // Index of the back-most element.
    const std::size_t size; // Number of elements in the array.
    T* c; // The underlying container.
};

#include "Queue.cpp"

#endif
