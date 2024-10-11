#include "SinglyList.h"

void SinglyList::InsertAtBeginning(int elementToInsert)
{
	Node* newNode = new Node();
	newNode->data = elementToInsert;

	newNode->nextNode = head;
	head = newNode;
	length++;

	return;
}

void SinglyList::InsertAt(int index, int data)
{
	int currentIndex = 0;

	/* If list is empty & index is anything but zero */
	if (bIsEmpty() && index != 0)
	{
		cout << "List is empty, enter at first index before entering a value at index: " << index << endl;
		return;
	}

	if (index == length)
	{
		Insert(data);
		return;
	}

	/* Example if index:5 and length:4 means index of last element is 3. No element can be entered at index 5 before 4 */
	if (index - length == 1)
	{
		cout << "Invalid index" << endl;
		return;
	}

	if (index == 0)
	{
		InsertAtBeginning(data);
		return;
	}

	Node* currentNode = head;
	Node* trailingNode = head;

	while (currentNode->nextNode != NULL)
	{
		currentIndex++;
		trailingNode = currentNode;
		currentNode = currentNode->nextNode;

		if (index == currentIndex)
		{
			Node* newNode = new Node();
			newNode->data = data;

			trailingNode->nextNode = newNode;
			newNode->nextNode = currentNode;

			return;
		}
	}
}

void SinglyList::Insert(int elementToInsert)
{
	/* If this is the first insertion in the List */
	if (head == nullptr)
	{
		Node* newNode = new Node();
		newNode->data = elementToInsert;
		
		head = newNode;
		newNode->nextNode = NULL;

		length++;

		return;
	}

	/* Else */
	Node* pNode = head;

	/* Reach the last node of the list */
	while (pNode->nextNode != NULL)
	{
		pNode = pNode->nextNode;
	}

	/* Attach the new node */
	Node* newNode = new Node();
	newNode->data = elementToInsert;

	pNode->nextNode = newNode;
	newNode->nextNode = NULL;

	length++;

	return;
}

int SinglyList::Remove(int elementToRemove)
{
	int outElement = 0;

	/* Check if the list is empty */
	if (bIsEmpty())
	{
		cout << "List empty" << endl;
		return -1;
	}

	/* Two pointer approach */
	Node* pNode = head;
	Node* trailingNode = head;

	/* Traverse the list to find if the element exists */
	while (pNode != NULL)
	{
		if (pNode->data == elementToRemove)
		{
			break;
		}
		trailingNode = pNode;
		pNode = pNode->nextNode;
	}

	/* Enters the if block only iff the element is found */
	if (pNode)
	{
		trailingNode->nextNode = pNode->nextNode;
		pNode->nextNode = NULL;
		outElement = pNode->data;
		delete pNode;
		length--;
		return outElement;
	}
	else
	{
		cout << "Element not found" << endl;
		return -1;
	}

}

int SinglyList::RemoveAt(int index)
{
	int outElement = 0;

	int currentIndex = 0;

	if (bIsEmpty() && index != 0)
	{
		cout << "List is already empty" << endl;
		return -1;
	}

	if (index > length - 1)
	{
		cout << "Invalid index" << endl;
		return -1;
	}

	if (index == 0)
	{
		Node* pNode = head;
		head = pNode->nextNode;
		outElement = pNode->data;
		delete pNode;
		length--;
		return outElement;
	}

	Node* currentNode = head;
	Node* trailingNode = head;

	while (currentNode->nextNode != NULL)
	{
		currentIndex++;
		trailingNode = currentNode;
		currentNode = currentNode->nextNode;

		if (index == currentIndex)
		{
			trailingNode->nextNode = currentNode->nextNode;
			currentNode->nextNode = NULL;
			outElement = currentNode->data;

			delete currentNode;
			length--;

			return outElement;
		}
	}
}

void SinglyList::Display() const
{
	/* Check if the list is empty */
	if (bIsEmpty())
	{
		cout << "List empty" << endl;
		return;
	}

	Node* pNode = head;

	/* Traverse the elements one by one and print them */
	while (pNode != NULL)
	{
		cout << pNode->data << " ";
		pNode = pNode->nextNode;
	}

	cout << endl;
}

bool SinglyList::bIsEmpty() const
{
	return (head == nullptr);
}
