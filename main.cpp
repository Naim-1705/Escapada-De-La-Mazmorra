#include <iostream>

using namespace std;

#include "Jugador.h"
#include "Monstruo.h"
#include "combate.h"

int main()
{
    Jugador jug;
    int opc;

    while(jug.get_vida() > 0){
        system("cls");
        cout << "Elije a que sala entrar: " << endl;
        cout << "Sala 1" << endl;
        cout << "Sala 2" << endl;
        cout << "Sala 3" << endl;
        cin >> opc;
        cout << endl;

        switch(opc){
            case 1: cout << "Entrando a la sala 1..." << endl;
                pelea(1);
                break;
            case 2:
                cout << "Entrando a la sala 2..." << endl;
                pelea(2);
                break;
            case 3:
                cout << "Entrando a la sala 3..." << endl;
                pelea(3);
                break;
        }
    }
    system("cls");
    if(jug.get_vida() <= 0){
        cout << "Game Over!" << endl;
    }
}
