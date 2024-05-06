/*




*/

#include "Linked_list.hpp"

template <typename T>
Linked_list<T>::Linked_list()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
Linked_list<T>::Linked_list(int length)
{
    if (length < 0)
    {
        return;
    }
    listNode<T> *p1, *p2;
    p1 = new listNode<T>;
    p1->pre = nullptr;
    head = p1;
    for (int i = 1; i <= length; i++)
    {
        p2 = new listNode<T>;
        p1->next = p2;
        p2->pre = p1;
        p1 = p2;
    }
    this->tail = p1;
    this->tail->next = nullptr;
}

template <typename T>
Linked_list<T>::Linked_list(const Linked_list<T> &copyFrom)
{
    listNode<T> *p_copy = copyFrom.head;
    listNode<T> *p1, *p2;
    p1 = new listNode<T>;
    p1->pre = nullptr;
    p1->value = p_copy->value;
    this->head = p1;
    while (p_copy->next != nullptr)
    {
        p_copy = p_copy->next;
        p2 = new listNode<T>;
        p2->pre = p1;
        p2->value = p_copy->value;
        p1 = p2;
    }
    this->tail = p1;
    this->tail->next = nullptr;
}


template <typename T>
Linked_list<T>::~Linked_list()
{
    listNode<T> *p1;
    p1 = this->head;
    while (p1->next != nullptr)
    {
        p1 = p1->next;
        delete p1->pre;
    }
    delete p1;
}

template <typename T>
void Linked_list<T>::insert(int pos, T val)
{
    switch (pos)
    {
    case 0:
    {
        this->push_front(val);
        break;
    }
    case -1:
    {
        this->push_back(val);
        break;
    }
    default:
    {
        listNode<T> *p_pre, *p_next, *p_insert;
        p_next = this->getNode(pos);
        p_pre = p_next->pre;
        p_insert = new listNode<T>;
        break;
    }
    }
}

template <typename T>
void Linked_list<T>::push_back(T val)
{
    listNode<T> *p1;
    p1 = new listNode<T>;
    p1->value = val;
    // link
    this->tail->next = p1;
    p1->pre = this->tail;
    p1->next = nullptr;
    this->tail = p1;
}

template <typename T>
void Linked_list<T>::push_front(T val)
{
    listNode<T> *p1;
    p1 = new listNode<T>;
    p1->value = val;
    // link
    this->head->pre = p1;
    p1->next = this->head;
    p1->pre = nullptr;
    this->head = p1;
}

template <typename T>
void Linked_list<T>::del(int pos)
{
    switch (pos)
    {
    case 0:
    {
        this->pop_front();
        break;
    }
    case -1:
    {
        this->pop_back();
        break;
    }
    default:
    {
        listNode<T> *p_pre, *p_next, *p_del;
        p_del = this->getNode(pos);
        p_pre = p_del->pre;
        p_next = p_del->next;
        p_pre->next = p_next;
        p_next->pre = p_pre;
        delete p_del;
        break;
    }
    }
}

template <typename T>
void Linked_list<T>::pop_back()
{
    if (this->tail = nullptr)
    {
        return;
    }
    listNode<T> *p1;
    p1 = this->tail;
    this->tail = this->tail->pre;
    delete p1;
}

template <typename T>
void Linked_list<T>::pop_front()
{
    if (this->head = nullptr)
    {
        return;
    }
    listNode<T> *p1;
    p1 = this->head;
    this->head = this->head->next;
    delete p1;
}

template <typename T>
T inline Linked_list<T>::back()
{
    return this->tail->value;
}

template <typename T>
T inline Linked_list<T>::front()
{
    return this->tail->value;
}

template <typename T>
T inline Linked_list<T>::getVal(int pos)
{
    return getNode(pos)->value;
}

template <typename T>
void inline Linked_list<T>::setVal(int pos, T val)
{
    getNode(pos)->value = T;
}

template <typename T>
int Linked_list<T>::length()
{
    int len;
    listNode<T> p1 = this->head;
    for (len = 0; p1.next ! = nullptr; len++)
    {
        p1 = p1.next;
    }
    return len;
}

template <typename T>
bool inline Linked_list<T>::empty()
{
    if (this->head == nullptr)
    {
        return true;
    }
    return false;
}

template <typename T>
void inline Linked_list<T>::clear()
{
    listNode<T> *p1 = this->head;
    while (p1->next != nullptr)
    {
        p1 = p1->next;
        delete p1->pre;
    }
    delete p1;
    this->head = nullptr;
    this->tail = nullptr;
}


template <typename T>
listNode<T> inline *Linked_list<T>::begin()
{
    return this->head;
}

template <typename T>
listNode<T> inline *Linked_list<T>::end()
{
    return this->tail;
}

template <typename T>
listNode<T> *Linked_list<T>::getNode(int pos)
{
    if (pos <= -1)
    {
        return this->tail;
    }
    else if (pos == 0 || pos == 1)
    {
        return this->head;
    }
    listNode<T> *p1 = this->head;
    for (int i = 1; i <= pos && p1->next != nullptr; i++)
    {
        p1 = p1->next;
    }
    return p1;
}
