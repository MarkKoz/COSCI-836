#include <type_traits>
#include <memory>
#include <new>
#include <utility>
#include <type_traits>

class NodeBase {
public:
    NodeBase() = default;

    NodeBase* next = nullptr;
};

template<typename T>
class Node : NodeBase {
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

template<typename T>
class List {
public:
   List() : head() { };


private:
    NodeBase* head;
};
