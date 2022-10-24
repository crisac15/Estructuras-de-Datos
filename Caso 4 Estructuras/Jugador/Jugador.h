#include <iostream>
#include "../Mapa/Puerta.h"
#include "../Lista/List.h"
#include <thread>
#include <chrono>
#include "Miner.h"

using namespace std;

#ifndef JUGADOR

#define JUGADOR 1

class Jugador{
    private:
        List <Miner> mineros;
        List <Puerta> puertas;
        string nombre;
        Puerta *mapa;
        int cantidad_mat_total = 0; 
        bool enable = true;   

    public:

        void setEnable(bool pEnable){
            this->enable = pEnable;
        }
        void setNombre(string pNombre){
            this->nombre = pNombre;
        }
        string getNombre(){
            return this->nombre;
        }

        void addMinero(Miner *pMinero){
            this->mineros.insert(0,pMinero);
        }
        void setStrategyMiner(Strategy *pEstrategia){
            this->mineros.find(0)->setStrategy(pEstrategia);
        }

        void setMapa(Puerta *pMapa){ 
            this->mapa = pMapa;
        }

        int getCantidadDeMaterial(){
            return this->cantidad_mat_total;
        }
        List<Puerta> recorrerMapa(){
            List<Puerta> cola;
            cola.add(mapa);
            while(true){
                for (int i = 0; i < cola.find(0)->getCantidadDeHijos(); i++){
                    if (cola.find(0)->getPuerta(i) == NULL){                        
                        continue;                        
                    }                    
                    if (cola.find(0)->getPuerta(i) == cola.find(0)->getPadre()){
                        cout << endl;
                        continue;
                    }
                    if (cola.find(0)->getPuerta(i)->getTunel()){                        
                        this->puertas.push(cola.find(0)->getPuerta(i));
                        continue;
                    }
                    cola.add(cola.find(0)->getPuerta(i));
                }
                cola.remove(0);
                if (cola.getSize()==0){return this->puertas;}                
            }  
        }
        
        Miner* getMiner(int pINDEX){
            if (pINDEX >-1 && pINDEX < this->mineros.getSize()){
                return this->mineros.find(pINDEX);
            }
        }
        void recorrerMapaCriterio(Miner *pMinero,int jj){
            Strategy *estrategia_temp = pMinero->getStrategy();
            AVLNode* camaraAct = NULL;        
            Puerta* puertaAct = NULL;    
            int capacidad_Minero = pMinero->getCapacity();            
            int material_aumentado = 0;
            int duracion = 0;            

            while (enable)
            {   
                puertaAct = estrategia_temp->validateCriterioPuerta(this->puertas);
                camaraAct = estrategia_temp->criterioTunel(puertaAct->getTunel()->root); //Retorna un nodo camara
                
                if (camaraAct){

                    duracion = (camaraAct->profundidad / pMinero->getVelocity());
                    //cout << "prof: " << camaraAct->profundidad << " Vel: " << pMinero->getVelocity() << endl;
                    //cout << "canti: " << camaraAct->camara->getCantidadDeMaterial() << endl;

                    material_aumentado = capacidad_Minero;
                    if (camaraAct->camara->getCantidadDeMaterial() < capacidad_Minero){
                        material_aumentado = camaraAct->camara->getCantidadDeMaterial();
                    }

                    camaraAct->camara->decreaseMateriales(capacidad_Minero);
                    if (camaraAct->camara->getCantidadDeMaterial() == 0){ // Para eliminar la camara y sus hijos si el material es 0
                        puertaAct->getTunel()->deletNode(camaraAct->key);
                    }     

                    material_aumentado += pMinero->criterio(camaraAct, material_aumentado,capacidad_Minero);
                    //cout << "Duracion: " << duracion << endl;
                    this_thread::sleep_for(chrono::milliseconds(duracion*1000));
                    if (enable){
                        cout << endl << "El minero "<<  pMinero->getNombre() << ": llego a la camara a minar" << endl;
                        cout << endl << "Encontro " << material_aumentado << endl;
                    }
                    this_thread::sleep_for(chrono::milliseconds(duracion*1000));
                    if (enable){
                        cout << endl << "El minero "<<  pMinero->getNombre() << ": deposito los minerales recolectados" << endl;
                    }   
                    if (!enable){
                        continue;
                    }
                    this->cantidad_mat_total+= material_aumentado;
                    camaraAct = NULL;
                    //cout << "CantidadTot: " << cantidad_mat_total << endl<< endl;
                }
            }
        }

        void runMineros(){
            recorrerMapa();
            for (int j = 0; j < 3; j++)
            {
                Miner *minero = mineros.find(j);
                thread hilo(&Jugador::recorrerMapaCriterio,this,minero,j);
                hilo.detach();
            }
            
            
        }
};

#endif
