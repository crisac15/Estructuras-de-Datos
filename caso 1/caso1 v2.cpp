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
    bool resultado = true;
    int asignar[4] = {1, 2, 3, 4};
    short posi = 0;

    for (int i = 0; i < 20; i++) // por cada zona
    {
        if (mapa[i].color == 0) // si no tiene color asignado
        {
            mapa[i].color = 1;          // le asigno el primer color
            for (int j = 0; j < 8; j++) // 8 iteraciones
            {
                if (mapa[i].adyacentes[j] != 0) // (si el adyacente no es 0)
                {

                    if (mapa[mapa[i].adyacentes[j] - 1].color == 1) // el adyacente es 1 tambien? si es así, entonces sos 2
                    {
                        mapa[i].color = 2;

                        if (mapa[i].color = 2)
                        {
                            if (mapa[mapa[i].adyacentes[j] - 1].color == 2) // el adyacente es 2 tambien? si es así, entonces sos 3
                            {
                                mapa[i].color = 3;
                            }
                        }
                        if (mapa[i].color = 3)
                        {
                            if (mapa[mapa[i].adyacentes[j] - 1].color == 3) // el adyacente es 3 tambien? si es así, entonces sos 4
                            {
                                mapa[i].color = 4;
                            }
                        }
                        if (mapa[i].color = 4)
                        {
                            if (mapa[mapa[i].adyacentes[j] - 1].color == 4) // el adyacente es 4 tambien? si es así, entonces sos  FALSO, no puedes ser ninguno
                            {
                                resultado = false;
                            }
                        }
                    }
                }
                cout << "Zona:" << mapa[i].num << "   " << mapa[i].color << "   "
                     << "adyacente:" << mapa[mapa[i].adyacentes[j] - 1].color << endl;
            }
        }

        cout << i << endl;
    }
    for (int i = 0; i < 20; i++)
    {
        cout << "Zona:" << mapa[i].num << endl;
        cout << "color:" << mapa[i].color << endl;
        cout << endl;
    }

    return resultado;
}