#ifndef ASSIGNMENT_5_TREE_HPP
#define ASSIGNMENT_5_TREE_HPP

#include <utility>

#include "Node.hpp"
#include "TreeIterator.hpp"

struct Person {
    std::string name;
    unsigned long bribe;

    bool operator<(const Person& rhs) const {
       return bribe < rhs.bribe;
    }

    bool operator>(const Person& rhs) const {
        return rhs < *this;
    }
};

/**
 * @brief A threaded binary search tree container.
 *
 * Each parent node can have up to two child nodes, left and right. The value of
 * the parent is greater than the left node's value and less than the right
 * node's value.
 *
 * @tparam  T       The type of the object to contain.
 */
template<typename T>
class Tree {
public:
    using iterator = TreeIterator<T>;
    using const_iterator = TreeIteratorConst<T>;

    /**
     * Constructs a new @c Node with a copy of @c value and inserts the node
     * into the container. If @c value already exists in the container, no
     * insertion takes place.
     *
     * @param   value   The data to store in the container.
     * @return          @c true if the insertion was successful; @c false
     *                  otherwise.
     */
    bool insert(const T& value) {
        return emplace(value);
    }

    /**
     * Moves @c value into a new @c Node and inserts the node into the
     * container. If @c value already exists in the container, no
     * insertion takes place.
     *
     * @param   value   The data to store in the container.
     * @return          @c true if the insertion was successful; @c false
     *                  otherwise.
     */
    bool insert(T&& value) {
        return emplace(std::move(value));
    }

    /**
     * Constructs an object using the arguments @c args, constructs a new
     * @c Node with that object, and inserts the node into the container. If
     * @c value already exists in the container, no insertion takes place.
     *
     * @tparam  Args    The types of the arguments.
     * @param   args    The arguments to forward to the object's constructor.
     * @return          @c true if the insertion was successful; @c false
     *                  otherwise.
     */
    template<typename... Args>
    bool emplace(Args&& ... args) {
        auto node = std::make_unique<Node<T>>(T(std::forward<Args>(args)...));

        if (empty()) {
            root = std::move(node);

            return true;
        } else {
            return insertNode(root, node);
        }
    }

    /**
     * Checks if the container is empty i.e. contains no nodes.
     *
     * @return          @c true if empty; @c false otherwise.
     */
    bool empty() const {
        return !root;
    }

    iterator begin() {
        return iterator(root->getLeftmost());
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator begin() const {
        return const_iterator(root->getLeftmost());
    }

    const_iterator end() const {
        return const_iterator(nullptr);
    }

    const_iterator cbegin() const {
        return const_iterator(root->getLeftmost());
    }

    const_iterator cend() const {
        return const_iterator(nullptr);
    }

protected:
    std::shared_ptr<Node<T>> root = nullptr;

private:
    /**
     * @brief Recursively finds the position at which @c node can be inserted
     * and then inserts @c node at that position.
     *
     * Searches for an empty child @c Node (@c left or @c right) depending on
     * the evaluation of the comparison between @c node's @c value and @c
     * parent's @c value. If the @c Node is occupied, the function is
     * recursively called starting at that occupied child @c Node.
     *
     * Once an empty position is found, @c node is inserted into that position.
     *
     * @param   parent  The @c Node at which to begin the search.
     * @param   node    The @c Node to be inserted.
     * @return          @c true if the insertion was successful; @c false
     *                  otherwise.
     */
    bool insertNode(std::shared_ptr<Node<T>>& parent,
                    std::unique_ptr<Node<T>>& node) {
        if (*parent->value() > *node->value()) { // Smaller values to the left.
            if (parent->left) {
                // The left node exists; start the search at the left node.
                return insertNode(parent->left, node);
            } else {
                // The left node doesn't exist; found the free position.
                // A left node's in-order successor is its parent.
                // parent's shared_ptr is shared with thread's weak_ptr; no
                // transfer of ownership occurs.
                node->thread = parent;
                node->threaded = true;

                // Inserts the node. Transfers ownership from unique_ptr (node)
                // to the shared_ptr (left). The unique_ptr manages no object
                // afterwards.
                parent->left = std::move(node);

                return true;
            }
        } else if (*parent->value() < *node->value()) { // Larger go right.
            if (parent->right) {
                // The right node exists; start the search at the right node.
                return insertNode(parent->right, node);
            } else {
                // The right node doesn't exist; found the free position.
                // A right node's in-order successor is its parent's thread.
                // Both threads are weak_ptrs; no transfer of ownership occurs.
                node->thread = parent->thread;
                node->threaded = true;

                // Inserts the node. Transfers ownership from unique_ptr (node)
                // to the shared_ptr (right). The unique_ptr manages no object
                // afterwards.
                parent->right = std::move(node);
                parent->threaded = false; // Parent isn't threaded anymore.

                return true;
            }
        } else { // Value is equal to the parent's value; no duplicates allowed.
            return false;
        }
    }
};

#endif
