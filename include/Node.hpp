#ifndef ASSIGNMENT_5_NODE_HPP
#define ASSIGNMENT_5_NODE_HPP

#include <memory>
#include <utility>

template<typename T>
class Node {
public:
    std::shared_ptr<Node<T>> left = nullptr;
    std::shared_ptr<Node<T>> right = nullptr;
    std::weak_ptr<Node<T>> thread = std::weak_ptr<Node<T>>();
    bool threaded = false;

    explicit Node(const T& value) : data(value) { }

    explicit Node(T&& value) : data(std::move(value)) { }

    T* value() {
        return &data;
    }

    const T* value() const {
        return &data;
    }

    Node<T>* getLeftmost() {
        Node<T>* node = this;

        while (node->left) {
            node = node->left.get();
        }

        return node;
    }

private:
    T data;
};

#endif
