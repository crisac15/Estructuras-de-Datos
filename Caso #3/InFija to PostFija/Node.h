#include <iostream>

#ifndef NODE

#define NODE 1

using namespace std;

// template <class T>
class Node
{
private:
    char data;
    Node *next;

public:
    Node()
    {
        data = ' ';
        next = NULL;
    }

    Node(char pData)
    {
        this->data = pData;
        next = NULL;
    }

    char getData()
    {
        return data;
    }

    Node *getNext()
    {
        return next;
    }

    void setNext(Node *pValue)
    {
        this->next = pValue;
    }
};

#endif