#include "../InFija to PostFija/Stack.h"

#ifndef COLA2P

#define COLA2P 1

template <class T>
class Cola2P
{
private:
    Stack<T> Pila1 = Stack<T>();
    Stack<T> Pila2 = Stack<T>();

public:
    Cola2P()
    {
    }

    void enqueue(T pValue)
    {
        Pila1.Push(pValue);
    }

    T dequeue()
    {
        T result = ' ';
        while (!Pila1.isEmpty())
        {
            Pila2.Push(Pila1.Top());
            Pila1.Pop();
        }
        result = Pila2.Top();
        Pila2.Pop();
        return result;
    }

    T front()
    {
        Pila2.Top();
    }

    bool isEmpty()
    {
        if (Pila1.size() > 0 || Pila2.size() > 0)
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