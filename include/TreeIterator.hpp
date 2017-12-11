#ifndef ASSIGNMENT_5_TREEITERATOR_HPP
#define ASSIGNMENT_5_TREEITERATOR_HPP

#include <cstddef>
#include <iterator>

#include "Node.hpp"

// Forward declaration for friendship.
template <typename T>
class TreeIteratorConst;

/**
 * An implementation of a ForwardIterator for a @c Tree. Allows for descending
 * in-order traversal of a @c Tree and reading of iterated elements.
 *
 * @tparam  T       The type of the elements to iterated.
 */
template <typename T>
class TreeIterator : public std::iterator<std::forward_iterator_tag,
                                          T,
                                          std::ptrdiff_t,
                                          T*,
                                          T&> {
    friend class TreeIteratorConst<T>;

public:
    /**
     * @brief Default constructor.
     */
    TreeIterator() : node() { }

    /**
     * Constructs an iterator at the given position @c n.
     *
     * @param   n       A pointer to a @c Node in the container.
     */
    explicit TreeIterator(Node<T>* n) : node(n) { }

    /**
     * @brief Unary prefix increment operator.
     *
     * Advances to the next in-order node.
     *
     * @return          Reference to the iterator after incrementation.
     */
    TreeIterator<T>& operator++() {
        if (node->isThreaded()) {
            // The in-order successor is whatever is in the thread.
            node = node->getThread().lock().get();
        } else if (node->getLeft()) {
            // The left node exists. The in-order successor is the right-most
            // node of the left child.
            node = node->getLeft()->getRightmost();
        } else {
            // The current node is not threaded and its left child doesn't
            // exist. Therefore, the current node must be the last node in
            // the tree.
            node = nullptr;
        }

        return *this;
    }

    /**
     * @brief Unary postfix increment operator.
     *
     * Advances to the next in-order @c Node and returns a reference to a copy
     * of the iterator made @a before incrementation.
     *
     * @return          A reference to the iterator @a before
     *                  incrementation.
     */
    TreeIterator<T>& operator++(int) {
        TreeIterator<T> it(*this);
        operator++();

        return it;
    }

    /**
     * @brief Unary prefix indirection operator.
     *
     * Retrieves a reference to the value stored in the @c Node.
     *
     * @return          A reference to the value stored in the @c Node.
     */
    T& operator*() const {
        return *node->value();
    }

    /**
     * @brief Binary infix member of pointer access operator.
     *
     * Retrieves the pointer to the value stored in the @c Node.
     *
     * @return          A pointer to the value stored in the @c Node.
     */
    T* operator->() const {
        return node->value();
    }

    /**
     * @brief Binary infix equality comparison operator.
     *
     * Performs a comparison to determine if the two elements are equal.
     *
     * @param   rhs     The element to compare against.
     * @return          @c true if equal; @c false otherwise.
     */
    bool operator==(const TreeIterator<T>& rhs) const {
        return node == rhs.node;
    }

    /**
     * @brief Binary infix inequality comparison operator.
     *
     * Performs a comparison to determine if the two elements are unequal.
     *
     * @param   rhs     The element to compare against.
     * @return          @c true if unequal; @c false otherwise.
     */
    bool operator!=(const TreeIterator<T>& rhs) const {
        return !operator==(rhs);
    }

private:
    Node<T>* node;
};

/**
 * An implementation of a const ForwardIterator for a @c Tree. Allows for
 * descending in-order traversal of a @c Tree and reading of iterated elements.
 *
 * @tparam  T       The type of the elements to iterated.
 */
template <typename T>
class TreeIteratorConst : public std::iterator<std::forward_iterator_tag,
                                          T,
                                          std::ptrdiff_t,
                                          T*,
                                          T&> {
public:
    /**
     * @brief Default constructor.
     */
    TreeIteratorConst() : node() { }

    /**
     * Constructs a constant iterator from a const-qualified @c TreeIterator.
     *
     * @param   iter    The @c TreeIterator from which to construct.
     */
    explicit TreeIteratorConst(const TreeIterator<T>& iter)
            : node(iter.node) { }

    /**
     * Constructs an iterator at the given position @c n.
     *
     * @param   n       A pointer to a @c Node in the container.
     */
    explicit TreeIteratorConst(const Node<T>* n) : node(n) { }

    /**
     * @brief Unary prefix increment operator.
     *
     * Advances to the next in-order node.
     *
     * @return          Reference to the iterator after incrementation.
     */
    TreeIteratorConst<T>& operator++() {
        if (node->isThreaded()) {
            // The in-order successor is whatever is in the thread.
            node = node->thread.lock().get();
        } else if (node->getLeft()) {
            // The left node exists. The in-order successor is the right-most
            // node of the left child.
            node = node->getLeft()->getRightmost();
        } else {
            // The current node is not threaded and its left child doesn't
            // exist. Therefore, the current node must be the last node in
            // the tree.
            node = nullptr;
        }

        return *this;
    }

    /**
     * @brief Unary postfix increment operator.
     *
     * Advances to the next in-order @c Node and returns a reference to a copy
     * of the iterator made @a before incrementation.
     *
     * @return          A reference to the iterator @a before
     *                  incrementation.
     */
    TreeIteratorConst<T>& operator++(int) {
        TreeIteratorConst<T> it(*this);
        operator++();

        return it;
    }

    /**
     * @brief Unary prefix indirection operator.
     *
     * Retrieves a reference to the value stored in the @c Node.
     *
     * @return          A reference to the value stored in the @c Node.
     */
    const T& operator*() const {
        return *node->value();
    }

    /**
     * @brief Binary infix member of pointer access operator.
     *
     * Retrieves the pointer to the value stored in the @c Node.
     *
     * @return          A pointer to the value stored in the @c Node.
     */
    const T* operator->() const {
        return node->value();
    }
    /**
     * @brief Binary infix equality comparison operator.
     *
     * Performs a comparison to determine if the two elements are equal.
     *
     * @param   rhs     The element to compare against.
     * @return          @c true if equal; @c false otherwise.
     */

    bool operator==(const TreeIteratorConst<T>& rhs) const {
        return node == rhs.node;
    }

    /**
     * @brief Binary infix inequality comparison operator.
     *
     * Performs a comparison to determine if the two elements are unequal.
     *
     * @param   rhs     The element to compare against.
     * @return          @c true if unequal; @c false otherwise.
     */
    bool operator!=(const TreeIteratorConst<T>& rhs) const {
        return !operator==(rhs);
    }

private:
    const Node<T>* node;
};

#endif
