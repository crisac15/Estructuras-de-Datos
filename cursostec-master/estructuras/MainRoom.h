#include <string>
#include <iostream>
#include "starticketcr/dobleenlazada/List.h"
#include "Puerta.h"
#include "list"

using namespace std;

#ifndef MainRoom 
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
            this->puerta->incializarPuertas(this->puerta,numPuertasCreadas,numeroDePuertas);
            this->numPuertasCreadas += getRealHijos(puerta);


            cout << this->puerta->getNombre() << "\n";
        }

        int getNumeroDePueras(){
            return this->numeroDePuertas;
        }
        int getRealHijos(Puerta *pPuerta){
            int cant = 0;
            for(int i = 0; i < pPuerta->getCantidadDePuertasHijos(); i++){
                if (pPuerta->getPuertas()->find(i)!= NULL){
                    cant++;
                }
            }
            return cant;

        }
        
        void crearPuertas(){
            cout << "\n\n\n" "CrearPuertas" << "\n";
            List<List<Puerta>> listaPila; // Cambiar a una pila
            listaPila.add(puerta->getPuertas()); //Nos da las puertas hijos ejm: [NULL, de, NULL, down]
            int size = 1; 
            for (int i = 0; i < size ; i++){                         
                for (int j = 0; j < listaPila.find(i)->getSize(); j++){
                    int crear = rand() % 6;
                    //cout << "enable: "<< crear << " : " << i <<" : " <<numPuertasCreadas<< " : " <<listaPila.find(i)->find(j) << "\n";
                    if (crear && numPuertasCreadas+1 <= this->numeroDePuertas && listaPila.find(i)->find(j) != NULL){ //Numero menor al dado y que la puerta haya sido inicializada
                        listaPila.find(i)->find(j)->setPuertaPadre(j,listaPila.find(i)->find(j));                  // HAY UNA MEJOR FORMA PARA NO TENER QUE VALIDAR EL NULL / RECORDAR
                        listaPila.find(i)->find(j)->incializarPuertas(listaPila.find(i)->find(j),numPuertasCreadas,numeroDePuertas);
                        //puertasTemp.add(listaPila.find(i)->find(j)); // Se añaden las nuevas puertas eje: [iz,de,up] 
                        listaPila.add(listaPila.find(i)->find(j)->getPuertas()); //[iz, de ,arr,down] 
                        numPuertasCreadas+= getRealHijos(listaPila.find(i)->find(j)); //4
                        //cout << getRealHijos(listaPila.find(i)->find(j))<< " : " << j << "\n";
                        size++;
                    }
                    if (numPuertasCreadas > this->numeroDePuertas){
                        //cout << "Puertas creadas " << numPuertasCreadas << " : " << numeroDePuertas << "\n";
                    }
                }
                
                //size--;
            }
            cout << "Puertas creadas " << numPuertasCreadas << "\n";
        }


        void showPuerta(){ // SOLO PARA PROBAR LA EFECTIVIDAD
            cout << "\n\n\n" << "SHOW " << "\n";
            List<List<Puerta>> listaPila;
       
            listaPila.add(puerta->getPuertas());
            int size = listaPila.getSize();
            cout << " padre: " << puerta->getNombre()<< "\n";
            for (int i = 0; i < size ; i++){
                string nombre;
                for (int j = 0; j < listaPila.find(i)->getSize(); j++){
                    if (listaPila.find(i)->find(j) != NULL){
                        //cout << i << " padre: " << listaPila.find(i)->find(j)->getPadre() << "\n";
                        cout << listaPila.find(i)->find(j)->getNombre() << "_";
                        listaPila.add(listaPila.find(i)->find(j)->getPuertas());
                        nombre = listaPila.find(i)->find(j)->getNombre();
                        cout << "hijos: " <<getRealHijos(listaPila.find(i)->find(j))<< "\n";
                        size++;
                    }
                cout << "\n";
                cout << "\nPrueba " << nombre << "\n";
                //size--;
                }

            }  
        }
};
#endif