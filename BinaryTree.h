#ifndef BinaryTree_
#define BinaryTree_
#include <iostream>
template <class T>
class BinaryTreeNode
{
public:
	BinaryTreeNode() { LeftChild = RightChild = 0; }
	BinaryTreeNode(const T& d)
	{
		data = d;
		LeftChild = RightChild = 0;
	}
	BinaryTreeNode(const T& d, BinaryTreeNode *l, BinaryTreeNode *r)
	{
		data = d;
		LeftChild = l; RightChild = r;
	}
	~BinaryTreeNode() {}

	T data;
	BinaryTreeNode<T> *LeftChild, *RightChild;
};

template<class T>
class BinaryTree
{
public:
	// Constructors
	BinaryTree();
	BinaryTree(BinaryTreeNode<T> *u);
	//Destructor
	~BinaryTree();

	// Basic methods
	void MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right);
	bool IsEmpty() const;
	bool Root(T& x) const;
	void PostOrder(void(*Visit)(BinaryTreeNode<T> *u));
	void LevelOrder(void(*Visit)(BinaryTreeNode<T> *u));
	void BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right);
	void PreOrder(void(*Visit)(BinaryTreeNode<T> *u));
	void InOrder(void(*Visit)(BinaryTreeNode<T> *u));

	// my method
	T maxSecond();

private:
	BinaryTreeNode<T> *root;  // pointer to pointing to root
};

#endif
