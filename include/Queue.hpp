#ifndef ASSIGNMENT_3_QUEUE_HPP
#define ASSIGNMENT_3_QUEUE_HPP

#include <iterator>
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
    class iterator {
    public:
        typedef std::forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

        explicit iterator(pointer p) : ptr(p) { }

        iterator operator++() {
            iterator i = *this;
            ptr++;

            return i;
        }

        iterator operator++(int dummy) {
            ptr++;

            return *this;
        }

        reference operator*() const {
            return *ptr;
        }

        pointer operator->() const {
            return ptr;
        }

        bool operator==(const iterator& rhs) const {
            return ptr == rhs.ptr;
        }

        bool operator!=(const iterator& rhs) const {
            return ptr != rhs.ptr;
        }

    private:
        pointer ptr;
    };

    class const_iterator {
    public:
        typedef std::forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef const T* pointer;
        typedef const T& reference;

        explicit const_iterator(pointer p) : ptr(p) { }

        const_iterator operator++() {
            const_iterator i = *this;
            ptr++;

            return i;
        }

        const_iterator operator++(int dummy) {
            ptr++;

            return *this;
        }

        reference operator*() const {
            return *ptr;
        }

        pointer operator->() const {
            return ptr;
        }

        bool operator==(const const_iterator& rhs) const {
            return ptr == rhs.ptr;
        }

        bool operator!=(const const_iterator& rhs) const {
            return ptr != rhs.ptr;
        }

    private:
        pointer ptr;
    };

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
     * @param   data    A pointer to the data to insert.
     * @throws  std::logic_error    Thrown if the stack is full.
     */
    void push(T const data);

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
    T& getFront();

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

    iterator begin() {
        return iterator(c);
    }

    iterator end() {
        return iterator(c + size - 1);
    }

    const_iterator begin() const {
        return const_iterator(c);
    }

    const_iterator end() const {
        return const_iterator(c + size - 1);
    }

private:
    int front; // Index of the element before the queue's front-most element.
    int back; // Index of the queue's back-most element.
    int size; // Number of elements in the array.
    T* c; // The underlying container.
};

#include "../src/Queue.cpp"

#endif
