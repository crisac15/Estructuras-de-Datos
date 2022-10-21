#include "List.h"

#ifndef STACK

#define STACK 1

template <class T>
class Stack
{

public:
    List *StackList;
    Stack()
    {
        StackList = new List();
    }

    T Top()
    {
        T result = ' ';
        if (StackList->getSize() != 0)
        {
            result = StackList->find(0);
        }
        return result;
    }

    void Push(T pData)
    {
        StackList->insert(0, pData);
    }

    void Pop()
    {
        if (StackList->getSize() != 0)
        {
            StackList->remove(0);
        }
    }

    bool isEmpty()
    {
        if (StackList->getSize() > 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int size()
    {
        return StackList->getSize();
    }
};

#endif