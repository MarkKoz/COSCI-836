#ifndef ASSIGNMENT_5_TREE_HPP
#define ASSIGNMENT_5_TREE_HPP

#include <memory>

#include "Node.hpp"
#include "TreeIterator.hpp"

/**
 * @brief A threaded binary search tree container.
 *
 * Each parent node can have up to two child nodes, left and right. The value of
 * the parent is greater than the left node's value and less than the right
 * node's value.
 *
 * @tparam  T       The type of the object to contain.
 */
template<typename T>
class Tree {
public:
    using iterator = TreeIterator<T>;
    using const_iterator = TreeIteratorConst<T>;

    /**
     * Constructs a new @c Node with a copy of @c value and inserts the node
     * into the container. If @c value already exists in the container, no
     * insertion takes place.
     *
     * @param   value   The data to store in the container.
     * @return          @c true if the insertion was successful; @c false
     *                  otherwise.
     */
    bool insert(const T& value);

    /**
     * Moves @c value into a new @c Node and inserts the node into the
     * container. If @c value already exists in the container, no
     * insertion takes place.
     *
     * @param   value   The data to store in the container.
     * @return          @c true if the insertion was successful; @c false
     *                  otherwise.
     */
    bool insert(T&& value);

    /**
     * Constructs an object using the arguments @c args, constructs a new
     * @c Node with that object, and inserts the node into the container. If
     * @c value already exists in the container, no insertion takes place.
     *
     * @tparam  Args    The types of the arguments.
     * @param   args    The arguments to forward to the object's constructor.
     * @return          @c true if the insertion was successful; @c false
     *                  otherwise.
     */
    template<typename... Args>
    bool emplace(Args&& ... args);

    /**
     * Checks if the container is empty i.e. contains no nodes.
     *
     * @return          @c true if empty; @c false otherwise.
     */
    bool empty() const;

    /**
     * Returns an iterator to the first element of the container.
     *
     * If the container is empty, the returned iterator will be equal to @c
     * end().
     *
     * @return          An iterator to the first element.
     */
    iterator begin();

    /**
     * Returns an iterator to the element following the last element of the
     * container (past-the-last).
     *
     * @return          An iterator to the past-the-last element.
     */
    iterator end();

    /**
     * Returns a const iterator to the first element of the container.
     *
     * If the container is empty, the returned iterator will be equal to @c
     * end().
     *
     * @return          A const-qualified iterator to the first element.
     */
    const_iterator begin() const;

    /**
     * Returns a const iterator to the element following the last
     * element of the container (past-the-last).
     *
     * @return          A const iterator to the past-the-last element.
     */
    const_iterator end() const;

    /**
     * Returns a const iterator to the first element of the container.
     *
     * If the container is empty, the returned iterator will be equal to @c
     * cend().
     *
     * @return          A const-qualified iterator to the first element.
     */
    const_iterator cbegin() const;

    /**
     * Returns a const iterator to the element following the last
     * element of the container (past-the-last).
     *
     * @return          A const iterator to the past-the-last element.
     */
    const_iterator cend() const;

protected:
    std::shared_ptr<Node<T>> root = nullptr;

private:
    /**
     * @brief Recursively finds the position at which @c node can be inserted
     * and then inserts @c node at that position.
     *
     * Searches for an empty child @c Node (@c left or @c right) depending on
     * the evaluation of the comparison between @c node's @c value and @c
     * parent's @c value. If the @c Node is occupied, the function is
     * recursively called starting at that occupied child @c Node.
     *
     * Once an empty position is found, @c node is inserted into that position.
     *
     * @param   parent  The @c Node at which to begin the search.
     * @param   node    The @c Node to be inserted.
     * @return          @c true if the insertion was successful; @c false
     *                  otherwise.
     */
    bool insertNode(const std::shared_ptr<Node<T>>& parent,
                    std::unique_ptr<Node<T>>& node);
};

#include "Tree.cpp"

#endif
