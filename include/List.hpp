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
        head.next = list.head.next; // "Steal" the front node of other list.
        list.head.next = nullptr; // Leave it in a valid but empty state.
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

    /**
     * Destructor.
     */
    ~List() {
        Node<T>* curr = static_cast<Node<T>*>(head.next);

        while (curr != nullptr) {
            Node<T>* node = curr;
            // Get the next node before the current node is deleted.
            curr = static_cast<Node<T>*>(curr->next);

            node->data()->~T(); // Destroy the data.
            node->~Node<T>(); // Destroy the node.
            ::operator delete(node); // Deallocate memory.
        }

        head.next = nullptr;
    }

    /**
     * Inserts a copy of @a value after the position @a pos.
     *
     * @param   pos
     * @param   value
     * @return
     */
    iterator insertAfter(const_iterator pos, const T& value) {
        return emplaceAfter(pos, value);
    }

    /**
     * Inserts a new node after the position @a pos and moves @a value into
     * that node.
     *
     * @param   pos
     * @param   value
     * @return
     */
    iterator insertAfter(const_iterator pos, T&& value) {
        return emplaceAfter(pos, std::move(value));
    }

    /**
     * Constructs an object using the arguments @a args and inserts it after
     * the position @a pos.
     *
     * @tparam  Args
     * @param   pos
     * @param   args
     * @return
     */
    template<typename... Args>
    iterator emplaceAfter(const_iterator pos, Args&&... args) {
        Node<T>* nodePos = const_cast<Node<T>*>(pos.node);
        Node<T>* nodeNew = createNode(std::forward<Args>(args)...);

        nodeNew->next = nodePos->next;
        nodePos->next = nodeNew;

        return iterator(nodeNew);
    }

    T& front() {
        return *static_cast<Node<T>*>(head.next)->data();
    }

    const T& front() const {
        return *static_cast<Node<T>*>(head.next)->data();
    }

    bool empty() const { return head.next == nullptr; }

    iterator before_begin() { return iterator(&head); }

    iterator begin() { return iterator(head.next); }

    iterator end() { return iterator(nullptr); }

    const_iterator before_begin() const { return const_iterator(&head); }

    const_iterator begin() const { return const_iterator(head.next); }

    const_iterator end() const { return const_iterator(nullptr); }

    const_iterator cbefore_begin() const { return const_iterator(&head); }

    const_iterator cbegin() const { return const_iterator(head.next); }

    const_iterator cend() const { return const_iterator(nullptr); }

protected:
    NodeBase head;

private:
    template<typename... Args>
    Node<T>* createNode(Args&& ... args) {
        // Allocates memory for 1 node.
        Node<T>* node = static_cast<Node<T>*>(::operator new(sizeof(Node<T>)));

        try {
            ::new(static_cast<void*>(node)) Node<T>;
            ::new(static_cast<void*>(node->data())) T(std::forward<Args>(args)...);
        } catch(...) {
            ::operator delete(node);
            throw;
        }

        return node;
    }

    template<typename Iter>
    void initRange(Iter first, Iter last) {
        for (NodeBase* node = &head; first != last; ++first) {
            node->next = this->createNode(*first);
            node = node->next;
        }
    }
};

#endif
