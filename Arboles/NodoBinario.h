#ifndef _NODOBINARIO_H
#define _NODOBINARIO_H
// template <class T>
class NodoBinario
{
    // private:
    //     // T clase;
    //     int valor;
    //     int FB;
    //     NodoBinario *Hizq, *Hder, *siguiente, *anterior;

public:
    int valor;
    int FB;
    NodoBinario *Hizq, *Hder, *siguiente, *anterior;
    NodoBinario(int num, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig = NULL, NodoBinario *ant = NULL) : Hizq(izq), Hder(der), valor(num), siguiente(sig), anterior(ant), FB(0) {}

    // NodoBinario(int num, T pClass)
    // {
    //     this->clase = pClass;
    //     this->valor = num;
    //     this->FB = 0;
    //     this->Hizq = NULL;
    //     this->Hder = NULL;
    //     this->siguiente = NULL;
    //     this->anterior = NULL;
    // }

    friend class Pila;
    friend class Binario;

    void InsertaBinario(int num);
};
typedef NodoBinario *pnodo;
typedef NodoBinario *pNodoBinario;

void PreordenR(NodoBinario *R);
void InordenR(NodoBinario *R);
void PostordenR(NodoBinario *R);
#endif
