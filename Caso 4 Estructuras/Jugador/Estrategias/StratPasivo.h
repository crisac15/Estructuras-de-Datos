#include <iostream>
#include "../Strategy.h"

using namespace std;


#ifndef PASIVO

#define PASIVO 1

class Pasivo: public Strategy{
    private:
        AVLNode *node_temp = new AVLNode();
    public:
        Pasivo(){
            this->setNombre("Pasivo");
        }
        
        AVLNode* criterioTunel(AVLNode* pNodeCam){

            if(pNodeCam->camara->getCantidadDeMaterial() > node_temp->camara->getCantidadDeMaterial()){ //Entra en la primer camara con material que encuentr
                node_temp = pNodeCam;
            }
            if (pNodeCam->right){
                criterioTunel(pNodeCam->right);
            }else if (pNodeCam->left){
                criterioTunel(pNodeCam->left);
            }
            return node_temp;
        }
        
        Puerta* validateCriterioPuerta(List<Puerta> pPuertas) 
        {
            int mayor = 0;
            int pos;
            for (int i = 0; i < pPuertas.getSize(); i++)
            {   
                int temp = pPuertas.find(i)->getTunel()->Theight();
                if (temp > mayor){
                    mayor = temp;
                    pos = i;
                }
            }
            return pPuertas.find(pos);
        }
};
#endif