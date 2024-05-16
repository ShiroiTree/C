/*








*/

#include "Heap.hpp";

template <typename T>
maxHeap<T>::maxHeap()
{
    this->m_data = new List<T>;
    this->deep = 0;
}

template <typename T>
maxHeap<T>::maxHeap(List<T> *date)
{
    this->m_data = new List<T>;
    this->deep = 0;
    for (int i = 0; i < date->lenth; i++)
    {
        m_data[i] = date[i];
    }
    update(deep);
}

