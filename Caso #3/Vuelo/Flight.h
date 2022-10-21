#include <iostream>
#include <string>
#include <ctime>
#include "ColaPriori.h"

using namespace std;
class Flight
{

private:
    time_t flightTime;
    string aerolinea;
    int numeroVuelo;
    int pasajeros;
    tm *horaMod;
    int horaSalida;
    int minSalida;

public:
    Flight()
    {
        flightTime = time(NULL);
        this->numeroVuelo = 0;
        this->pasajeros = 0;
        this->aerolinea = "";
    }
    Flight(int pHour, int pMinutes, int pPasajeros, int pAerolinea, int pNumero)
    {
        tm *currentTime = localtime(&flightTime);
        this->horaSalida = pHour;
        this->minSalida = pMinutes;
        mktime(currentTime);
        horaMod = currentTime;

        pasajeros = pPasajeros;

        string aeroDisp[6] = {"Avianca", "Volaris", "Iberia", "Qatar Airways", "Copa Airlines", "American Airlines"};
        aerolinea = aeroDisp[pAerolinea];

        numeroVuelo = pNumero;
    }

    void flightTimeString()
    {
        cout << "El vuelo numero " << this->numeroVuelo << " ha despegado a las " << this->horaSalida << " horas y " << this->minSalida << " minutos"
             << " con " << this->pasajeros << " pasajeros"
             << " a bordo de la aerolinea " << this->aerolinea << endl;
    }

    int getIntTimeValue()
    {
        return (this->horaSalida * 100) + this->minSalida;
    }
};