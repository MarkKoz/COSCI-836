#include <memory>
#include <utility>

#include "Node.hpp"
#include "Tree.hpp"
#include "TreeIterator.hpp"

template<typename T>
bool Tree<T>::insert(const T& value) {
    return emplace(value);
}

template<typename T>
bool Tree<T>::insert(T&& value) {
    return emplace(std::move(value));
}

template<typename T>
template<typename... Args>
bool Tree<T>::emplace(Args&& ... args) {
    auto node = std::make_unique<Node<T>>(T(std::forward<Args>(args)...));

    if (empty()) {
        root = std::move(node);

        return true;
    } else {
        return insertNode(root, node);
    }
}

template<typename T>
bool Tree<T>::empty() const {
    return !root;
}

template<typename T>
typename Tree<T>::iterator Tree<T>::begin() {
    if (empty()) {
        return end();
    }

    return iterator(root->getRightmost());
}

template<typename T>
typename Tree<T>::iterator Tree<T>::end() {
    return iterator(nullptr);
}

template<typename T>
typename Tree<T>::const_iterator Tree<T>::begin() const {
    if (empty()) {
        return end();
    }

    return const_iterator(root->getRightmost());
}

template<typename T>
typename Tree<T>::const_iterator Tree<T>::end() const {
    return const_iterator(nullptr);
}

template<typename T>
typename Tree<T>::const_iterator Tree<T>::cbegin() const {
    if (empty()) {
        return cend();
    }

    return const_iterator(root->getRightmost());
}

template<typename T>
typename Tree<T>::const_iterator Tree<T>::cend() const {
    return const_iterator(nullptr);
}

template<typename T>
bool Tree<T>::insertNode(const std::shared_ptr<Node<T>>& parent,
                         std::unique_ptr<Node<T>>& node) {
    if (*parent->value() > *node->value()) { // Smaller values to the left.
        if (parent->getLeft()) {
            // The left node exists; start the search at the left node.
            return insertNode(parent->getLeft(), node);
        } else {
            // The left node doesn't exist; found the free position.
            // A left node's in-order successor is its parent's thread.
            node->setThread(parent->getThread());
            parent->setLeft(std::move(node)); // Inserts the node.

            return true;
        }
    } else if (*parent->value() < *node->value()) { // Larger go right.
        if (parent->getRight()) {
            // The right node exists; start the search at the right node.
            return insertNode(parent->getRight(), node);
        } else {
            // The right node doesn't exist; found the free position.
            // A right node's in-order successor is its parent.
            node->setThread(parent);
            parent->setRight(std::move(node)); // Inserts the node.

            return true;
        }
    } else { // Value is equal to the parent's value; no duplicates allowed.
        return false;
    }
}
