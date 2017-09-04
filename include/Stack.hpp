#ifndef ASSIGNMENT_2_STACK_HPP
#define ASSIGNMENT_2_STACK_HPP

/**
 * An adaptor class which wraps around an underlying container to enforce
 * last in first out (LIFO) stack behaviour.
 */
class Stack {
public:
    /**
     * Constructs an empty stack.
     */
    Stack();

    /**
     * Creates a new element at the top of the stack and assigns to it the given
     * data.
     *
     * @param   data       The data to insert.
     * @throws  std::logic_error    Thrown if the stack is full.
     */
    void push(const char data);

    /**
     * Removes the top element.
     *
     * @throws  std::logic_error    Thrown if the stack is empty.
     */
    void pop();

    /**
     * Returns a constant reference to the data at the element at the top of
     * the stack.
     *
     * @return          The data at the top element.
     * @throws  std::logic_error    Thrown if the stack is empty.
     */
    const char& top() const;

    /**
     * Checks whether the underlying container is empty.
     *
     * @return          @c true if empty; @c false otherwise.
     */
    bool empty() const;


    /**
     * Checks whether the underlying container is full.
     *
     * @return          @c true if full; @c false otherwise.
     */
    bool full() const;

private:
    int t; // The index of the top element.
    char container[21]; // The underlying container.
};

#endif
