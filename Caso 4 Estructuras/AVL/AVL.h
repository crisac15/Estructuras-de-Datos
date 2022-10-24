#include <bits/stdc++.h>
#include "AVLNode.h"
using namespace std;

#ifndef AVL2

#define AVL2 1

class AVL{
    private:
        int profundidadActual;
        int largo;
        int profundidad = 0;
        int material;
    public:
        AVLNode *root = NULL;

        AVLNode* search(AVLNode* root, int pkey) 
        {
            AVLNode *searched = NULL;
            if(root!=NULL){
                if (root->key == pkey){ 
                    searched = root;
                }
                else if (root->key < pkey){
                    search(root->right, pkey);
                }
                
                else{
                    search(root->left, pkey);
                }
            }
            return searched;
        }

        bool deletNode(int pKey){
            AVLNode* delete_node = search(root, pKey);
            if (delete_node){
                cout << endl << endl << " se elimino la camara " << endl << endl;
                delete_node = NULL;
                return true;
            }
            return false;
        }

        int height(AVLNode *N)
        {
            if (N == NULL)
                return 0;
            return N->height;
        }

        int Theight()
        {
            height(root);
        }

        int max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        AVLNode *newNode(int pKey, AVLNode *pAnt)
        {
            AVLNode *node = new AVLNode();
        
            node->key = pKey;
            node->largo = this->largo;
            node->camara->setMaterial(material);
            node->left = NULL;
            node->right = NULL;
            node->height = 1; 
            if (pAnt != NULL){
                node->antecesor = pAnt;
                node->profundidad = node->antecesor->profundidad + node->largo;
                this->profundidad = node->profundidad;
            }            
            return (node);
        }

        AVLNode *rightRotate(AVLNode *y)
        {
            AVLNode *x = y->left;
            AVLNode *T2 = x->right;

            x->right = y;
            y->left = T2;

            y->height = max(height(y->left),
                            height(y->right)) +
                        1;
            x->height = max(height(x->left),
                            height(x->right)) +
                        1;
            return x;
        }

        AVLNode *leftRotate(AVLNode *x)
        {
            AVLNode *y = x->right;
            AVLNode *T2 = y->left;

            y->left = x;

            x->right = T2;

            x->height = max(height(x->left),
                            height(x->right)) +
                        1;
            y->height = max(height(y->left),
                            height(y->right)) +
                        1;

            return y;
        }

        int getBalance(AVLNode *N)
        {
            if (N == NULL)
                return 0;
            return height(N->left) - height(N->right);
        }
        
        AVLNode *insert(AVLNode *node, int key, AVLNode *pAnt)
        {

            if (node == NULL){
                return (newNode(key, pAnt));
            }                     
            if (key < node->key){             
                node->left = insert(node->left, key, node);  
            }                
            else if (key > node->key){              
                node->right = insert(node->right, key, node);
            }
                
            else{
                return node;
            } 
                

            node->height = 1 + max(height(node->left),
                                height(node->right));

            int balance = getBalance(node);

            if (balance > 1 && key < node->left->key)
                return rightRotate(node);

            if (balance < -1 && key > node->right->key)
                return leftRotate(node);

            if (balance > 1 && key > node->left->key)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            if (balance < -1 && key < node->right->key)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            return node;
        }

        void preOrder(AVLNode *root)
        {
            if (root != NULL)
            {
                cout << " | " << root->key << " : " << root->profundidad <<  " : " << root->largo <<   " | \n";
                cout << "   <             >" << endl;
                preOrder(root->left);
                preOrder(root->right);
                cout <<  endl;
            }
        }

        void coutRight(AVLNode *root)

        {
            if (root != NULL)
            {
                cout << " | " << root->key << " : " << root->profundidad <<  " : " << root->largo <<   " : " << root->camara->getCantidadDeMaterial() <<" | \n";
                coutRight(root->right);
            }
        }

        int getProfunidadActual(){
            return this->profundidadActual;
        }
        bool addNodo(){
            largo = rand() % 71 + 10;    
            material = rand() % 20 + 1;
            int key = material * profundidad;

            if (root == NULL){
                profundidad = largo;
            }
            if (profundidad >= 720){
                return false;
            }

            this->root = insert(this->root, key, root);

            return true;
        }
        
};
#endif
