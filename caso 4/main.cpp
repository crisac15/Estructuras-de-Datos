#include <iostream>
#include <thread>

using namespace std;

void food()
{
    cout << "food" << endl;
}

int main()
{
    cout << "Hello World";
    thread hilo(food);
    hilo.join();

    return 0;
}
