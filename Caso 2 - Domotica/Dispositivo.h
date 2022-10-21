
// #include "Tarea.h"

using namespace std;
#ifndef DISPOSITIVO
#define DISPOSITIVO
#include "Action.h"
class Dispositivo
{
private:
    string nombre;
    string habitacion;
    string tipo;
    // friend class Tarea;

public:
    Action *accion;
    Dispositivo(string pTipo, string pNombre, string pHabitacion)
    {
        this->tipo = pTipo;
        this->nombre = pNombre;
        this->habitacion = pHabitacion;
    }

    string getTipo()
    {
        return tipo;
    }

    string getNombre()
    {
        return nombre;
    }
    string getHabitacion()
    {
        return habitacion;
    }
};

#endif