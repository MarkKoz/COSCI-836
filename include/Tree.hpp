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
 * @brief A binary search tree container.
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
    //using const_iterator = TreeIteratorConst<T>;

    /**
     * @brief Destructor.
     *
     * Destroys the container along with all of its nodes and the objects
     * they store.
     */
    ~Tree() {
        // TODO: Implement the destructor.
    }

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
    bool emplace(Args&&... args) {
        Node<T>* node = createNode(std::forward<Args>(args)...);

        if (empty()) {
            root = node;

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
        return root == nullptr;
    }

    iterator begin() const {
        return iterator(root->getLeftmost());
    }

    iterator end() const {
        return iterator(nullptr);
    }

protected:
    Node<T>* root = nullptr;

private:
    /**
     * Constructs an object using the arguments @c args and returns a new @c
     * Node constructed using that object.
     *
     * @tparam  Args    The types of the arguments.
     * @param   args    The arguments to forward to the object's constructor.
     * @return          The constructed @c Node.
     */
    template<typename... Args>
    Node<T>* createNode(Args&&... args) {
        return new Node<T>(T(std::forward<Args>(args)...));
    }

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
    bool insertNode(Node<T>* parent, Node<T>* node) {
        if (*parent->value() > *node->value()) { // Goes left.
            if (parent->left) { // Left node exists & is occupied.
                return insertNode(parent->left, node);
            } else { // Left node doesn't exist; found the free position.
                // The succeeding node for in-order traversal is the parent
                // of the left node.
                node->setThread(parent);
                parent->left = node; // Insert the node.

                return true;
            }
        } else if (*parent->value() < *node->value()) { // Goes right.
            // Checks if the right node exists i.e. it isn't null and it isn't
            // threaded.
            if (parent->right && !parent->threaded) {
                return insertNode(parent->right, node);
            } else {
                // The right node doesn't exist. Either its parent is the last
                // node or it is threaded.

                // Transfer parent's thread to the new node.
                node->setThread(parent->right);
                parent->threaded = false; // Parent isn't threaded anymore.
                parent->right = node; // Insert the node.

                return true;
            }
        } else { // Value is equal to the parent's value; no duplicates allowed.
            return false;
        }
    }
};

#endif
