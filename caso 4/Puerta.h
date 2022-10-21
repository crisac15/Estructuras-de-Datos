#include <string>
#include <iostream>
#include "dobleenlazada/List.h"
//#include "Tunel.h"

using namespace std;


#ifndef Puerta 
class Puerta {
    private:
        Tunel *tunel;
        string nombre; 
        string nombrePadre; //SOLO PARA PROBAR
        Puerta *iz = NULL;
        Puerta *de = NULL; 
        Puerta *up = NULL;
        Puerta *down = NULL;
        List<Puerta> puertas; 
        List<Puerta> *puertasHijos = new List<Puerta>();// SOLO CONTIENE A LAS PUERTAS HIJOS

    public:
        Puerta(){
            puertas.add(iz);
            puertas.add(de);
            puertas.add(up);
            puertas.add(down);  
        }
        void setNombre(string pNombre){
            this->nombre = pNombre;
        }

        string getNombre(){
            return this->nombre;
        }

        string getPadre(){
            return this->
        }
        void setPuertaPadre(int pID, Puerta *pPuerta){
            if(pID == 0){
                this->setNombre("Izquierda");
                this->nombrePadre = "derecha";
                this->de = pPuerta;
            }
            else if(pID == 1){
                this->setNombre("Derecha");
                this->nombrePadre = "izquiera";
                this->iz = pPuerta;
            }
            else if(pID == 2){
                this->setNombre("Arriba");
                this->nombrePadre = "down";
                this->down = pPuerta;
            }
            else if(pID == 3){
                this->setNombre("Abajo");
                this->nombrePadre = "up";
                this->up = pPuerta;
            }
        }
       
        void crearTunel(){
            this->tunel = new Tunel();
        }
        void asignarTunel(){
            int posibilidad = rand() % 101; 
            if (posibilidad <= 66){
                crearTunel();
            }
            
        }
        
        List<Puerta>* getPuertas(){            
            return puertasHijos;
        }
        int getCantidadDePuertasHijos(){
            return puertasHijos->getSize();
        }
        void incializarPuertas(Puerta *pPuerta, int pCantidad, int pCantidadMaxima){      
            cout << "Inicializar " << pPuerta->getNombre() << "\n";   
            int cantidadActual = 0;   
            for (int i = 0; i < this->puertas.getSize() ; i++){ // ACA SE CREAN LAS PUERTAS   // 0 1 2 3              
                int crear = rand() % 2;
                Puerta *puerta = puertas.find(i);
                if (crear && puerta == NULL && pCantidad+cantidadActual <=pCantidadMaxima){
                    puerta = new Puerta();
                    puerta->setPuertaPadre(i,pPuerta);
                    cout << "init de " << pPuerta->getNombre() << " para " << puerta->getNombre()<< "\n"; 
                    puertasHijos->add(puerta);
                    cantidadActual++;
                }else{
                    puertasHijos->add(NULL); 
                }  
            }            
        }

        
        

};
#endif