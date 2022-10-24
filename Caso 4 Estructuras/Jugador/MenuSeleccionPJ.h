#include <iostream>

#include "Jugador.h"

#include "MinerosType/Explorer.h"
#include "MinerosType/Topo.h"
#include "MinerosType/Carguero.h"

#include "Estrategias/StratAgresivo.h"
#include "Estrategias/StratPasivo.h"
#include "Estrategias/StratProfundo.h"

using namespace std;

class Menu
{
private:
    int seleccion;
    Jugador *jugador = new Jugador();

public:
    Jugador *seleccionarStrategy()
    {
        cout << "\n Seleecionar la estrategia que el jugador seguira: " << endl
             << endl;
        cout << "1) Agresivo" << endl;
        cout << "2) Pasivo" << endl;
        cout << "3) Profundo" << endl;
        cin >> seleccion;
        if (seleccion == 1)
        {
            Strategy *agresivo = new Agresivo();
            jugador->setStrategyMiner(agresivo);
        }

        else if (seleccion == 2)
        {
            Strategy *pasivo = new Pasivo();
            jugador->setStrategyMiner(pasivo);
        }

        else if (seleccion == 3)
        {
            Strategy *profundo = new Profundo();
            jugador->setStrategyMiner(profundo);
        }
        else if (seleccion > 3 || seleccion < 1)
        {
            cout << "Error en seleccion" << endl;
            return NULL;
        }
        return this->jugador;
    }

    Jugador *menuSeleccion()
    {

        cout << endl
             << "-- Digite uno de los siguientes numeros: --" << endl;
        cout << " 1) Explorador " << endl;
        cout << " 2) Topo " << endl;
        cout << " 3) Cargador " << endl;
        cin >> seleccion;
        if (seleccion == 1)
        {
            this->jugador->addMinero(new Explorer());
            return seleccionarStrategy();
        }
        else if (seleccion == 2)
        {
            this->jugador->addMinero(new Topo());
            return seleccionarStrategy();
        }
        else if (seleccion == 3)
        {
            this->jugador->addMinero(new Carguero());
            return seleccionarStrategy();
        }
        else if (seleccion > 3 || seleccion < 1)
        {
            cout << "Error en seleccion" << endl;
            return NULL;
        }
    }

    Jugador *seleccionar3Mineros()
    {
        cout << endl
             << "   MENU DE SELECCION DE PERSONAJE   " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "   Minero: " << i + 1 << " | " << i << " de "
                 << "3" << endl;
            menuSeleccion();
        }
        return this->jugador;
    }
};