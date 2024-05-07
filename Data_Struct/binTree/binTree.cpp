/*








*/

#include "binTree.hpp"

template <typename T>
binTree<T>::binTree()
{
	this->root = new treeNode;
}

template <typename T>
Linked_list<T> *binTree<T>::preOrder()
{
	Linked_list<T> Traversal = new Linked_list<T>;
	preOrderTraversal(Traversal, root);
	return Traversal;
}

template <typename T>
Linked_list<T> *binTree<T>::inOrder()
{
	Linked_list<T> Traversal = new Linked_list<T>;
	inOrderTraversal(Traversal, root);
	return Traversal;
}

template <typename T>
Linked_list<T> *binTree<T>::postOrder()
{
	Linked_list<T> Traversal = new Linked_list<T>;
	postOrderTraversal(Traversal, root);
	return Traversal;
}

template <typename T>
void preOrderTraversal(Linked_list<T> *out, treeNode<T> *currentNode)
{
	out->push_back(currentNode->value);
	if (currentNode->left != nullptr)
	{
		preOrderTraversal(out, currentNode->left);
	}
	if (currentNode->right != nullptr)
	{
		preOrderTraversal(out, currentNode->right);
	}
}

template <typename T>
void inOrderTraversal(Linked_list<T> *out, treeNode<T> *currentNode)
{
	if (currentNode->left != nullptr)
	{
		preOrderTraversal(out, currentNode->left);
	}
	out->push_back(currentNode->value);
	if (currentNode->right != nullptr)
	{
		preOrderTraversal(out, currentNode->right);
	}
}

template <typename T>
void postOrderTraversal(Linked_list<T> *out, treeNode<T> *currentNode)
{
	if (currentNode->left != nullptr)
	{
		preOrderTraversal(out, currentNode->left);
	}
	if (currentNode->right != nullptr)
	{
		preOrderTraversal(out, currentNode->right);
	}
	out->push_back(currentNode->value);
}
