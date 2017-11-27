#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include <new>
#include <type_traits>
#include <utility>

#include "ListIterator.hpp"
#include "Node.hpp"


template<typename T>
class List {
public:
    using iterator = ListIterator<T>;
    using const_iterator = ListIterator<const T>;

    List() : head() { }

private:
    NodeBase* head;
};

#endif
