#include <string>
#include <iostream>
#include "MainRoom.h"

using namespace std;

int main(){
    MainRoom room = MainRoom(2);
    room.crearPuertas();
    room.showPuerta();

    cout << room.getNumeroDePueras() << "\n";
}