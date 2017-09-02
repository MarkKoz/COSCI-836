#ifndef ASSIGNMENT_2_STACK_HPP
#define ASSIGNMENT_2_STACK_HPP

class Stack {
public:
    Stack();

    void push(char c);

    void pop();

    char top() const;

    bool isEmpty() const;

    bool isFull() const;

private:
    int topVal;
    char data[21];
};

#endif
