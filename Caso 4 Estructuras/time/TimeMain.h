#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include "../Mapa/MainRoom.h"
#include "../Jugador/MenuSeleccionPJ.h"
#include "../Jugador/Jugador.h"


using namespace std;

class TimeMain{
    private:
        struct tm *finTurno;
        time_t local_time;
        int cantidad_timepo = 2; //Minutos

        int numero_Puertas; //Cantidad de puertas a generar
        
        Jugador *jugador1 = NULL; 
        Jugador *jugador2 = NULL;

        MainRoom *room = NULL;
        Puerta *mapa;

    public:
        TimeMain(){
            this->local_time = time(NULL);   
              
        }
        void ganador(){
            cout << "Materiales recolectados por el jugador 1: " << jugador1->getCantidadDeMaterial() << endl;
            cout << "Materiales recolectados por el jugador 2: " << jugador2->getCantidadDeMaterial() << endl;
            if (jugador1->getCantidadDeMaterial() == jugador2->getCantidadDeMaterial()){                
                cout << endl << "Jugador 1 y 2 han empatado el juego!!!!" << endl << endl;
                return;   
            }  
            else if (jugador1->getCantidadDeMaterial() > jugador2->getCantidadDeMaterial()){                
                cout << endl << "El _jugador 1_ ha gando el juego!!!!" << endl << endl;
                return;   
            }            
            cout << endl <<"El _jugador 2_ ha gando el juego!!!!" << endl << endl;
            return;
        }

        void init(){
            cout << "Digite el numero de puertas a generar: ";
            cin >> this->numero_Puertas;
            room = new MainRoom(this->numero_Puertas);
            room->crearPuertas2();
            this->mapa = room->getPuerta();

        }

        void run1(){
            cout << "\nTurno del jugador 1: \n" ;
            this->finTurno = localtime(&local_time);
            this->finTurno->tm_min += this->cantidad_timepo; // Se asigna la hora en la que finaliza el turno
            Menu menu1;
            jugador1 = menu1.seleccionar3Mineros();
            jugador1->setMapa(this->mapa);
            time_t curr1 = mktime(finTurno);
            time_t curr2 = mktime(localtime(&local_time));
            cout << "\nLos mineros comenzaron a buscar mineral!!!" << endl;
            cout << "\nHora en la que finaliza el turno: " << ctime(&curr1) << endl;
            jugador1->runMineros();
            while (curr1 > curr2){          // hasta que no se termine el turno      
                curr2 = time(NULL);
                curr2 = mktime(localtime(&curr2));
            }
            jugador1->setEnable(false);
            local_time = time(NULL);
            finTurno = NULL;
            cout << "\n --Se acabo el tiempo jajaja-- \n";
            cout << "Jugador 1 consiguio: " << jugador1->getCantidadDeMaterial() << endl << endl;
        }
        void run2(){
            cout << "\nTurno del jugador 2: \n" ;
            this->finTurno = localtime(&local_time);
            this->finTurno->tm_min += this->cantidad_timepo; // Se asigna la hora en la que finaliza el turno
            Menu menu2;
            jugador2 = menu2.seleccionar3Mineros();
            jugador2->setMapa(this->mapa);
            time_t curr1 = mktime(finTurno);
            time_t curr2 = mktime(localtime(&local_time));
            cout << "Hora en la que finaliza el turno: " << ctime(&curr1) << endl;
            jugador2->runMineros();
            while (curr1 > curr2){          // hasta que no se termine el turno      

                curr2 = time(NULL);
                curr2 = mktime(localtime(&curr2));;

            }
            jugador2->setEnable(false);
            local_time = time(NULL);
            cout << "\n --Se acabo el tiempo jajaja-- \n";
            cout << "Jugador 2 consiguio: " << jugador2->getCantidadDeMaterial() << endl << endl;
            this->ganador();
        }

        
            

};