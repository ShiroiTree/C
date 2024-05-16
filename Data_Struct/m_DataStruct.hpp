
#ifndef _DATATYPE_
#define _DATATYPE_

typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;

#endif

namespace ST // ST<ShiroiTree>
{

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

    template class List<int8>;
    template class List<int16>;
    template class List<int32>;
    template class List<int64>;
    template class List<uint8>;
    template class List<uint16>;
    template class List<uint32>;
    template class List<uint64>;
    template class List<float>;
    template class List<double>;

#endif // end of List

#ifndef _STACK_HPP_
#define _STACK_HPP_

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

template class Stack<int8>;
template class Stack<int16>;
template class Stack<int32>;
template class Stack<int64>;
template class Stack<uint8>;
template class Stack<uint16>;
template class Stack<uint32>;
template class Stack<uint64>;
template class Stack<float>;
template class Stack<double>;

#endif //end of Stack


} // end of namespcae ST<ShiroiTree>
