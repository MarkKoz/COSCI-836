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
            node = node->right;
        } else if (node->right) {
            node = node->right->getLeftmost();
        } else {
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
            node = node->right;
        } else if (node->right) {
            node = node->right->getLeftmost();
        } else {
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
