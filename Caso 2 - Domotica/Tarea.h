
using namespace std;
#ifndef TAREA
#define TAREA
#include "Lista.h"
class Tarea
{
public:
    string nombreTarea;
    List *asignados = new List();

    Tarea(string pNombre, List pLista)
    {
        this->nombreTarea = pNombre;
        pLista.curr = pLista.first;
        while (pLista.curr != NULL)
        {
            asignados->addNodo(pLista.curr->valor);
            pLista.curr = pLista.curr->next;
        };
    }
    void ejecutar()
    {
        asignados->curr = asignados->first;
        while (asignados->curr != NULL)
        {
            cout << "El Dispositivo " << asignados->curr->valor->getNombre() << " de tipo " << asignados->curr->valor->getTipo() << " ha ejecutado la accion " << asignados->curr->valor->accion->nombre << " con los parametros " << asignados->curr->valor->accion->parametro << " en la habitacion " << asignados->curr->valor->getHabitacion() << endl;
            asignados->curr = asignados->curr->next;
        }
    }
};

#endif