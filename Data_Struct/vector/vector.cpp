#include<iostream>

/*
*
* The Vector.cpp are going to rebuilt the vector in stl with template class
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


typedef unsigned int size_T;

template<typename T>
class Vector
{
public:
	//
	Vector();
	Vector(int len);
	~Vector();

	void push_back(T value);
	void pop_back();

	void setVal(int pos, T value);
	T back();
	T getVal(int pos);// operator []

	bool empty();
	void clear();

	T *begin();
	T *end();

private:
	T* m_Data;
	size_T m_Size, m_tailptr;

	void sizeIncrease();
};

template<typename T> 
Vector<T>::Vector()
{
	this->m_Data = new T[2];
	this->m_Size = 2;
	this->m_tailptr = -1;
}

template<typename T>
Vector<T>::Vector(int len)
{
	if(len<0)
	{
		exit(0);
	}
	else if (len == 0)
	{
		this->m_Data = new T[1];
		this->m_Size = 1;
		this->m_tailptr = -1;
	}
	this->m_Data = new T[len];
	this->m_Size = len;
	this->m_tailptr = -1;
}

template<typename T>
Vector<T>::~Vector()
{
	delete this->m_Data;
}

template<typename T>
void Vector<T>::sizeIncrease()
{
	size_T new_Size = this->m_Size + this->m_Size / 2;
	T *new_Data = new T[new_Size];
	T *raw_Data = this->m_Data;
	// dataCopy(this->m_Data, new_Data, m_Size);
	for (int i = 0; i <= this->m_tailptr; i++)
	{
		new_Data[i] = raw_Data[i];
	}
	delete raw_Data;
	this->m_Size = new_Size;
	this->m_Data = new_Data;
}

template<typename T>
void Vector<T>::push_back(T value)
{
	if (this->m_tailptr == this->m_Size - 1)
	{
		sizeIncrease();
	}
	this->m_tailptr++;
	this->m_Data[this->m_tailptr] = value;
}

template<typename T>
void Vector<T>::pop_back()
{
	if (this->m_tailptr == -1)
	{
		return;
	}
	this->m_tailptr--;
}

template<typename T>
bool Vector<T>::empty()
{
	if (this->m_tailptr == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void Vector<T>::clear()
{
	this->m_tailptr = -1;
}

template<typename T>
T Vector<T>::back()
{
	return this->m_Data[this->m_tailptr];
}

template <typename T>
void Vector<T>::setVal(int pos, T value)
{
	if (pos >= m_Data || pos < 0)
	{
		exit(0);
	}
	this->m_Data[pos] = value;
}

template <typename T>
T Vector<T>::getVal(int pos)
{
	if (pos >= m_Data || pos < 0)
	{
		exit(0);
	}
	return this->m_Data[pos];
}

template <typename T>
T *Vector<T>::begin()
{
	return this->m_Data;
}

template <typename T>
T *Vector<T>::end()
{
	return &this->m_Data[this->m_tailptr];
}

int main()
{
	Vector<int> a;
	for (int i = 0; i <= 50; i++)
	{
		//std::cout << i << ' ';
		a.push_back(i);
		//std::cout << a.back() << ' ';
	}
	while (!a.empty())
	{
		std::cout << a.back() << ' ';
		a.pop_back();
	}
}