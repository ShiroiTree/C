/*




*/


#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

//typedef unsigned int uint32;

template <typename T>
struct listNode
{
    listNode() : pre(nullptr), next(nullptr) {}
    T value;
    struct listNode<T> *pre, *next;
};

template <typename T>
class Linked_list
{
public:
    Linked_list();
    Linked_list(int length);
    Linked_list(const Linked_list<T> &copyFrom);
    ~Linked_list();

    void insert(int pos, T val);
    void push_back(T val);
    void push_front(T val);
    void del(int pos);
    void pop_back();
    void pop_front();

    int length();

    bool empty();
    void clear();

    T back();
    T front();
    T getVal(int pos);
    void setVal(int pos, T val);
    // T &operator[](uint32 pos);

    listNode<T> *begin();
    listNode<T> *end();
    listNode<T> *getNode(int pos);

private:
    listNode<T> *head, *tail;
};

#endif