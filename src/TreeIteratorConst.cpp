#include "Node.hpp"
#include "TreeIterator.hpp"

template<typename T>
TreeIteratorConst<T>::TreeIteratorConst() : node() { }

template<typename T>
TreeIteratorConst<T>::TreeIteratorConst(const TreeIterator<T>& iter)
        : node(iter.node) { }

template<typename T>
TreeIteratorConst<T>::TreeIteratorConst(const Node<T>* n) : node(n) { }

template<typename T>
TreeIteratorConst<T>& TreeIteratorConst<T>::operator++() {
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
TreeIteratorConst<T>& TreeIteratorConst<T>::operator++(int) {
    TreeIteratorConst<T> it(*this);
    operator++();

    return it;
}

template<typename T>
const T& TreeIteratorConst<T>::operator*() const {
    return *node->value();
}

template<typename T>
const T* TreeIteratorConst<T>::operator->() const {
    return node->value();
}

template<typename T>
bool TreeIteratorConst<T>::operator==(const TreeIteratorConst<T>& rhs) const {
    return node == rhs.node;
}

template<typename T>
bool TreeIteratorConst<T>::operator!=(const TreeIteratorConst<T>& rhs) const {
    return !operator==(rhs);
}
