#include <iostream>

using namespace std;

#include "archivoJugador.h"
#include "Jugador.h"
#include "opciones.h"
#include "combate.h"

int main()
{
    ArchivoJugador archi;
    Jugador jug;
    jug = archi.leerJugador(0);
    int opc;

    while(jug.get_vida() > 0){
        system("cls");
        cout << "---MENU PRINCIPAL---" << endl;
        cout << "1- Pelear!" << endl;
        cout << "2- Estadisticas" << endl;
        cout << "3- Opciones" << endl;
        cout << "0- Salir" << endl;
        cout << "Ingrese una opcion:";
        cin >> opc;
        cout << endl;

        switch(opc){
            case 0:
                cout << "Se cerrara el juego! Esperemos verte pronto" << endl;
                exit(0);
                break;
            case 1: cout << "Encontrando pelea..." << endl;
                pelea(1,jug);
                break;
            case 2:
                cout << "Cargando estadisticas del jugador..." << endl;
                pelea(2,jug);
                break;
            case 3:
                menuOpciones();
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
