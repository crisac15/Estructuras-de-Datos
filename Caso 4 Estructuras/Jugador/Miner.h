#include <iostream>
#include <string>
#include <map>
#include "Strategy.h"
using namespace std;

#ifndef MINER

#define MINER 1

class Miner
{
private:
    string nombre;
    int velocidadDeMov;
    int capacidadCarga;
    Strategy *estrategia;

public:
    void setStrategy(Strategy *pStrategy)
    {
        this->estrategia = pStrategy;
    }
    Strategy *getStrategy()
    {

        return this->estrategia;
    }

    int getVelocity()
    {
        return this->velocidadDeMov;
    }
    int getCapacity()
    {
        return this->capacidadCarga;
    }

    void setNombre(string pNombre)
    {
        this->nombre = pNombre;
    }
    void setCapacidad(int pCapacidadCarga)
    {
        this->capacidadCarga = pCapacidadCarga;
    }
    void setVelocidadMovimiento(int pVel)
    {
        this->velocidadDeMov = pVel;
    }
    string getNombre()
    {
        return this->nombre;
    }

    virtual int criterio(AVLNode *pNode, int pCantidadActual, int pCapacidad)
    {
        return NULL;
    }
};
#endif