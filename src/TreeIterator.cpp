#include "Node.hpp"
#include "TreeIterator.hpp"

template <typename T>
TreeIterator<T>::TreeIterator() : node() { }

template <typename T>
TreeIterator<T>::TreeIterator(Node<T>* n) : node(n) { }

template<typename T>
TreeIterator<T>& TreeIterator<T>::operator++() {
    if (node->isThreaded()) {
        // The in-order successor is whatever is in the thread.
        node = node->getThread().lock().get();
    } else if (node->getLeft()) {
        // The left node exists. The in-order successor is the right-most
        // node of the left child.
        node = node->getLeft()->getRightmost();
    } else {
        // The current node is not threaded and its left child doesn't
        // exist. Therefore, the current node must be the last node in
        // the tree.
        node = nullptr;
    }

    return *this;
}

template<typename T>
TreeIterator<T>& TreeIterator<T>::operator++(int) {
    TreeIterator<T> it(*this);
    operator++();

    return it;
}

template<typename T>
T& TreeIterator<T>::operator*() const {
    return *node->value();
}

template<typename T>
T* TreeIterator<T>::operator->() const {
    return node->value();
}

template<typename T>
bool TreeIterator<T>::operator==(const TreeIterator<T>& rhs) const {
    return node == rhs.node;
}

template<typename T>
bool TreeIterator<T>::operator!=(const TreeIterator<T>& rhs) const {
    return !operator==(rhs);
}
