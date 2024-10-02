#include "Stack.h"

void Stack::push(int i)
{
	if (top >= MAX_SIZE - 1)
	{
		cout << "Stack overflow exception for input: " << i << endl;
		return;
	}

	top++;
	contents[top] = i;
}

int Stack::pop()
{
	int o_element;

	if (top == -1)
	{
		cout << "Stack empty nothing to pop" << endl;
		return -1;
	}

	o_element = contents[top];
	top--;

	return o_element;
}

void Stack::peek()
{
	if (top == -1)
	{
		cout << "Stack empty nothing to peek" << endl;
		return;
	}

	cout << "Element at top: " << contents[top] << endl;
	return;
}

void Stack::Display()
{
	cout << "Elements in stack: ";
	for (int i = 0; i <= top; i++)
	{
		cout << contents[i] << " ";
	}
}
