/*
*
* The List.cpp are going to rebuilt the vector in stl with template class
* error
*
*
*
*
*/

/*
memory management
data copy


*/
#include "List.hpp"

template<typename T>
List<T>::List()
{
	this->m_Data = new T[2];
	this->m_Size = 2;
	this->m_tailptr = 0;
}

template<typename T>
List<T>::List(size_T len)
{
	if(len<0)
	{
		exit(0);
	}
	else if (len == 1 || len == 0)
	{
		this->m_Data = new T[2];
		this->m_Size = 2;
		this->m_tailptr = 0;
	}
	this->m_Data = new T[len];
	this->m_Size = len;
	this->m_tailptr = 0;
}

template<typename T>
List<T>::~List()
{
	delete this->m_Data;
}

template<typename T>
void List<T>::sizeIncrease()
{
	size_T new_Size = this->m_Size + this->m_Size / 2;
	T *new_Data = new T[new_Size];
	T *raw_Data = this->m_Data;
	// dataCopy(this->m_Data, new_Data, m_Size);
	for (size_T i = 1; i <= this->m_tailptr; i++)
	{
		new_Data[i] = raw_Data[i];
	}
	delete raw_Data;
	this->m_Size = new_Size;
	this->m_Data = new_Data;
}

template<typename T>
void List<T>::push_back(T value)
{
	if (this->m_tailptr == this->m_Size - 1)
	{
		sizeIncrease();
	}
	this->m_tailptr++;
	this->m_Data[this->m_tailptr] = value;
}

template<typename T>
void List<T>::pop_back()
{
	if (this->m_tailptr == 0)
	{
		return;
	}
	this->m_tailptr--;
}

template<typename T>
bool inline List<T>::empty()
{
	if (this->m_tailptr == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void inline List<T>::clear()
{
	this->m_tailptr = 0;
}

template<typename T>
T inline List<T>::back()
{
	return this->m_Data[this->m_tailptr];
}

template <typename T>
void List<T>::setVal(size_T pos, T value)
{
	if (pos >= m_Size - 1 || pos <= 0)
	{
		exit(0);
	}
	this->m_Data[pos] = value;
}

template <typename T>
T List<T>::getVal(size_T pos)
{
	if (pos >= m_Size - 1 || pos <= 0)
	{
		exit(0);
	}
	return this->m_Data[pos];
}

template <typename T>
T *List<T>::begin()
{
	return this->m_Data;
}

template <typename T>
T *List<T>::end()
{
	return &this->m_Data[this->m_tailptr];
}

template class List<char>;
template class List<unsigned char>;
template class List<short>;
template class List<unsigned short>;
template class List<int>;
template class List<unsigned int>;
template class List<float>;
template class List<double>;
