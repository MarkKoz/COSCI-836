#ifndef ASSIGNMENT_5_NODE_HPP
#define ASSIGNMENT_5_NODE_HPP

#include <memory>
#include <utility>

template<typename T>
class Node {
public:
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    bool threaded = false;

    explicit Node(const T& value) : data(value) { }

    explicit Node(T&& value) : data(std::move(value)) { }

    T* value() {
        return std::addressof(data);
    }

    const T* value() const {
        return std::addressof(data);
    }

    void setThread(Node<T>* thread) {
        right = thread;
        threaded = true;
    }

    Node<T>* getLeftmost() {
        Node<T>* node = this;

        while (node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

private:
    T data;
};

#endif
