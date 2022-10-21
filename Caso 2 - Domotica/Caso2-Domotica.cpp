#include <conio.h>
#include <iostream>
#include "Lista.h"
#include "ListaTarea.h"
#include "Dispositivo.h"
#include "Tarea.h"
using namespace std;
void configParametros(Tarea *pTarea)
{
    pTarea->asignados->curr = pTarea->asignados->first;
    while (pTarea->asignados->curr != NULL)
    {
        Action *ejemplo = new Action();
        if (pTarea->asignados->curr->valor->getTipo() == "Bombillo")
        {
            if (pTarea->nombreTarea == "buenos dias")
            {
                ejemplo->nombre = "encender";
                ejemplo->parametro = "Luz media";
            }
            if (pTarea->nombreTarea == "Chill")
            {
                ejemplo->nombre = "apagar";
                ejemplo->parametro = "luz nula";
            }
        }
        if (pTarea->asignados->curr->valor->getTipo() == "Televisor")
        {
            if (pTarea->nombreTarea == "buenos dias")
            {
                ejemplo->nombre = "encender";
                ejemplo->parametro = "Canal 7";
            }
            if (pTarea->nombreTarea == "Chill")
            {
                ejemplo->nombre = "encender";
                ejemplo->parametro = "HDMI";
            }
        }
        if (pTarea->asignados->curr->valor->getTipo() == "Consola")
        {
            if (pTarea->nombreTarea == "buenos dias")
            {
                ejemplo->nombre = "encender";
                ejemplo->parametro = "Canal 7";
            }
            if (pTarea->nombreTarea == "Chill")
            {
                ejemplo->nombre = "encender";
                ejemplo->parametro = "Iniciar FIFA";
            }
        }
        if (pTarea->asignados->curr->valor->getTipo() == "Coffee Maker")
        {
            if (pTarea->nombreTarea == "buenos dias")
            {
                ejemplo->nombre = "encender";
                ejemplo->parametro = "Cafe Fuerte";
            }
            if (pTarea->nombreTarea == "Chill")
            {
                ejemplo->nombre = "encender";
                ejemplo->parametro = "Cafe con leche";
            }
        }
        if (pTarea->asignados->curr->valor->getTipo() == "Aire Acondicionado")
        {
            if (pTarea->nombreTarea == "buenos dias")
            {
                ejemplo->nombre = "apagar";
                ejemplo->parametro = "nulo";
            }
            if (pTarea->nombreTarea == "Chill")
            {
                ejemplo->nombre = "encender";
                ejemplo->parametro = "20 grados";
            }
        }
        pTarea->asignados->curr->valor->accion = ejemplo;
        pTarea->asignados->curr = pTarea->asignados->curr->next;
    }
}
void EjecutarTarea(LisTarea pListaTareas, string pNombre)
{
    pListaTareas.curr = pListaTareas.first;
    while (pListaTareas.curr != NULL)
    {
        if (pListaTareas.curr->valor->nombreTarea == pNombre)
        {
            pListaTareas.curr->valor->ejecutar();
        };
        pListaTareas.curr = pListaTareas.curr->next;
    };
}
int main()
{
    //-------------------------------------------- CREAR DISP ---------------------------------------------------------
    Dispositivo *bombillo = new Dispositivo("Bombillo", "bombi 1", "sala");
    Dispositivo *tvSala = new Dispositivo("Televisor", "pantalla 1", "sala");

    Dispositivo *CM = new Dispositivo("Coffee Maker", "CM de oficina", "Oficina");

    Dispositivo *pantalla = new Dispositivo("Televisor", "pantalla de cuarto", "cuarto");
    Dispositivo *AC = new Dispositivo("Aire Acondicionado", "AC de cuarto", "cuarto");
    Dispositivo *PS4 = new Dispositivo("Consola", "ps4 del cuarto", "cuarto");
    //------------------------------------ GUARDAR DISP EN LISTA ------------------------------------------------------
    List *sala = new List();
    sala->addNodo(bombillo);
    sala->addNodo(tvSala);

    List *office = new List();
    office->addNodo(CM);

    List *cuarto = new List();
    cuarto->addNodo(pantalla);
    cuarto->addNodo(AC);
    cuarto->addNodo(PS4);
    List *especial = new List();
    especial->addNodo(bombillo);
    especial->addNodo(CM);
    especial->addNodo(pantalla);
    //-------------------------------------------- CREAR TAREA --------------------------------------------------------
    Tarea *BuenosDias = new Tarea("buenos dias", *especial);
    configParametros(BuenosDias);
    Tarea *Chill = new Tarea("Chill", *cuarto);
    configParametros(Chill);
    //------------------------------------  GUARDAR TAREAS EN LISTA ------------------------------------------------------
    LisTarea *lisTareas = new LisTarea();
    lisTareas->addTarea(BuenosDias);
    lisTareas->addTarea(Chill);
    //------------------------------------ EJECUTAR TAREA POR NOMBRE ------------------------------------------------------
    EjecutarTarea(*lisTareas, "Chill");
}