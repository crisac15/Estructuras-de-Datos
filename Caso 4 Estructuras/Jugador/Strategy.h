#include <iostream>
#include <string>
//#include <map>
#include "../Mapa/Puerta.h"
using namespace std;

#ifndef STRATEGY 

#define STRATEGY 1

class Strategy{
    private:
        string nombre;
    public:
        void setNombre(string pNombre){
            this->nombre = pNombre;
        }
        string getNombre(){
            return this->nombre;
        }
        virtual AVLNode* criterioTunel(AVLNode* pNodeCam){
            return NULL;
        }
        virtual Puerta* validateCriterioPuerta(List<Puerta> pPuerta){
            return NULL;
        }
};

#endif