#include <string>
#include <iostream>
#include "../AVL/AVL.h"

using namespace std;

#ifndef TUNEL
#define TUNEL 1 

class Tunel {
    private:
        AVL *tunel = new AVL();
        int largo;

    public:

        int getLargo(){
            return this->largo;
        }

        void inicializarNodo(){
            
            bool continuar = true;
            while(continuar){

                continuar = tunel->addNodo();                

            }
            
            tunel->root->profundidad = 0;
            tunel->root->camara->setMaterial(0);
            tunel->root->key = 0;

        }
        

        void preOrden(){
            cout << "\n----------------------tunel-----------------------------\n" ;
            tunel->preOrder(tunel->root);
            cout << "-----------------------preorden---------------------------\n" ;
        }

        void right(){
            cout << "\n----------------------tunel-----------------------------\n" ;
            tunel->coutRight(tunel->root->left);
            cout << "-----------------------right---------------------------\n" ;
        }
    
        AVL* getTunel(){
            return this->tunel;
        }
};
#endif