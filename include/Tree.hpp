#ifndef ASSIGNMENT_5_TREE_HPP
#define ASSIGNMENT_5_TREE_HPP

#include <memory>
#include <utility>

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

template<typename T>
class Node {
public:
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;

    explicit Node(const T& value) : data(value) { }

    explicit Node(T&& value) : data(std::move(value)) { }

    T* value() {
        return std::addressof(data);
    }

    const T* value() const {
        return std::addressof(data);
    }

private:
    T data;
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
        } else {
            Node<T>** pos = getPos(root, node->value());

            if (!pos) { // nullptr means value is a duplicate.
                return false;
            }

            *pos = node;
        }

        return true;
    }

    /**
     * Checks if the container is empty i.e. contains no nodes.
     *
     * @return          @c true if empty; @c false otherwise.
     */
    bool empty() {
        return root == nullptr;
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
     * @brief Finds the position at which a new @c Node should be inserted using
     * recursion.
     *
     * Searches for an empty child @c Node (@c left or @c right) depending on
     * the evaluation of the comparison between @c value and the @c parent's
     * @c value. If the @c Node is not empty, the function is recursively called
     * starting at that occupied child @c Node.
     *
     * @param   parent  The @c Node at which to begin the search.
     * @param   value   The value of the @c Node to be inserted.
     * @return          A pointer to an empty child @c Node pointer or @c
     *                  nullptr if @c value already exists in the container.
     */
    Node<T>** getPos(Node<T>* parent, const T* value) {
        if (*parent->value() > *value) { // Goes left.
            if (parent->left) { // Left node exists.
                return getPos(parent->left, value);
            } else { // Left node doesn't exist.
                return std::addressof(parent->left);
            }
        } else if (*parent->value() < *value) { // Goes right.
            if (parent->right) { // Right node exists.
                return getPos(parent->right, value);
            } else { // Right node doesn't exist.
                return std::addressof(parent->right);
            }
        } else { // Value is equal to the parent's value; no duplicates allowed.
            return nullptr;
        }
    }
};

#endif
