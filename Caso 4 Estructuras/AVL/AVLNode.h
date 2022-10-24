#include <iostream>
#include "Camara.h"
using namespace std;

#ifndef AVLNODE

#define AVLNODE 1

class AVLNode{
    public:   
        Camara *camara = new Camara();     
        int largo; // 10 a 80
        int profundidad = 0; // distancia con respecto a la base // largo + profundidad del nodo antecesor
        int key;
        AVLNode *antecesor;
        AVLNode *left;
        AVLNode *right;
        int height;
        bool enable = true;
        
};
#endif