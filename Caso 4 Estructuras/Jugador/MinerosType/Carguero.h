#include <iostream>
#include "../Miner.h"

using namespace std;

class Carguero : public Miner
{
    public:
        Carguero()
        {        
            
            this->setNombre("Carguero");
            this->setCapacidad(40);
            this->setVelocidadMovimiento(10);

        }
        int criterio(AVLNode* pNode, int pCantidadActual, int pCapacidad){
            return 0;
        }

};
