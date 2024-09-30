#include "Array.h"

void Array::Display()
{
	for (int i = 0; i < this->m_size; i++)
	{
		cout << this->m_array[i] << " ";
	}
}
