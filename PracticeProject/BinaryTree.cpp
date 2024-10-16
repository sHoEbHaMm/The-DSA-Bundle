#include "BinaryTree.h"

void BinaryTree::CreateBinaryTree()
{
    LinkedQueue<BNode*> queue;

    BNode* currentNode;
    BNode* newNode;

    int temp = 0;

    cout << "Enter root value: ";
    root = new BNode();

    cin >> root->data;

    root->leftChild = NULL;
    root->rightChild = NULL;


    queue.Enqueue(root);


    while (!queue.bIsEmpty())
    {
        currentNode = queue.Dequeue();

        cout << "Enter left child [-1 if there is no left child]: ";
        cin >> temp;

        if (temp != -1)
        {
            newNode = new BNode();
            newNode->data = temp;
            newNode->leftChild = newNode->rightChild = nullptr;
            currentNode->leftChild = newNode;

            queue.Enqueue(newNode);
        }

        cout << "Enter right child [-1 if there is no right child]: ";
        cin >> temp;

        if (temp != -1)
        {
            newNode = new BNode();
            newNode->data = temp;
            newNode->leftChild = newNode->rightChild = nullptr;
            currentNode->rightChild = newNode;

            queue.Enqueue(newNode);
        }
        
    }
    return;
}

void BinaryTree::PreOrderTraversal(BNode* root)
{
    if(root != NULL)
    {
      cout << root->data << " ";
      PreOrderTraversal(root->leftChild);
      PreOrderTraversal(root->rightChild);
    }
}
