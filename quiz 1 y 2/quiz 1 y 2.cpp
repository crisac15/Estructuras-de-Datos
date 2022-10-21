#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
int main()
{
    int tren[5][10] = {
        {1, 0, 0, 0, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 0}};
    int contador = 0;
    int primeros[10];
    int posi = 0;
    int disponibles = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int asiento = tren[i][j];
            if (asiento == 0)
            {
                contador++;
                primeros[posi] = contador;
                posi++;
                disponibles++;
            }
            else
            {
                contador++;
            }
        }
    }
    int lugar = 0;
    cout << "Los 10 primeros asientos disponibles en el tren corresponden a los números::" << endl;
    while (lugar < 10)
    {
        cout << primeros[lugar] << endl;
        lugar++;
    }
    cout << "Los ultimos 10 asientos disponibles en el tren corresponden a los números:" << endl;
    while (lugar > 0)
    {
        disponibles = disponibles - 1;
        cout << primeros[disponibles] << endl;
        lugar = lugar - 1;
    }
    return 0;
}
