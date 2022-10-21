#include "Flight.h"
#include "ListG.h"
#include "cstdlib"

List<Flight> listaVuelos = List<Flight>();
List<QueueP<Flight>> listaPistas = List<QueueP<Flight>>();
int vuelosDiarios = 0;
void fillFlights(int pCantidad, int pStartHour, int pEndHour)
{
    vuelosDiarios = pCantidad;
    for (int i = 0; i < pCantidad; i++)
    {
        int hora = pStartHour + rand() % (pEndHour - pStartHour);
        int minuto = rand() % (43);
        int atraso = rand() % (18);
        minuto += atraso;

        int pasajeros = 300 + rand() % (550 + 1 - 300);
        int aero = rand() % (6);
        int numVuelo = 1 + rand() % (1000 - 1);

        Flight *vuelo = new Flight(hora, minuto, pasajeros, aero, numVuelo);
        listaVuelos.add(vuelo);
    }
}
void pistasAeropuerto(int pPistas)
{
    for (int i = 0; i < pPistas; i++)
    {
        QueueP<Flight> *Pistas = new QueueP<Flight>();
        listaPistas.add(Pistas);
    }

    while (!listaVuelos.isEmpty())
    {
        int proxVuelo = listaVuelos.find(0)->getIntTimeValue();
        for (int i = 0; i < listaVuelos.getSize(); i++)
        {
            if (listaVuelos.find(i)->getIntTimeValue() < proxVuelo)
            {
                proxVuelo = listaVuelos.find(i)->getIntTimeValue();
            }
        }
        for (int i = 0; i < listaVuelos.getSize(); i++)
        {
            if (listaVuelos.find(i)->getIntTimeValue() == proxVuelo)
            {
                listaPistas.find(i % pPistas)->enqueue(*listaVuelos.find(i), proxVuelo);
                listaVuelos.remove(i);
                break;
            }
        }
    }
}
void despegar()
{
    int prioridad = 0;
    for (int i = 0; i < vuelosDiarios; i++)
    {
        for (int i = 0; i < listaPistas.getSize(); i++) // iteraciones segun numero de pistas
        {
            if (!listaPistas.find(i)->isEmpty()) // si la pista no esta vacia
            {
                prioridad = listaPistas.find(i)->front().getIntTimeValue(); // prioridad igual al primero de la pista (solo para inicializar)

                for (int j = 0; j < listaPistas.getSize(); j++) // recorro pistas  de nuevo
                {
                    if (!listaPistas.find(j)->isEmpty())
                    { // pregunto si no esta vacia
                        if (prioridad >= listaPistas.find(j)->front().getIntTimeValue())
                        { // si hay alguna de las del frot de la cola con mayor prioridad

                            prioridad = listaPistas.find(j)->front().getIntTimeValue(); // entonces ese es el primer vuelo en despegar
                        }
                    }
                }
                for (int k = 0; k < listaPistas.getSize(); k++) // recorro la lista para revisar el vuelo que le corresponde salir
                {
                    if (!listaPistas.find(k)->isEmpty())
                    { // con esto evito iteraciones en colas que ya han sido vaciadas
                        if (listaPistas.find(k)->front().getIntTimeValue() == prioridad)
                        { // si la hora de despegue coincide con la mas proxima entre los front de las colas de pista
                            listaPistas.find(k)->front().flightTimeString();
                            cout << "De la pista de despegue numero: " << (k + 1) << endl;
                            cout << endl;
                            listaPistas.find(k)->dequeue();
                            break;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    // numero de vuelos/hora inicial/hora final
    fillFlights(10, 1, 24);
    // numero de pistas del aeropuesto donde despegan los n vuelos
    pistasAeropuerto(4);

    despegar();
}