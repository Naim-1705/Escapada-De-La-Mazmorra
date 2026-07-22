#include <iostream>
#include <cstring>

using namespace std;

#include "combate.h"
#include "Jugador.h"
#include "Monstruo.h"

int vidaMos;
int vidaJug;
bool turnoJug = true;
int opc;
void cargarMonstruo();
void dardeBajaMonstruo();

void pelea(int sala,Jugador &jug){
    Monstruo mos;
    switch(sala){
    case 1:
        mos.set_nombre("Duende");
        mos.set_vida(50);
        mos.set_ataque(15);
        cout << "Te encontraste un " << mos.get_nombre() << "!" << endl;
        system("pause");
        enfrentamiento(mos,jug);
    break;
    case 2:
        mos.set_nombre("Lobo");
        mos.set_vida(75);
        mos.set_ataque(20);
        cout << "Te encontraste un " << mos.get_nombre() << "!" << endl;
        system("pause");
        enfrentamiento(mos,jug);
    break;
    case 3:
        mos.set_nombre("Dragon");
        mos.set_vida(200);
        mos.set_ataque(50);
        cout << "Te encontraste un " << mos.get_nombre() << "!" << endl;
        system("pause");
        enfrentamiento(mos,jug);
    break;
    case 4:
        cout << "JUGADOR:" << endl;
        cout << "Vida: " << jug.get_vida() << endl;
        cout << "Damage de Espada: " << jug.get_espada() << endl;
        cout << "Damage de Arco: " << jug.get_arco() << endl;
        system("pause");
        break;
    }
}

void enfrentamiento(Monstruo &mos,Jugador &obj){
    while(mos.get_vida() > 0 && obj.get_vida() > 0){
        system("cls");
        cout << "JUGADOR: " << endl;
        cout << "Vida: " << obj.get_vida() << endl;
        cout << "Damage de Arco: " << obj.get_arco() << endl;
        cout << "Damage de Espada: " << obj.get_espada() << endl;

        cout << endl;

        cout << "MONSTRUO: " << mos.get_nombre() << endl;
        cout << "Vida: " << mos.get_vida() << endl;
        cout << "Ataque: " << mos.get_ataque() << endl;

        system("pause");

        if(turnoJug == true && obj.get_vida() > 0){
            cout << "Tu turno!" << endl;
            cout << endl;
            cout << "Elige tu arma: " << endl;
            cout << "1-Espada" << endl;
            cout << "2-Arco" << endl;
            cin >> opc;
            cout << endl;

            if(opc == 1){
                vidaMos = mos.get_vida() - obj.get_espada();
                if(vidaMos <= 0){
                    cout << "El combate termino" << endl;
                    mos.set_vida(0);
                }
                else{
                    mos.set_vida(vidaMos);
                    cout << "Hit!" << obj.get_espada() << " Damage!" << endl;
                }
            }
            if(opc == 2){
                vidaMos = mos.get_vida() - obj.get_arco();
                if(vidaMos <= 0){
                    cout << "El combate termino" << endl;
                    mos.set_vida(0);
                }
                else{
                    mos.set_vida(vidaMos);
                    cout << "Hit! " << obj.get_arco() << " Damage!" << endl;
                }
            }
            turnoJug = false;
            system("pause");
        }
        if(turnoJug == false && mos.get_vida() > 0){
            cout << "Turno del Monstruo!" << endl;
            cout << endl;
            vidaJug = obj.get_vida() - mos.get_ataque();
            if(vidaJug <= 0){
                cout << "El combate termino" << endl;
                obj.set_vida(0);
            }
            else{
                obj.set_vida(vidaJug);
                cout << "Hit! " << mos.get_ataque() << " Damage!" << endl;
            }
            turnoJug = true;
            system("pause");
        }
    }
}

void admin(){
    int opc;
    bool seguir = true;
    while(seguir){
        cout << "-----MENU DE ADMINISTRACION-----" << endl;
        cout << "1- Cargar" << endl;
        cout << "2- Dar de baja" << endl;
        cout << "0- Salir" << endl;

        cout << "Ingrese una opcion: ";
        cin >> opc;
        cout << endl;

        switch(opc){
            case 1: cargarMonstruo();
            break;
            case 2: dardeBajaMonstruo();
            break;
            case 0: seguir = false;
            break;
        }
    }
}

void cargarMonstruo(){
    ArchivoMonstruo archi;
    if(archi.agregarMonstruo() == -1){
        cout << "Error de memoria" << endl;
    }
    if(archi.agregarMonstruo() == -2){
        cout << "No se pudo cargar la memoria" << endl;
    }
    if(archi.agregarMonstruo > 0){
        cout << "Cargado con exito" << endl;
    }
}

void dardeBajaMonstruo(){
    ArchivoMonstruo archi;
    Monstruo mons;
    char nombre[20];
    int contador = archi.cantidadMonstruo();

    cout << "Indique el nombre del Monstruo a dar de Baja: ";
    cin >> nombre;
    cout << endl;

    for(int i = 0; i < contador; i++){
        mons = archi.leerMonstruo(i);
        if(strcmp(mons.get_nombre(),nombre)==1){

        }
    }
}
