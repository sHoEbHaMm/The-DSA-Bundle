#pragma once
#include "config.h"

#define MAX_SIZE 5

class Stack
{
public:
	Stack()
	{
		top = -1;
	}

private:
	int contents[MAX_SIZE];
	int top;

public:
	void push(int i);
	int pop();
	void peek();
	void Display();
};
