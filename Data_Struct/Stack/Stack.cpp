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
    stackNode<T> p1 = new stackNode;
    p1.value = val;
    p1.next = nullptr;
    this->head = p1;
}

template <typename T>
void inline Stack<T>::pop_back()
{
    if (this->head == nullptr)
    {
        return;
    }
    stackNode<T> p1;
    p1 = this->head;
    p1 = p1.next;
    delete this->head;
    this->head = p1;
}

template <typename T>
T inline Stack<T>::back()
{
    return this->head->value;
}

template <typename T>
void Stack<T>::clear()
{
    stackNode<T> *p1;
    p1 = this->head;
    while (p1->next != nullptr)
    {
        p1 = p1->next;
        delete p1->pre;
    }
    delete p1;
    this->head = nullptr;
}

template <typename T>
bool Stack<T>::empty()
{
    if (this->head == nullptr)
    {
        return true;
    }
    return false;
}