#include <iostream>
#include <string>
#include <map>
using namespace std;

class Strategy
{
private:
    string estrategia;
    string criterioPuer;
    string criterioTunel;

public:
    Strategy(){};
    Strategy(string pNombre, string pCritPuertas, string pCritTuneles)
    {
        this->criterioPuer = pCritPuertas;
        this->criterioTunel = pCritTuneles;
        this->estrategia = pNombre;
    }
    string getNombreEstrategia()
    {
        return estrategia;
    }
    string getCriterioPuerta()
    {
        return criterioPuer;
    }
    string getCriterioTunel()
    {
        return criterioTunel;
    }
    map<string, Strategy> preliminares()
    {
        map<string, Strategy> asignadas;
        Strategy ejemplo = Strategy("tryhard", "escoje la primer puerta con tunel", "camina hacia la mitad del tunel para garantizar cantidad/tiempo");
        Strategy ejemplo2 = Strategy("analisis", "busca la puerta con tunel mas grande", "viaja hasta el final del tunel para minar");
        asignadas["tryhard"] = ejemplo;
        asignadas["analitico"] = ejemplo2;
        return asignadas;
    }
};

class Miner : public Strategy
{
protected:
    string nombre;
    int velocidadDeMov;
    int capacidadCarga;
    Strategy asignada;
    map<string, Strategy> estrategias = this->preliminares();

public:
    Miner(){};
    virtual void setStrategy(string) = 0;
    int getVelocity()
    {
        return this->velocidadDeMov;
    }
    int getCapacity()
    {
        return this->capacidadCarga;
    }
};

class Explorer : public Miner
{
public:
    Explorer()
    {
        this->nombre = "explorer";
        this->capacidadCarga = 8;
        this->velocidadDeMov = 20;
    }
    void setStrategy(string pStrategy)
    {
        this->asignada = estrategias[pStrategy];
    }
    Strategy getStrategy()
    {
        return asignada;
    }
};

// begin() – retorna un iterator con el primer elemento del map.
// end() – retorna un iterator con el teorico elemento que está después del map.
// size() – retorna el numero de elementos del map.
// empty() – Indica si está vacío.
// pair insert(keyvalue, mapvalue) – añade nuevo elemento al map.
// erase(iterator position) – Elimina el elemento que se indique con el iterator.
// erase(const g)– Elimina la llave y valor indicada por ‘g’.
// clear() – Elimina todos los elementos del map.

int main()
{
    map<string, string> mapExample;
    mapExample["uno"] = "manzana";
    mapExample["dos"] = "banano";
    mapExample["tres"] = "naranja";
    // creamos iterator
    map<string, string>::iterator i;
    for (i = mapExample.begin(); i != mapExample.end(); i++)
    {
        cout << "llave: " << i->first << "  valor: " << i->second << endl;
    }

    // no creamos iterator
    map<int, int> order;
    order[5] = 10;
    order[3] = 5;
    order[20] = 100;
    order[1] = 1;
    for (auto i = order.begin(); i != order.end(); i++)
    {
        cout << i->first << " : " << i->second << endl;
    }

    // lo podemos usar para implementar en clases polimirficas
    Explorer exp1 = Explorer();
    exp1.setStrategy("tryhard");
    cout << "Nombre de estrategia asignada:  " << exp1.getStrategy().getNombreEstrategia() << endl;
    cout << "Criterio para tuneles:  " << exp1.getStrategy().getCriterioTunel() << endl;
    cout << "Criterio para puertas:  " << exp1.getStrategy().getCriterioPuerta() << endl;

    return 0;
}