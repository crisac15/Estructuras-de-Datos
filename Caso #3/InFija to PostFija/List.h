#include "Node.h"

#ifndef LIST
#define LIST 1

// template <class T>
class List
{
private:
    Node *first;
    Node *last;
    int quantity;
    bool empty;
    Node *searchPosition = NULL;
    Node *searchBehind = NULL;

public:
    List()
    {
        first = NULL;
        last = NULL;
        quantity = 0;
        empty = true;
    }

    void add(char pData)
    {
        Node *newNode = new Node(pData);

        if (quantity > 0)
        {
            this->last->setNext(newNode);
        }
        else
        {
            this->first = newNode;
        }
        this->last = newNode;

        empty = false;
        quantity++;
    }

    Node *getFirst()
    {
        return this->first;
    }

    int getSize()
    {
        return quantity;
    }

    bool isEmpty()
    {
        return quantity;
    }

    char find(int pPosition)
    {
        char result = ' ';
        searchPosition = this->first;
        searchBehind = NULL;

        if (pPosition < getSize())
        {
            while (pPosition > 0)
            {
                searchBehind = searchPosition;
                searchPosition = searchPosition->getNext();
                pPosition--;
            }
            result = searchPosition->getData();
        }

        return result;
    }

    // es que si el position es mayor a la cantidad, entonces inserto al final
    void insert(int pPosition, char pData)
    {

        if (pPosition < getSize() && first != NULL)
        {
            Node *newNodo = new Node(pData);

            char result = find(pPosition);

            newNodo->setNext(searchPosition);
            if (searchBehind != NULL)
            {
                searchBehind->setNext(newNodo);
            }
            else
            {
                this->first = newNodo;
            }

            quantity++;
        }
        else
        {
            add(pData);
        }
    }

    bool remove(int pPosition)
    {
        bool result = false;
        if (first != NULL && pPosition < getSize())
        {
            Node *search = first;
            if (pPosition != 0)
            {
                char data = find(pPosition);

                searchBehind->setNext(searchPosition->getNext());

                if (searchPosition == last)
                {
                    last = searchBehind;
                }
                searchPosition->setNext(NULL);
            }
            else
            {
                first = first->getNext();
                search->setNext(NULL);
                delete search;
            }
            quantity--;
        }
        return result;
    }
};

#endif