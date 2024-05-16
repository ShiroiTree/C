/*





*/

#include "Stack.hpp"

template <typename T>
Stack<T>::Stack()
{
    head = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    clear();
}

template <typename T>
void inline Stack<T>::push_back(T val)
{
    stackNode<T> *p1 = new stackNode<T>;
    p1->value = val;
    p1->next = head;
    this->head = p1;
}

template <typename T>
void inline Stack<T>::pop_back()
{
    if (this->head == nullptr)
    {
        return;
    }
    stackNode<T> *p1;
    p1 = this->head;
    p1 = p1->next;
    delete this->head;
    this->head = p1;
}

template <typename T>
T inline Stack<T>::back()
{
    return this->head->value;
}

template <typename T>
void inline Stack<T>::clear()
{
    while (!empty())
    {
        pop_back();
    }
}

template <typename T>
bool inline Stack<T>::empty()
{
    if (this->head == nullptr)
    {
        return true;
    }
    return false;
}