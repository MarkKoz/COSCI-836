#ifndef ASSIGNMENT_3_QUEUEITERATORS_HPP
#define ASSIGNMENT_3_QUEUEITERATORS_HPP

#include <cstddef>
#include <iterator>
#include <type_traits>

#include "Queue.hpp"

/**
 * An implementation of an InputIterator for a Queue. Allows for the reading
 * of iterated elements.
 *
 * @tparam  T       The type of the elements to iterated.
 */
template <typename T>
class QueueIterator : public std::iterator<std::input_iterator_tag,
                                           T,
                                           std::ptrdiff_t,
                                           T*,
                                           T&> {
public:
    /**
     * Constructs a new iterator at the given position @c pos.
     *
     * @param   pos     A pointer to an element in the container.
     * @param   c       A pointer to the container.
     * @param   size    The total capacity of the container.
     */
    QueueIterator(T* pos, T* c, const std::size_t size);

    // TODO: Make const_iterator constructable from iterator.

    /**
     * @brief Unary prefix increment operator.
     *
     * Increments the pointer to the container by 1.
     *
     * Satisfies Iterator.
     *
     * @return          Reference to the iterator after incrementation.
     */
    QueueIterator& operator++();

    /**
     * @brief Unary postfix increment operator.
     *
     * Increments the pointer to the container by 1 and returns a reference
     * to a copy of the iterator made @a before incrementation.
     *
     * Satisfies InputIterator.
     *
     * @return          A reference to the iterator @a before
     *                  incrementation.
     */
    QueueIterator& operator++(int);

    /**
     * @brief Unary prefix indirection operator.
     *
     * Dereferences the operand, which must be a pointer.
     *
     * Satisfies Iterator.
     *
     * @return          A reference to the lvalue referring to the
     *                  object to which the operand points.
     */
    T& operator*() const;

    /**
     * @brief Binary infix member of pointer access operator.
     *
     * Satisfies InputIterator.
     *
     * @return
     */
    T* operator->() const;

    /**
     * @brief Binary infix equality comparison operator.
     *
     * Performs a comparison to determine if the two elements are equal.
     *
     * Satisfies EqualityComparable, which satisfies InputIterator.
     *
     * @param   rhs     The element to compare against.
     * @return          @c true if equal; @c false otherwise.
     */
    bool operator==(const QueueIterator& rhs) const;

    /**
     * @brief Binary infix inequality comparison operator.
     *
     * Performs a comparison to determine if the two elements are unequal.
     *
     * Satisfies InputIterator.
     *
     * @param   rhs     The element to compare against.
     * @return          @c true if unequal; @c false otherwise.
     */
    bool operator!=(const QueueIterator& rhs) const;

private:
    T* pos; // Pointer to the current position in the container.
    T* c; // Pointer to the container.
    const std::size_t size; // Size of the container.
};

#include "QueueIterator.cpp"

#endif
