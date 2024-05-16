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

    int lenth();
    T *begin();
    T *end();

    T &operator[](size_T pointer);

private:
    T *m_Data;
    size_T m_Size, m_tailptr;

    void sizeIncrease();
};

template class List<char>;
template class List<unsigned char>;
template class List<short>;
template class List<unsigned short>;
template class List<int>;
template class List<unsigned int>;
template class List<float>;
template class List<double>;

#endif
