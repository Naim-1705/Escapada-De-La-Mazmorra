#include <iostream>

using namespace std;

#include "Jugador.h"
#include "Monstruo.h"

int main()
{
    Jugador obj;
    Monstruo mos;
    int vidaMos;
    int vidaJug;
    bool turnoJug = true;

    cout << "COMIENZA EL COMBATE!!" << endl;
    cout << endl;

    int opc;

    while(mos.get_vida() > 0 && obj.get_vida() > 0){
        system("cls");
        cout << "JUGADOR: " << endl;
        cout << "Vida: " << obj.get_vida() << endl;
        cout << "Damage de Arco: " << obj.get_arco() << endl;
        cout << "Damage de Espada: " << obj.get_espada() << endl;

        cout << endl;

        cout << "MONSTRUO: " << endl;
        cout << "Vida: " << mos.get_vida() << endl;
        cout << "Ataque: " << mos.get_ataque() << endl;

        system("pause");

        if(turnoJug == true){
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
        }

        system("pause");

        if(turnoJug == false){
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
        }
        system("pause");
    }

    if(mos.get_vida() == 0){
        cout << "Ganaste!" << endl;
    }
    else if(obj.get_vida() == 0){
        cout << "Game Over!" << endl;
    }
}
