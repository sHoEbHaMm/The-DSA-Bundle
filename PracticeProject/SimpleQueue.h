#pragma once
#include "config.h"

class SimpleQueue
{
public:
	SimpleQueue(int c)
	{
		front = 0;
		rear = -1;
		capacity = c;
		contents = new int[c];
	}

	~SimpleQueue()
	{
		delete[] contents;
	}

private:
	int* contents;
	int front, rear, capacity;

public:
	void enqueue(int i);
	int dequeue();
	void Display();

};