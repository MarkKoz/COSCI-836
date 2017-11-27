#ifndef ASSIGNMENT_4_NODE_HPP
#define ASSIGNMENT_4_NODE_HPP

#include <type_traits>

class NodeBase {
public:
    NodeBase() = default;

    NodeBase* next = nullptr;
};

template<typename T>
class Node : public NodeBase {
public:
    Node() = default;

    T* data() {
        return reinterpret_cast<T*>(&storage);
    }

    const T* data() const {
        return reinterpret_cast<const T*>(&storage);
    }

private:
    typename std::aligned_storage<sizeof(T), std::alignment_of<T>::value>::type storage;
};

#endif
