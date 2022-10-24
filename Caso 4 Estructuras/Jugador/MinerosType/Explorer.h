#include <iostream>
#include "../Miner.h"

using namespace std;

class Explorer : public Miner
{
public:
    Explorer()
    {        
        this->setNombre("Explorer");
        this->setCapacidad(8);
        this->setVelocidadMovimiento(20);
    }

    int criterio(AVLNode* pNode, int pCantidadActual, int pCapacidad){
        return 0;
    }

};
