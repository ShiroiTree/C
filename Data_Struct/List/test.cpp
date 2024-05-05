#include "List.hpp"
#include<iostream>


void test()
{
    List<int> a;
    for (int i = 0; i <= 50; i++)
    {
        // std::cout << i << ' ';
        a.push_back(i);
        // std::cout << a.back() << ' ';
    }
    while (!a.empty())
    {
        std::cout << a.back() << ' ';
        a.pop_back();
    }
}

int main()
{
    test();
}
