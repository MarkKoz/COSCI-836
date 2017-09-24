#ifndef ASSIGNMENT_3_QUEUE_HPP
#define ASSIGNMENT_3_QUEUE_HPP

#include <memory>
#include <string>

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
    explicit Queue(const int size);

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
     * @param   data    The data to insert.
     * @throws  std::logic_error    Thrown if the stack is full.
     */
    void push(T& data);

    /**
     * Removes the front element.
     *
     * @throws  std::logic_error    Thrown if the stack is empty.
     */
    void pop();

    /**
     * Returns a pointer to the element at the front of the queue.
     *
     * @return          A pointer to the element at the front of the queue.
     * @throws  std::logic_error    Thrown if the stack is empty.
     */
    T* getFront();

    /**
     * Checks whether the queue is empty.
     *
     * @return          @c true if empty; @c false otherwise.
     */
    bool empty();

    /**
     * Checks whether the queue is full.
     *
     * @return          @c true if full; @c false otherwise.
     */
    bool full();

private:
    int front; // Index of the element before the queue's front-most element.
    int back; // Index of the queue's back-most element.
    int size; // Number of elements in the array.
    std::unique_ptr<T>* c; // The underlying container.
};

#include "../src/Queue.cpp"

#endif
