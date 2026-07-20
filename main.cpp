#include <iostream>

using namespace std;

#include "Jugador.h"
#include "combate.h"

int main()
{
    Jugador jug;
    int opc;

    while(jug.get_vida() > 0){
        system("cls");
        cout << "En que direccion te mueves? " << endl;
        cout << "1- Este" << endl;
        cout << "2- Oeste" << endl;
        cout << "3- Norte" << endl;
        cout << "4- Estadisticas" << endl;
        cout << "5- Agregar monstruo" << endl;
        cin >> opc;
        cout << endl;

        switch(opc){
            case 1: cout << "Caminando hacia el Este..." << endl;
                pelea(1,jug);
                break;
            case 2:
                cout << "Caminando hacia el Oeste..." << endl;
                pelea(2,jug);
                break;
            case 3:
                cout << "Caminando hacia el Norte..." << endl;
                pelea(3,jug);
                break;
            case 4:
                cout << "Estadisticas de jugador" << endl;
                pelea(4,jug);
                break;
            case 5:

                break;
            default:
                cout << "No es valida esta opcion. Intente de nuevo" << endl;
                system("pause");
                break;
        }
    }
    system("cls");
    if(jug.get_vida() <= 0){
        cout << "Game Over!" << endl;
    }
}
