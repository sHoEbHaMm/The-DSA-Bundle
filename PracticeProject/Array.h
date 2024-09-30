#pragma once
#include "config.h"

class Array
{
public:
	

private:
	int m_size = 10;
	int m_array[10];
	int m_length = 0;

public:
	void Display();
	void Append(int i_element);
	void InsertAt(int index, int i_element);
	void Delete(int i_element);

	/* Algorithms */
	int linearSearch(int i_element);
	int binarySearch(int low, int high, int i_element);
	void Reverse();

	/* Helper functions */
	inline int GetLength() const { return this->m_length; }
	int GetAverage() const;
	int GetMax() const;
	int GetMin() const;
	bool isSorted() const;
};