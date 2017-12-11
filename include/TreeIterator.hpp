#ifndef ASSIGNMENT_5_TREEITERATOR_HPP
#define ASSIGNMENT_5_TREEITERATOR_HPP

#include <cstddef>
#include <iterator>
#include <memory>

#include "Node.hpp"

template <typename T>
class TreeIteratorConst;

template <typename T>
class TreeIterator : public std::iterator<std::forward_iterator_tag,
                                          T,
                                          std::ptrdiff_t,
                                          T*,
                                          T&> {
    friend class TreeIteratorConst<T>;

public:
    TreeIterator() : node() { }

    explicit TreeIterator(Node<T>* n) : node(n) { }

    TreeIterator<T>& operator++() {
        if (node->threaded) {
            // The in-order successor is whatever is in the thread.
            node = node->thread.lock().get();
        } else if (node->right) {
            // The right node exists. The in-order successor is the left-most
            // node of the right child.
            node = node->right->getLeftmost();
        } else {
            // The current node is not threaded and its right child doesn't
            // exist. Therefore, the current node must be the last node in
            // the tree.
            node = nullptr;
        }

        return *this;
    }

    TreeIterator<T>& operator++(int) {
        TreeIterator<T> it(*this);
        operator++();

        return it;
    }

    T& operator*() const {
        return *node->value();
    }

    T* operator->() const {
        return node->value();
    }

    bool operator==(const TreeIterator<T>& rhs) const {
        return node == rhs.node;
    }

    bool operator!=(const TreeIterator<T>& rhs) const {
        return !operator==(rhs);
    }

private:
    Node<T>* node;
};

template <typename T>
class TreeIteratorConst : public std::iterator<std::forward_iterator_tag,
                                          T,
                                          std::ptrdiff_t,
                                          T*,
                                          T&> {
public:
    TreeIteratorConst() : node() { }

    explicit TreeIteratorConst(const TreeIterator<T>& iter)
            : node(iter.node) { }

    explicit TreeIteratorConst(const Node<T>* n) : node(n) { }

    TreeIteratorConst<T>& operator++() {
        if (node->threaded) {
            // The in-order successor is whatever is in the thread.
            node = node->thread.lock().get();
        } else if (node->right) {
            // The right node exists. The in-order successor is the left-most
            // node of the right child.
            node = node->right->getLeftmost();
        } else {
            // The current node is not threaded and its right child doesn't
            // exist. Therefore, the current node must be the last node in
            // the tree.
            node = nullptr;
        }

        return *this;
    }

    TreeIteratorConst<T>& operator++(int) {
        TreeIteratorConst<T> it(*this);
        operator++();

        return it;
    }

    const T& operator*() const {
        return *node->value();
    }

    const T* operator->() const {
        return node->value();
    }

    bool operator==(const TreeIteratorConst<T>& rhs) const {
        return node == rhs.node;
    }

    bool operator!=(const TreeIteratorConst<T>& rhs) const {
        return !operator==(rhs);
    }

private:
    const Node<T>* node;
};

#endif
