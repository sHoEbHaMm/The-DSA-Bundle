#pragma once
#include "config.h"

class Array
{
public:
	Array(int size)
	{
		this->m_size = size;
		this->m_array = new int[m_size];
		this->m_length = 0;
	}

	~Array()
	{
		delete this->m_array;
	}

public:
	int* m_array;
	int m_size;
	int m_length;

	void Display();
};