#include <memory>
#include <utility>

#include "Node.hpp"

template<typename T>
Node<T>::Node(const T& value) : data(value) { }

template<typename T>
Node<T>::Node(T&& value) : data(std::move(value)) { }

template<typename T>
Node<T>* Node<T>::getRightmost() {
    Node<T>* node = this;

    while (node->right) {
        node = node->right.get();
    }

    return node;
}

template<typename T>
T* Node<T>::value() {
    return &data;
}

template<typename T>
const T* Node<T>::value() const {
    return &data;
}

template<typename T>
const std::shared_ptr<Node<T>>& Node<T>::getLeft() const {
    return left;
}

template<typename T>
void Node<T>::setLeft(std::unique_ptr<Node<T>>&& child) {
    left = std::move(child);
    threaded = false;
}

template<typename T>
const std::shared_ptr<Node<T>>& Node<T>::getRight() const {
    return right;
}

template<typename T>
void Node<T>::setRight(std::unique_ptr<Node<T>>&& child) {
    right = std::move(child);
}

template<typename T>
const std::weak_ptr<Node<T>> Node<T>::getThread() const {
    return thread;
}

template<typename T>
void Node<T>::setThread(const std::weak_ptr<Node<T>>& node) {
    this->thread = node;
    threaded = true;
}

template<typename T>
void Node<T>::setThread(const std::shared_ptr<Node<T>>& node) {
    this->thread = node;
    threaded = true;
}

template<typename T>
bool Node<T>::isThreaded() const {
    return threaded;
}
