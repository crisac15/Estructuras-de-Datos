#include <iostream>
#include "../Miner.h"

using namespace std;



class Topo : public Miner{
    public:
        Topo()
        {        
            this->setNombre("Topo");
            this->setCapacidad(15);
            this->setVelocidadMovimiento(7);
        }

        int criterio(AVLNode* pNode, int pCantidadActual, int pCapacidad){
            if (pCantidadActual >= pCapacidad){
                return 0;
            }
            int diferencia = pCapacidad - pCantidadActual;
            AVLNode* padre = pNode->antecesor;
            AVLNode* actual;
            if (pNode->key > padre->key){
                
                actual =  padre->left;
            }else{
                actual =  padre->right;
            }
            int material_aumentado = diferencia;
            if (pNode->camara->getCantidadDeMaterial() < diferencia){
                material_aumentado = pNode->camara->getCantidadDeMaterial();                
            }

            pNode->camara->decreaseMateriales(material_aumentado);
            cout << endl <<"el topo se cruzo" << endl;
            return material_aumentado;
        }
    };
