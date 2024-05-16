#include<iostream>
#include"Stack.hpp"

int main()
{
    Stack<int> a;
    for (int i = 0; i < 5;i++)
    {
        a.push_back(i);
    }
    while (!a.empty())
    {
        std::cout << a.back() << ' ';
        a.pop_back();
        //std::cout << a.back() << ' ';
    }
}