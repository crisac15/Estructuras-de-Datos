#include <string>
#include <iostream>
#include "MainRoom.h"

using namespace std;

int main(){
    MainRoom room = MainRoom(20);
    room.crearPuertas();
    room.showPuerta();

    cout << room.getNumeroDePueras() << "\n";
}