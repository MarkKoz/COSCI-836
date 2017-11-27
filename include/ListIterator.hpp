#ifndef ASSIGNMENT_4_LISTITERATOR_HPP
#define ASSIGNMENT_4_LISTITERATOR_HPP

#include <cstddef>
#include <iterator>
#include <memory>

#include "Node.hpp"

template <typename T>
class ListIterator : public std::iterator<std::forward_iterator_tag,
                                          T,
                                          std::ptrdiff_t,
                                          T*,
                                          T&> {
public:
    ListIterator() : node() { }

    explicit ListIterator(NodeBase* n) : node(n) { }

    ListIterator<T>& operator++() {
        node = node->next;

        return *this;
    }

    ListIterator<T>& operator++(int) {
        ListIterator<T> it(*this);
        operator++();

        return it;
    }

    T& operator*() const {
        return *static_cast<Node<T>*>(node)->data();
    }

    T* operator->() const {
        return static_cast<Node<T>*>(node)->data();
    }

    bool operator==(const ListIterator<T>& rhs) const {
        return node == rhs.node;
    }

    bool operator!=(const ListIterator<T>& rhs) const {
        return !operator==(rhs);
    }

    NodeBase* node;
};

template <typename T>
class ListIteratorConst : public std::iterator<std::forward_iterator_tag,
                                               T,
                                               std::ptrdiff_t,
                                               const T*,
                                               const T&> {
public:
    ListIteratorConst() : node() { }

    explicit ListIteratorConst(const ListIterator<T> iter) : node(iter.node) { }

    explicit ListIteratorConst(const NodeBase* n) : node(n) { }


    ListIteratorConst<T>& operator++() {
        node = node->next;

        return *this;
    }

    ListIteratorConst<T>& operator++(int) {
        ListIteratorConst<T> it(*this);
        operator++();

        return it;
    }

    const T& operator*() const {
        return *static_cast<const Node<T>*>(node)->data();
    }

    const T* operator->() const {
        return static_cast<const Node<T>*>(node)->data();
    }

    bool operator==(const ListIteratorConst<T>& rhs) const {
        return node == rhs.node;
    }

    bool operator!=(const ListIteratorConst<T>& rhs) const {
        return !operator==(rhs);
    }

    const NodeBase* node;
};

#endif
