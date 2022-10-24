#include <iostream>
#include "../Strategy.h"

using namespace std;


#ifndef AGRESIVO

#define AGRESIVO 1

class Agresivo: public Strategy{
    public:
        Agresivo(){
            this->setNombre("Agresivo");
        }
        
        AVLNode* criterioTunel(AVLNode* pNodeCam){
            if (!pNodeCam){
                return NULL;
            }
            if(pNodeCam->camara->getCantidadDeMaterial()){ //Entra en la primer camara con material que encuentr
                //cout << "crit tunel " << pNodeCam->camara->getCantidadDeMaterial() <<  endl;
                return pNodeCam;
            }
            if (pNodeCam->right){
                criterioTunel(pNodeCam->right);
            }else if (pNodeCam->left){
                criterioTunel(pNodeCam->left);
            }
            
            
        }
        
        Puerta* validateCriterioPuerta(List<Puerta> pPuertas) 
        {
            for (int i = 0; i < pPuertas.getSize(); i++)
            {
                if(pPuertas.find(i)->getTunel()){ // Como es agresivo entra en la primer puerta que encuentre 
                    return pPuertas.find(i);
                }    
            }

            return NULL;
        }
};
#endif