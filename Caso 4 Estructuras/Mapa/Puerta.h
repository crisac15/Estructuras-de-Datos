
#include <iostream>
#include "../Lista/List.h"
#include "Tunel.h"
using namespace std;


#ifndef PUERTA 

#define PUERTA 1

class Puerta {
    private:
        string nombre; 
        Tunel *tunel = NULL;
        Puerta *padre = NULL;
        Puerta *iz = NULL;
        Puerta *de = NULL;
        Puerta *up = NULL;
        Puerta *down = NULL;
        List<Puerta> puertas; 
        string direcciones[5] = {"Oeste","Este","Norte","Sur"};  // Se puede cambiar por {"Oeste","Este","Norte","Sur"} : {"Izquierda","Derecha","Arriba","abajo"}

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
        string getPadreNombre(){
            return this->padre->getNombre();
        }
        Puerta* getPadre(){
            return this->padre;
        }
       
        List<Puerta> getPuertas(){           
            return puertas;
        }
        Puerta* getPuerta(int pID){            
            return puertas.find(pID);
        }
        int getCantidadDeHijos(){
            return puertas.getSize();
        }

        AVL* getTunel(){
            if (tunel){
                return this->tunel->getTunel();
            }
            return NULL;
            
        }
    
        void setPadre(Puerta* pPuerta, int pID){
            int padres[4] = {1,0,3,2}; //[iz,de,arriba,down] //Los padres son los contrarios, se inicializan para que no se toquen luego
            //cout << "\n"<< "Set padreIN: " << padre << "\n";
            if (pID > 3){
                this->padre = pPuerta;
            }
            if (padre == NULL){
                this->padre = pPuerta;                
                this->puertas.remove(padres[pID]);
                this->puertas.insert(padres[pID],padre);                
                //cout << "Set padreFin: " << padre->getNombre() <<" : Padre Real: " << direcciones[padres[pID]] << "\n";
            }
            //else{
                //cout << "ya tiene padre " << "\n";
            //}
            
            
        }
        void crearTunel(){
            int posibilidad = rand() % 101;
            if (posibilidad <= 66){
                this->tunel = new Tunel();
                tunel->inicializarNodo();
                //tunel->right();
                return;
            }
            //cout << "No se creo el tunel "<< posibilidad << endl;
        }
        void inicializarPuerta(int pID){
            //cout << "Inicializar Puerta: " << pID;
            Puerta *puerta = this->puertas.find(pID);
            puertas.remove(pID);
            puerta = new Puerta();
            puerta->setPadre(this, pID); //pPuerta
            puerta->setNombre(direcciones[pID]);
            puerta->crearTunel();
            puertas.insert(pID,puerta);
           // cout << "Fin inicializacion : nombre : " <<  puerta->getNombre() << "\n\n";
        }
        

};
#endif