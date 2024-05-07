/*






*/

#ifndef _BINTREE_HPP_
#define _BINTREE_HPP_

#include "../Linked_list/Linked_list.hpp"

template <typename T>
struct treeNode
{
    treeNode() : root(nullptr), leftChild(nullptr), rightChild(nullptr) {}
    struct treeNode *root, *leftChild, *rightChild;
    T value;
};

template <typename T>
class binTree
{
public:
    binTree();
    ~binTree();
    //

    // Traversal
    Linked_list<T> *preOrder();
    Linked_list<T> *inOrder();
    Linked_list<T> *postOrder();

    //

private:
    treeNode<T> *root;
};

template <typename T>
void preOrderTraversal(Linked_list<T> *out, treeNode<T> *currentNode);

template <typename T>
void inOrderTraversal(Linked_list<T> *out, treeNode<T> *currentNode);

template <typename T>
void postOrderTraversal(Linked_list<T> *out, treeNode<T> *currentNode);

#endif
