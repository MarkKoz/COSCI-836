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
     * Inserts an element at the top.
     *
     * @param   c       The element to insert.
     * @throws  std::logic_error    Thrown if the stack is full.
     */
    void push(const char c);

    /**
     * Removes the top element.
     *
     * @throws  std::logic_error    Thrown if the stack is empty.
     */
    void pop();

    /**
     * Accesses the top element.
     *
     * @return          The top element.
     * @throws  std::logic_error    Thrown if the stack is empty.
     */
    char top() const;

    /**
     * Checks whether the underlying container is empty.
     *
     * @return          @c true if empty; @c false otherwise.
     */
    bool isEmpty() const;


    /**
     * Checks whether the underlying container is full.
     *
     * @return          @c true if full; @c false otherwise.
     */
    bool isFull() const;

private:
    int topVal; // The index of the top element.
    char data[21]; // The underlying container.
};

#endif
