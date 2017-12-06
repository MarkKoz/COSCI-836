#ifndef LIST_HPP
#define LIST_HPP

#include <initializer_list>
#include <utility>

#include "ListIterator.hpp"
#include "Node.hpp"

template<typename T>
class List {
public:
    using iterator = ListIterator<T>;
    using const_iterator = ListIteratorConst<T>;

    /**
     * @brief Default constructor.
     *
     * Constructs an empty List.
     */
    List() : head() { }

    /**
     * @brief Copy constructor.
     *
     * @param   list
     */
    List(const List& list) : head() {
        initRange(list.begin(), list.end());
    }

    /**
     * @brief Move constructor.
     *
     * @param   list
     */
    List(List&& list) noexcept : head() {
        head.next = list.head.next; // "Steal" the front node of other list.
        list.head.next = nullptr; // Leave it in a valid but empty state.
    }

    /**
     * @brief Initialiser list constructor.
     *
     * Constructs a List containing copies of the elements in the
     * @c std::initializer_list.
     *
     * @param   init
     */
    List(std::initializer_list<T> init) : head() {
        initRange(init.begin(), init.end());
    }

    /**
     * @brief Destructor.
     */
    ~List() {
        Node<T>* curr = static_cast<Node<T>*>(head.next);

        while (curr != nullptr) {
            Node<T>* node = curr;
            // Get the next node before the current node is deleted.
            curr = static_cast<Node<T>*>(curr->next);
            delete node;
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
    iterator emplaceAfter(const_iterator pos, Args&& ... args) {
        NodeBase* nodePos = const_cast<NodeBase*>(pos.node);
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
        return new Node<T>(T(std::forward<Args>(args)...));
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
