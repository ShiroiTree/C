/*








*/

#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include "../List/List.hpp"
#include "binTree.hpp"
typedef unsigned int uint32;

template <typename T>
class maxHeap
{
public:
    maxHeap();
    // maxHeap(const T[] &data[]);
    maxHeap(List<T> *date);
    ~maxHeap();

    void push();
    void pop();
    void top();

private:
    void update(uint32 depth);
    uint32 deep, tailptr;
    List<T> *m_data;
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
    List<T> *m_data;
};

#endif