#include <iostream>
#include "../time/TimeMain.h"

using namespace std;

int main()
{

    TimeMain *tiempo = new TimeMain();
    tiempo->init();
    tiempo->run1();
    // system("pause");
    tiempo->run2();
    // system("pause");
}