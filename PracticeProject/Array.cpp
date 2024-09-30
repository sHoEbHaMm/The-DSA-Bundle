#include "Array.h"

void Array::Display()
{
	for (int i = 0; i < m_length; i++)
	{
		cout << m_array[i] << " ";
	}
}

void Array::Append(int i_element)
{
	if (m_length >= m_size)
	{
		cout << "\nArray full! cannot add: " << i_element << endl;
		return;
	}

	m_array[m_length] = i_element;
	m_length++;
}

void Array::InsertAt(int index, int i_element)
{

	if (index >= 0 && index <= m_length)
	{
		for (int i = m_length; i > index; i--)
		{
			m_array[i] = m_array[i - 1];
		}
		m_array[index] = i_element;
		m_length++;
	}
	else
	{
		cout << "\nOut of bounds exception " << i_element << endl;
		return;
	}

}

void Array::Delete(int i_element)
{
	int o_element;

	for (int i = 0; i <= m_length; i++)
	{
		if (m_array[i] == i_element)
		{
			if (i == m_length)
			{
				o_element = m_array[i];
				m_length--;
				return;
			}
			else
			{
				o_element = m_array[i];
				
				for (int j = i; i < m_length; i++)
				{
					m_array[i] = m_array[i + 1];
				}
				m_length--;
				return;
			}
		}
	}

	cout << "Element not found" << endl;
	return;

}

int Array::linearSearch(int i_element)
{
	for (int i = 0; i < m_length; i++)
	{
		if (m_array[i] == i_element)
			return 1;
	}
	return -1;
}

int Array::binarySearch(int low, int high, int i_element)
{
	if (high < low)
		return -1;

	int mid = (low + high) / 2;

	if (m_array[mid] == i_element)
		return mid;
	else
	{
		if (i_element < m_array[mid])
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
		else if (i_element > m_array[mid])
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
		binarySearch(low, high, i_element);
	}
}

void Array::Reverse()
{
	int temp = 0;
	int i = 0, j = m_length - 1;

	while (j > i)
	{
		temp = m_array[i];
		m_array[i] = m_array[j];
		m_array[j] = temp;
		i++;
		j--;
	}
}

int Array::GetAverage() const
{
	int sum = 0;

	for (int i = 0; i < m_length; i++)
	{
		sum += m_array[i];
	}

	return sum/m_length;
}

int Array::GetMax() const
{
	int max = m_array[0];

	for (int i = 1; i < m_length; i++)
	{
		if (m_array[i] > max)
			max = m_array[i];
	}

	return max;
}

int Array::GetMin() const
{
	int min = m_array[0];

	for (int i = 1; i < m_length; i++)
	{
		if (m_array[i] < min)
			min = m_array[i];
	}

	return min;
}

bool Array::isSorted() const
{
	for (int i = 0; i < m_length - 1; i++)
	{
		if (m_array[i] > m_array[i + 1])
			return false;
	}
	return true;
}
