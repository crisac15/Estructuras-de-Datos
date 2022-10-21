#include "List.h"

#ifndef QUEUE

#define QUEUE 1

template <class T>
class Queue
{
private:
    List *queueList;

public:
    Queue()
    {
        queueList = new List();
    }

    void enqueue(T pValue)
    {
        queueList->add(pValue);
    }

    T dequeue()
    {
        T result = ' ';
        if (queueList->getSize() > 0)
        {
            result = queueList->find(0);
            queueList->remove(0);
        }
        return result;
    }

    T front()
    {
        T result = ' ';
        if (queueList->getSize() > 0)
        {
            result = queueList->find(0);
        }
        return result;
    }
    int size()
    {
        return queueList->getSize();
    }

    bool isEmpty()
    {
        if (queueList->getSize() > 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

#endif