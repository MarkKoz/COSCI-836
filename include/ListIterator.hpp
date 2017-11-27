#ifndef ASSIGNMENT_4_LISTITERATOR_HPP
#define ASSIGNMENT_4_LISTITERATOR_HPP

#include <cstddef>
#include <iterator>
#include <type_traits>

#include "List.hpp"

template <typename T>
class ListIterator : public std::iterator<std::input_iterator_tag,
                                          T,
                                          std::ptrdiff_t,
                                          T*,
                                          T&> {
public:
    ListIterator(T* pos, T* c, const std::size_t size) {

    }

    ListIterator& operator++() {
        node = node->next;

        return *this;
    }

    ListIterator& operator++(int) {
        ListIterator<T> it(*this);
        operator++();

        return it;
    }

    T& operator*() const {
        return std::addressof(static_cast<Node*>(node)->data());
    }

    T* operator->() const {
        return static_cast<Node*>(node)->data();
    }

    bool operator==(const ListIterator& rhs) const {
        return node == rhs.node;
    }

    bool operator!=(const ListIterator& rhs) const {
        return !operator==(rhs);
    }

private:
    NodeBase* node;
};

#endif
