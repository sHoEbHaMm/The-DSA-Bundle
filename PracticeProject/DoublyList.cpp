#include "DoublyList.h"

void DoublyList::InsertAtBeginning(int elementToInsert)
{
	if (bIsEmpty())
	{
		Node* newNode = new Node();
		newNode->data = elementToInsert;
		newNode->prevNode = NULL;
		newNode->nextNode = NULL;

		head = newNode;
		return;
	}

	Node* newNode = new Node();
	newNode->data = elementToInsert;

	newNode->nextNode = head;
	newNode->prevNode = NULL;
	head->prevNode = newNode;
	head = newNode;

	length++;

	return;
}

void DoublyList::InsertAtEnd(int elementToInsert)
{
	if (bIsEmpty())
	{
		InsertAtBeginning(elementToInsert);
		return;
	}

	Node* currentNode = head;

	while (currentNode->nextNode != NULL)
	{
		currentNode = currentNode->nextNode;
	}

	Node* newNode = new Node();
	newNode->data = elementToInsert;

	currentNode->nextNode = newNode;
	newNode->prevNode = currentNode;
	newNode->nextNode = NULL;
	length++;

	return;
}

void DoublyList::InsertAt(int index, int elementToInsert)
{
	size_t currentIndex = 0;

	if (bIsEmpty() && index != 0)
	{
		cout << "List is empty, insert from the beginnning" << endl;
		return;
	}

	if (index == length)
	{
		InsertAtEnd(elementToInsert);
		return;
	}

	if (index - length == 1)
	{
		cout << "Invalid index, insert at previous index before inserting element at index: " << index << endl;
		return;
	}

	Node* currentNode = head;

	while (currentNode->nextNode != NULL)
	{
		currentIndex++;
		currentNode = currentNode->nextNode;

		if (index == currentIndex)
		{
			Node* newNode = new Node();
			newNode->data = elementToInsert;

			currentNode->prevNode->nextNode = newNode;
			newNode->prevNode = currentNode->prevNode;
			newNode->nextNode = currentNode;
			currentNode->prevNode = newNode;

			return;
		}
	}
}

int DoublyList::RemoveAt(int index)
{
	int outElement = 0;
	size_t currentIndex = 0;

	if (index == 0)
	{
		return RemoveFromBeginning();	
	}

	if (index == length - 1)
	{
		return RemoveFromEnd();
	}

	if (index - length == 1)
	{
		cout << "Invalid index, can't perform remove at index: " << index << endl;
		return -1;
	}

	Node* currentNode = head;

	while (currentNode->nextNode != NULL)
	{
		currentIndex++;
		currentNode = currentNode->nextNode;

		if (index == currentIndex)
		{
			currentNode->prevNode->nextNode = currentNode->nextNode;
			currentNode->nextNode->prevNode = currentNode->prevNode;
			outElement = currentNode->data;
			delete currentNode;

			length--;

			return outElement;
		}

	}
}

int DoublyList::RemoveFromBeginning()
{
	int outElement = 0;

	if (bIsEmpty())
	{
		if (bIsEmpty())
		{
			cout << "List empty, nothing to remove" << endl;
			return -1;
		}
	}

	Node* currentNode = head;

	head = currentNode->nextNode;
	head->prevNode = NULL;
	currentNode->nextNode = NULL;
	outElement = currentNode->data;
	delete currentNode;

	length--;

	return outElement;
}

int DoublyList::RemoveFromEnd()
{
	int outElement = 0;

	if (bIsEmpty())
	{
		cout << "List empty, nothing to display" << endl;
		return -1 ;
	}

	Node* currentNode = head;

	while (currentNode->nextNode != NULL)
	{
		currentNode = currentNode->nextNode;
	}

	currentNode->prevNode->nextNode = NULL;
	currentNode->prevNode = NULL;
	outElement = currentNode->data;
	delete currentNode;

	length--;

	return outElement;
}

void DoublyList::DisplayFromFront()
{
	if (bIsEmpty())
	{
		cout << "List empty, nothing to display" << endl;
		return;
	}

	Node* currentNode = head;

	while (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->nextNode;
	}

	cout << endl;
	return;
}

void DoublyList::DisplayFromEnd()
{
	if (bIsEmpty())
	{
		cout << "List empty, nothing to display" << endl;
		return;
	}

	Node* currentNode = head;

	while (currentNode->nextNode != NULL)
	{
		currentNode = currentNode->nextNode;
	}

	while (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->prevNode;
	}

	cout << endl;
	return;
}
