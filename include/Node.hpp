#ifndef ASSIGNMENT_4_NODE_HPP
#define ASSIGNMENT_4_NODE_HPP

class NodeBase {
public:
    NodeBase() = default;

    NodeBase* next = nullptr;
};

template<typename T>
class Node : public NodeBase {
public:
    explicit Node(const T& val) : val(val) { }

    explicit Node(T&& val) : val(std::move(val)) { }

    ~Node() = default;

    T* data() {
        return std::addressof(val);
    }

    const T* data() const {
        return std::addressof(val);
    }

private:
    T val;
};

#endif
