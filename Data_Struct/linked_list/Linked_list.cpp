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
Linked_list<T>::Linked_list(uint32 length)
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
Linked_list<T>::~Linked_list()
{
    listNode<T> *p1;
    p1 = head;
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
