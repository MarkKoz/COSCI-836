#ifndef ASSIGNMENT_2_STACK_HPP
#define ASSIGNMENT_2_STACK_HPP

/**
 * An container which enforces last in first out (LIFO) stack behaviour.
 * Wraps around an array.
 */
template <typename T>
class Stack {
public:
    /**
     * Constructs an empty stack with a capacity of 21 elements.
     */
    Stack();

    /**
     * Deletes the underlying array on destruction.
     */
    ~Stack();

    /**
     * Creates a new element at the top of the stack and assigns to it the
     * given data. The new element is initialised as a copy of @c data.
     *
     * @param   data       The data to insert.
     * @throws  std::logic_error    Thrown if the stack is full.
     */
    void push(const T& data);

    /**
     * Creates a new element at the top of the stack and assigns to it the
     * given data. @c data is moved into the new element.
     *
     * @param   data       The data to insert.
     * @throws  std::logic_error    Thrown if the stack is full.
     */
    void push(T&& data);

    /**
     * Removes the top element.
     *
     * @throws  std::logic_error    Thrown if the stack is empty.
     */
    void pop();

    /**
     * Returns a reference to the data at the first element of the stack.
     *
     * @return          The data at the first element.
     * @throws  std::logic_error    Thrown if the stack is empty.
     */
    T& top();

    /**
     * Returns a const-qualified reference to the data at first element of the
     * stack.
     *
     * @return          The data at the first element.
     * @throws  std::logic_error    Thrown if the stack is empty.
     */
    const T& top() const;

    /**
     * Checks whether the underlying array is empty.
     *
     * @return          @c true if empty; @c false otherwise.
     */
    bool empty() const;

    /**
     * Checks whether the underlying array is full.
     *
     * @return          @c true if full; @c false otherwise.
     */
    bool full() const;

private:
    int back; // The index of the top element.
    const int size; // Capacity of the underlying array.
    T* c; // The underlying array.
};

#include "Stack.cpp"

#endif
