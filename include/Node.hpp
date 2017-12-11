#ifndef ASSIGNMENT_5_NODE_HPP
#define ASSIGNMENT_5_NODE_HPP

#include <memory>
#include <utility>

template<typename T>
class Node {
public:
    std::weak_ptr<Node<T>> thread = std::weak_ptr<Node<T>>();

    /**
     * Constructs a @c Node which stores a copy of the given @c value.
     *
     * @param   value   The data to store in the @c Node.
     */
    explicit Node(const T& value) : data(value) { }

    /**
     * Constructs a @c Node and moves the given @c value into its storage.
     *
     * @param   value   The data to store in the @c Node.
     */
    explicit Node(T&& value) : data(std::move(value)) { }

    /**
     * Finds the left-most child @c Node of the @c Node.
     *
     * @return          A pointer to the left-most child @c Node.
     */
    Node<T>* getLeftmost() {
        Node<T>* node = this;

        while (node->left) {
            node = node->left.get();
        }

        return node;
    }

    /**
     * Gets the address of the data stored in the @c Node.
     *
     * @return          A pointer to the data stored in the @c Node.
     */
    T* value() {
        return &data;
    }

    /**
     * Gets the address of the const-qualified data stored in the @c Node.
     *
     * @return          A pointer to the const-qualified data stored in the @c
     *                  Node.
     */
    const T* value() const {
        return &data;
    }

    /**
     * Retrieves a const-qualified l-value reference the the left child
     * pointer of the @c Node.
     *
     * @return          The left child.
     */
    const std::shared_ptr<Node<T>>& getLeft() const {
        return left;
    }

    /**
     * Sets the given @c child to be the left child of the @c Node.
     *
     * This transfers ownership of the child to the @c Node; the original child
     * pointer will no longer have ownership of the child @c Node or manage
     * any object.
     *
     * @param   child   The @c Node to be set as the left child.
     */
    void setLeft(std::unique_ptr<Node<T>>&& child) {
        left = std::move(child);
    }

    /**
     * Retrieves a const-qualified l-value reference the the right child
     * pointer of the @c Node.
     *
     * @return          The right child.
     */
    const std::shared_ptr<Node<T>>& getRight() const {
        return right;
    }

    /**
     * Sets the given @c child to be the right child of the @c Node and
     * un-flags the @c Node as being threaded.
     *
     * This transfers ownership of the child to the @c Node; the original child
     * pointer will no longer have ownership of the child @c Node or manage
     * any object.
     *
     * @param   child   The @c Node to be set as the right child.
     */
    void setRight(std::unique_ptr<Node<T>>&& child) {
        right = std::move(child);
        threaded = false;
    }

    /**
     * Sets the @c thread pointer of the @c Node.
     *
     * After this, the @c node pointer becomes empty and it's use count is 0.
     *
     * @param   node    The @c Node to be set as the thread.
     */
    void setThread(std::weak_ptr<Node<T>>&& node) {
        this->thread = node;
        threaded = true;
    }

    /**
     * Sets the @c thread pointer of the @c Node.
     *
     * The @c thread pointer will only hold a reference to the object managed
     * by @c node; it will @a not take or share ownership.
     *
     * @param   node    The @c Node to be set as the thread.
     */
    void setThread(const std::shared_ptr<Node<T>>& node) {
        this->thread = node;
        threaded = true;
    }

    /**
     * Determines if the @c Node is threaded.
     *
     * @return          @c true if threaded; @c false otherwise.
     */
    bool isThreaded() const {
        return threaded;
    }

private:
    T data;
    std::shared_ptr<Node<T>> left = nullptr;
    std::shared_ptr<Node<T>> right = nullptr;
    bool threaded = false;
};

#endif
