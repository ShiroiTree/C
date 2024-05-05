/*
header file for list.cpp


*/

#ifndef _LIST_HPP_
#define _LIST_HPP_

typedef unsigned int size_T;

template <typename T>
class List
{
public:
    //
    List();
    List(size_T len);
    ~List();

    void push_back(T value);
    void pop_back();

    void setVal(size_T pos, T value);
    T back();
    T getVal(size_T pos); // operator []

    bool empty();
    void clear();

    T *begin();
    T *end();

private:
    T *m_Data;
    size_T m_Size, m_tailptr;

    void sizeIncrease();
};

#endif
