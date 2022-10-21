
using namespace std;

#ifndef LISTA
#define LISTA
#include "Dispositivo.h"
class List
{
public:
    typedef struct Nodo
    {
        Dispositivo *valor;
        Nodo *next;
    } * PtrNodo;
    PtrNodo first;
    PtrNodo curr;
    PtrNodo temp;

    List()
    {
        first = NULL;
        curr = NULL;
        temp = NULL;
    }
    void addNodo(Dispositivo *pData)
    {
        PtrNodo n = new Nodo;
        n->next = NULL;
        n->valor = pData;

        if (first != NULL)
        {
            curr = first;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = n;
        }
        else
        {
            first = n;
        }
    };
    void removerNodo(Dispositivo *pRemove)
    {
        PtrNodo PtrBorrar = NULL;
        temp = first;
        curr = first;
        while (curr != NULL && curr->valor != pRemove)
        {
            temp = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << pRemove << "no esta en lista" << endl;
            delete PtrBorrar;
        }
        else
        {
            PtrBorrar = curr;
            curr = curr->next;
            temp->next = curr;
            if (PtrBorrar == first)
            {
                first = first->next;
                temp = NULL;
            }
            delete PtrBorrar;
            cout << "el valor" << pRemove << "fue borrado" << endl;
        }
    };
    void printList()
    {
        curr = first;
        while (curr != NULL)
        {
            cout << curr->valor << endl;
            curr = curr->next;
        }
    };
};

#endif