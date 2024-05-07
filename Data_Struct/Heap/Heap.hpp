/*








*/


#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include "../List/List.hpp"

template <typename T>
class maxHeap
{
public:
    maxHeap();

    void push();
    void pop();
    void top();

private:
    List<T> *heap;
};

template <typename T>
class minHeap
{
public:
    minHeap();

    void push();
    void pop();
    void top();

private:
    List<T> *heap;
};

#endif