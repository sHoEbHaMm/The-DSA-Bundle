#pragma once
#include "config.h"

struct Node
{
	int data;
	Node* nextNode;
	Node* prevNode;
};

class DoublyList
{
public:
	DoublyList()
	{
		head = NULL;
		length = 0;
	}

	~DoublyList()
	{
		Node* currentNode = head;
		while (currentNode != NULL) {
			Node* temp = currentNode;
			currentNode = currentNode->nextNode;
			delete temp;
		}
	}

private:
	Node* head;
	size_t length;

public:
	void InsertAtBeginning(int elementToInsert);
	void InsertAtEnd(int elementToInsert);
	void InsertAt(int index, int elementToInsert);

	int RemoveAt(int index);
	int RemoveFromBeginning();
	int RemoveFromEnd();

	void DisplayFromFront();
	void DisplayFromEnd();

	inline bool bIsEmpty() const { return (head == nullptr); }
};
