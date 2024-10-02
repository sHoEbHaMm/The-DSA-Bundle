#include "SimpleQueue.h"

void SimpleQueue::enqueue(int i)
{
	if (rear == capacity - 1)
	{
		cout << "Queue is full, can't enqueue: " << i << endl;
		return;
	}

	rear++;
	contents[rear] = i;
}

int SimpleQueue::dequeue()
{
	int o_element;

	if (front > rear)
	{
		cout << "Queue is empty, can't dequeue" << endl;
		return -1;
	}
	
	o_element = contents[front];

	for (int i = 0; i < rear; i++)
	{
		contents[i] = contents[i + 1];
	}
	rear--;

	return o_element;
}

void SimpleQueue::Display()
{
	if (front > rear)
	{
		cout << "Queue is empty" << endl;
		return;
	}


	cout << "Elements in the Queue: ";
	
	for (int i = front; i <= rear; i++)
	{
		cout << contents[i] << " ";
	}
}
