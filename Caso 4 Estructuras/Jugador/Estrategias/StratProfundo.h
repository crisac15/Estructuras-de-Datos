#include <iostream>
#include "../Strategy.h"

using namespace std;


#ifndef HASTAELFONDO

#define HASTAELFONDO 1

class Profundo: public Strategy{
    private:
        AVLNode *node_temp = new AVLNode();
    public:
        Profundo(){
            this->setNombre("Profundo");
        }
        
        AVLNode* criterioTunel(AVLNode* pNodeCam){
            if(pNodeCam->profundidad > node_temp->profundidad){ //Entra en la primer camara con material que encuentr
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
                //cout << temp <<  " : " << mayor << endl;
                if (temp > mayor){
                    mayor = temp;
                    pos = i;
                    //cout << pos << " : " << mayor << endl;
                }
            }
            return pPuertas.find(pos);
        }
};
#endif