#pragma once
#include "LinkedQueue.h"


struct BNode
{
	int data;
	BNode* leftChild;
	BNode* rightChild;
};

class BinaryTree
{
public:
	inline BNode* GetRoot() const { return this->root; }
public:
	void CreateBinaryTree();
	void PreOrderTraversal(BNode* root);
private:
	BNode* root;
};
