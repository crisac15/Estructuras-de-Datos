#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>
using namespace std;
#include "Stack.h"
#include "Cola.h"
Queue<char> Cola = Queue<char>();
// genera prioridad
int prioridad(char pChar)
{
    switch (pChar)
    {
    case '^':
        return 3;
    case '/':
        return 2;
    case '*':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}
string mostrar()
{
    List guardar = List();
    string res = " ";
    while (Cola.size() > 0)
    {
        res += Cola.front();
        guardar.add(Cola.front());
        Cola.dequeue();
    }
    for (int i = 0; i < guardar.getSize(); i++)
    {
        Cola.enqueue(guardar.find(i));
    }
    return res;
}
// infija to post fija
void infToPost()
{
    string pInf;
    cout << " Ingrese una expresion en notación infija: " << endl;
    cin >> pInf;
    int i = 0;
    char simb;
    Stack<char> Pila = Stack<char>();
    while (i < pInf.size())
    {
        switch (pInf[i])
        {
        case '(':
            Pila.Push(pInf[i]);
            break;
        case ')':
            while (Pila.Top() != '(')
            {
                simb = Pila.Top();
                Pila.Pop();
                Cola.enqueue(simb);
            }
            Pila.Pop();
            break;
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            while (prioridad(pInf[i]) <= prioridad(Pila.Top()))
            {
                simb = Pila.Top();
                Pila.Pop();
                Cola.enqueue(simb);
            }
            Pila.Push(pInf[i]);
            break;
        default:
            Cola.enqueue(pInf[i]);
            break;
        }
        i++;
    }
    while (Pila.size() != 0)
    {
        simb = Pila.Top();
        Pila.Pop();
        Cola.enqueue(simb);
    }
    cout << "la notacion ingresada: " << pInf << " es equivalente en notacion Postfija a: " << mostrar() << endl;
}
void eval()
{
    Stack<float> PilaEval = Stack<float>();
    float x, y, res;
    char simb;
    while (Cola.size() > 0)
    {
        simb = Cola.front();
        Cola.dequeue();
        switch (simb)
        {
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            y = PilaEval.Top();
            PilaEval.Pop();
            x = PilaEval.Top();
            PilaEval.Pop();
            switch (simb)
            {
            case '*':
                res = x * y;
                break;
            case '/':
                res = x / y;
                break;
            case '+':
                res = x + y;
                break;
            case '-':
                res = x - y;
                break;
            case '^':
                res = pow(x, y);
                break;
            }
            PilaEval.Push(res);
            break;
        default:
            PilaEval.Push(simb - '0');
            break;
        }
    }
    cout << "El resultado de evaluar su notacion postfija es: " << PilaEval.Top() << endl;
}

int main()
{
    infToPost();
    eval();
    return 0;
}