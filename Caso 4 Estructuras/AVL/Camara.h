#include <iostream>

#ifndef CAMARA
#define CAMARA 1
class Camara{
    private:
        int materiales = 0;
    public:
        
        void decreaseMateriales(int pCantidad){
            if (this->materiales-pCantidad >= 0){ 
                this->materiales -= pCantidad;
            }else{
                this->materiales = 0;
            }
        }
        void setMaterial(int pMaterial){
            this->materiales = pMaterial;
        }
        int getCantidadDeMaterial(){
            return this->materiales;
        }

};
#endif