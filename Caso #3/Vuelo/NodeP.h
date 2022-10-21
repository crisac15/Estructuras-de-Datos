#include <iostream>
#ifndef NODEP
#define NODEP 1
using namespace std;

template <class T>
class NodeP
{
private:
    T data;
    NodeP *next;
    NodeP *previous;
    int priority;

public:
    NodeP()
    {
        priority = NULL;
        data = NULL;
        next = NULL;
        previous = NULL;
    }

    NodeP(T pData, int pPriority)
    {
        this->data = pData;
        this->priority = pPriority;
        next = NULL;
    }

    T getData()
    {
        return data;
    }

    NodeP *getNext()
    {
        return next;
    }
    void setNext(NodeP *pValue)
    {
        this->next = pValue;
    }

    NodeP *getPrevious()
    {
        return previous;
    }
    void setPrevious(NodeP *pValue)
    {
        this->previous = pValue;
    }

    int getPriority()
    {
        return priority;
    }
};

#endif