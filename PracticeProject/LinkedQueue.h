#pragma once
#include "config.h"

template <typename T>
struct Node
{
	T data;
	Node<T>* nextNode;
};


template <typename T>
class LinkedQueue
{
public:
	LinkedQueue()
	{
		front = rear = NULL;
	}

public:
	void Enqueue(T data);
	T Dequeue();
	void Display();
	inline bool bIsEmpty() const { return (front == NULL); }

private:
	Node<T>* front;
	Node<T>* rear;
};

template <typename T> void LinkedQueue<T>::Enqueue(T data)
{
	/* first element */
	if (front == NULL)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		newNode->nextNode = NULL;

		front = rear = newNode;
		return;
	}

	Node<T>* newNode = new Node<T>();
	newNode->data = data;

	rear->nextNode = newNode;
	rear = newNode;

	return;

}

template <typename T> T LinkedQueue<T>::Dequeue()
{
	T OutElement = 0;

	if (front == NULL)
	{
		cout << "Queue empty, nothing to dequeue!" << endl;
		return NULL;
	}

	Node<T>* temp = front;
	OutElement = temp->data;
	front = temp->nextNode;

	delete temp;

	return OutElement;
}

template <typename T> void LinkedQueue<T>::Display()
{
	if (front == NULL)
	{
		cout << "Queue empty, nothing to display!" << endl;
		return;
	}

	Node<T>* currentNode = front;

	while (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->nextNode;
	}

	cout << endl;
	return;
}