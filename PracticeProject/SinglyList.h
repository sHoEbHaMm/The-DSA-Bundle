#pragma once
#include "config.h"

struct Node
{
	int data;
	Node* nextNode;
};

class SinglyList
{
public:
	SinglyList()
	{
		head = nullptr;
		length = 0;
	}

	~SinglyList()
	{
		Node* current = head;
		while (current != nullptr) {
			Node* temp = current;
			current = current->nextNode;
			delete temp;
		}
	}

private:
	Node* head;
	size_t length;

public:
	void InsertAtBeginning(int elementToInsert);
	void InsertAt(int index, int elementToInsert);
	void Insert(int elementToInsert);

	int Remove(int elementToRemove);
	int RemoveAt(int index);

	void Display() const;

	bool bIsEmpty() const;

};
