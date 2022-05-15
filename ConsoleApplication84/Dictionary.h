#pragma once
#include <iostream>
using namespace std;
const int size_dict = 5;

template<typename T>
class Dictionary
{
protected:
    struct Node
    {
        T element;
        Node* next;
    };
    Node* dict[size_dict];
public:
    Dictionary() { MAKENULL(); }
    void MAKENULL();
    bool MEMBER(T x);
    void INSERT(T x);
    void DELETE(T x);
    void PRINT();
private:
    int h(T x);
};

