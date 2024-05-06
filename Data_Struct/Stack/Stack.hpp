/*








*/

#ifndef _STACK_H_
#define _STACK_H_

template <typename T>
struct stackNode
{
    stackNode() : next(nullptr){};
    T value;
    struct stackNode<T> *next;
};

template <typename T>
class Stack
{
public:
    Stack();
    ~Stack();

    void push_back(T val);
    void pop_back();
    T back();

    void clear();
    bool empty();

private:
    stackNode<T> *head;
};

#endif