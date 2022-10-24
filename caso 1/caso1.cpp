#include <iostream>
#include <conio.h>
using namespace std;
struct zona
{
    int num;
    int color;
    int adyacentes[8];
};

int main()
{
    // Se define el mapa ingresando el número de zona, el color asignado (0 para que el algoritmo asigne todos los colores) o forzarlo para que indique error
    //  y mediante un arreglo se anotan los número de las zonas adyacentes. El número de zonas (20) debe ser asignado en la variable tipo zona "mapa" y el número de
    //  adyacentes máximos de una zona (8 en este caso) define el número de datos que debe asignarse en la variable adyacentes definida en el struct.
    zona mapa[20] = {
        {1, 0, {2, 3}},
        {2, 0, {1, 3, 5}},
        {3, 0, {1, 2, 4, 5, 6}},
        {4, 0, {3, 6, 20}},
        {5, 0, {2, 3, 6, 7, 9}},
        {6, 0, {3, 4, 5, 7, 12, 20}},
        {7, 0, {5, 6, 8, 11}},
        {8, 0, {7, 9}},
        {9, 0, {5, 8, 10}},
        {10, 0, {9, 11, 13, 14}},
        {11, 0, {7, 10, 12, 13, 20}},
        {12, 0, {6, 11, 20}},
        {13, 0, {10, 11, 14, 15, 16, 17, 18, 19}},
        {14, 0, {10, 13, 15}},
        {15, 0, {13, 14, 16}},
        {16, 0, {13, 15, 17}},
        {17, 0, {13, 16, 18, 20}},
        {18, 0, {13, 17, 19, 20}},
        {19, 0, {13, 18, 20}},
        {20, 0, {4, 6, 11, 12, 17, 18, 19}}};

    bool resultado = true;           // booleano que indica si cumple o no
    short asignar[4] = {1, 2, 3, 4}; // número de colores

    for (short i = 0; i < 20; i++) // un for que itera cada zona del Mapa
    {
        if (mapa[i].color == 0) // si no tiene color asignado
        {

            for (short j = 0; j < 8; j++) // itera en los adyacentes
            {
                if (mapa[i].adyacentes[j] != 0) // ignora los adyacentes que sean 0, esto para ahorrar iteraciones en aquellas que no cumplen con el número másximo de adyacentes
                {
                    if (mapa[i].color == 0) // a partir de aquí, una serie de condiciones que comprueban el color que debe asignarse si de acuerdo a sus adyacentes.
                    {
                        mapa[i].color = 1;
                    }
                    if (mapa[i].color == 1 && mapa[mapa[i].adyacentes[j] - 1].color == 1)
                    {
                        mapa[i].color = 2;
                    }
                    else if (mapa[i].color == 2 && mapa[mapa[i].adyacentes[j] - 1].color == 2)
                    {
                        mapa[i].color = 3;
                    }
                    else if (mapa[i].color == 3 && mapa[mapa[i].adyacentes[j] - 1].color == 3)
                    {
                        mapa[i].color = 4;
                    }
                    else if (mapa[i].color == 4 && mapa[mapa[i].adyacentes[j] - 1].color == 4) // si intentó ser un 4 y no pudo porque este ultimo color tambien está entre los adyacentes:
                    {
                        resultado = false; // entonces la variable resultado cambia a false
                    }
                }
            }
        }
        cout << endl;
    }
    for (short i = 0; i < 20; i++) // Recorre todo el mapa modificado imprimiendo el número de zona y el color que le asignó
    {
        cout << "número de Zona:" << mapa[i].num << endl;
        cout << "color asignado por algoritmo:" << mapa[i].color << endl;
        cout << endl;
    }
    if (resultado) // Pregunta si se cumple con el teorema, si es así, lo indica
    {
        cout << "El mapa ingresado cumple con el teorema de 4 colores, se puede pintar con 4 o menos colores sin que sean adyacentes dos colores iguales" << endl;
    }
    else // si no es así, también lo indica
    {
        cout << "El mapa ingresado NO cumple con el teorema de 4 colores, hay 2 o más zonas adyacentes con el mismo color" << endl;
    }
    cout << "yo que se 2" << endl;
    return 0;
}