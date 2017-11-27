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
    using const_iterator = ListIteratorConst<T>;

    /**
     * Default constructor. Constructs an empty List.
     */
    List() : head() { }

    /**
     * Copy constructor.
     *
     * @param   list
     */
    List(const List& list) : head() {
        initRange(list.begin(), list.end());
    }

    /**
     * Move constructor.
     *
     * @param   list
     */
    List(List&& list) noexcept : head() {
        head->next = list.head->next; // "Steal" the front node of other list.
        list.head->next = nullptr; // Leave it in a valid but empty state.
    }

    /**
     * Initialiser list constructor. Constructs a List containing copies of
     * the elements in the std::initializer_list.
     *
     * @param   init
     */
    List(std::initializer_list<T> init) : head() {
        initRange(init.begin(), init.end());
    }

    ~List() {
        // TODO: Implement.
    }

    T& front() {
        return *static_cast<Node<T>*>(head->next)->data();
    }

    const T& front() const {
        return *static_cast<Node<T>*>(head->next)->data();
    }

    bool empty() const { return head->next == nullptr; }

    iterator before_begin() { return iterator(head); }

    iterator begin() { return iterator(head->next); }

    iterator end() { return iterator(nullptr); }

    const_iterator before_begin() const { return const_iterator(head); }

    const_iterator begin() const { return const_iterator(head->next); }

    const_iterator end() const { return const_iterator(nullptr); }

    const_iterator cbefore_begin() const { return const_iterator(head); }

    const_iterator cbegin() const { return const_iterator(head->next); }

    const_iterator cend() const { return const_iterator(nullptr); }

private:
    NodeBase* head;

    template<typename Iterator>
    void initRange(Iterator first, Iterator last) {
        for (NodeBase* node = head; first != last; ++first) {
            node->next = this->createNode(*first);
            node = node->next;
        }
    }
};

#endif
