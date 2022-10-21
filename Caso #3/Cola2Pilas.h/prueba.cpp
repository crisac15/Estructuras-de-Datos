#include "Cola2P.h"
#include <iostream>
Cola2P<int> prueba = Cola2P<int>();
int main(int argc, char const *argv[])
{
    prueba.enqueue(1);
    prueba.enqueue(2);
    prueba.enqueue(3);
    prueba.enqueue(4);
    prueba.enqueue(5);
    while (!prueba.isEmpty())
    {
        // prueba.dequeue();
        cout << "Front" << endl;
        cout << prueba.front() << endl;
        cout << "dequeue" << endl;
        cout << prueba.dequeue() << endl;
        cout << "IsEmpty" << endl;
        cout << prueba.isEmpty() << endl;
    }

    return 0;
}
