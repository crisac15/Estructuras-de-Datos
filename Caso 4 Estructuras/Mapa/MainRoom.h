
#include <iostream>
#include "../Lista/List.h"
#include "../Mapa/Puerta.h"

using namespace std;

#ifndef MAINROOM

#define MAINROOM 1

class MainRoom {
    private:
        int numPuertasCreadas = 0;
        int numeroDePuertas;
        List<List<Puerta>> puertas;
        Puerta *puerta;
        

    public:
        MainRoom(int pNumeroDePuertas){
            this->numeroDePuertas = pNumeroDePuertas;
            puerta = new Puerta();
            this->puerta->setNombre("PuertaInicial");
            this->puerta->setPadre(this->puerta,4); //Se setea a si mismo de padre
        }

        int getNumeroDePueras(){
            return this->numeroDePuertas;
        }


        void crearPuertas2(){

            List<Puerta> cola;
            cola.add(this->puerta);
            while (numPuertasCreadas < this->numeroDePuertas){
                Puerta* puerta = cola.getFirst()->getData();              
                for (int j = 0; j < puerta->getCantidadDeHijos(); j++){
                    int crear = rand()%2;
                    if (crear && puerta->getPuerta(j) == NULL){
                        puerta->inicializarPuerta(j);
                        cola.add(puerta->getPuerta(j));
                        this->numPuertasCreadas++;
                    }
                    if(numPuertasCreadas >= this->numeroDePuertas){
                        return;
                    }
                }

                if (cola.getSize() > 1){
                    cola.dequeue();
                }  
            }
        }

        Puerta* getPuerta(){
            return this->puerta;
        }
};
#endif