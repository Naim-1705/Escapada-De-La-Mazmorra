#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "combate.h"
#include "Jugador.h"
#include "Monstruo.h"
#include "archivoEspada.h"
#include "archivoMonstruo.h"

int vidaMos;
int vidaJug;
int damageMitigado;
bool turnoJug;
int opc;
int cdHab1Jug = 0;
int cdHab1Mon = 0;
int completeJug;
int completeMon;

void pelea(int sala,Jugador &jug){
    srand(time(nullptr));
    Monstruo mos;
    ArchivoMonstruo archiMon;
    int total, random;
    switch(sala){
    case 1:
        total = archiMon.cantidadMonstruo();
        mos.set_nombre(" ");
        while(strcmp(mos.get_nombre()," ") == 0){
            random = rand() % (total + 1);
            mos = archiMon.leerMonstruo(random);
        }
        cout <<  "Te encontraste con un " << mos.get_nombre() << "!" << endl;
        system("pause");
        enfrentamiento(mos,jug);
        break;
    case 2:
        cout << "Estadisticas del jugador:" << endl;
        jug.mostrar();
        cout << endl;
        system("pause");
        break;
    }
}

void enfrentamiento(Monstruo &mos,Jugador &obj){

    ///Se define el turno al azar
    int turnoAzar = rand() % 1;
    if(turnoAzar == 0){
        turnoJug = true;
    }
    else{
        turnoJug = false;
    }

    int armor,attack;
    cdHab1Jug = 0;
    cdHab1Mon = 0;

    while(mos.get_vida() > 0 && obj.get_vida() > 0){
        system("cls");
        cout << "JUGADOR: " << endl;
        obj.mostrar();
        cout << endl;

        cout << "MONSTRUO: " << endl;
        mos.mostrar();
        cout << endl;

        completeJug = 0;
        completeMon = 0;

        if(cdHab1Jug > 0){
            cdHab1Jug = cdHab1Jug - 1;
        }
        if(cdHab1Mon > 0){
            cdHab1Mon = cdHab1Mon - 1;
        }

        system("pause");

        ///PARA EL TURNO DEL JUGADOR
        if(turnoJug == true && obj.get_vida() > 0){
            while(completeJug == 0){
                cout << "Tu turno!" << endl;
                cout << endl;
                cout << "Que movimiento haras?" << endl;
                cout << "1- Usar la Espada" << endl;
                cout << "2- Usar la habilidad " << obj.get_ability().get_nombre() << endl;
                cout << "Elije una opcion:";
                cin >> opc;
                cout << endl;

                switch(opc){
                case 1:
                    attack = obj.get_damage() + obj.get_sword().get_damage();
                    damageMitigado = mos.get_armadura() - attack;
                    if(damageMitigado < 0){
                        vidaMos = mos.get_vida() + damageMitigado;
                        if(vidaMos <= 0){
                            cout << "El combate termino" << endl;
                            mos.set_vida(0);
                        }
                        else{
                            mos.set_vida(vidaMos);
                            cout << "Hit!" << damageMitigado << " Damage!" << endl;
                        }
                    }
                    else{
                        cout << "El damage a sido completamente mitigado" << endl;
                    }
                    completeJug = 1;
                    break;
                case 2:
                    if(cdHab1Jug == 0){
                        damageMitigado = mos.get_armadura() - obj.get_ability().get_damage();
                        if(damageMitigado < 0){
                            vidaMos = mos.get_vida() + damageMitigado;
                            if(vidaMos <= 0){
                                cout << "El combate termino" << endl;
                                mos.set_vida(0);
                            }
                            else{
                                mos.set_vida(vidaMos);
                                cout << "Hit! " << damageMitigado << " Damage!" << endl;
                            }
                        }
                        else{
                            cout << "El damage a sido completamente mitigado" << endl;
                        }
                        completeJug = 1;
                        cdHab1Jug = obj.get_ability().get_cooldown();
                    }
                    else{
                        cout << "Esta habilidad esta en CD!" << endl;
                    }
                    break;
                }
            }
            turnoJug = false;
            system("pause");
        }

        ///TURNO DEL MONSTRUO
        if(turnoJug == false && mos.get_vida() > 0){
            cout << "Turno del Monstruo!" << endl;
            cout << endl;

            while(completeMon == 0){
                opc = rand() % 2 + 1;

                switch(opc){
                case 1:
                    armor = obj.get_armadura() + obj.get_armor().get_Aguante();
                    damageMitigado = armor - mos.get_ataque();
                    if(damageMitigado < 0){
                        vidaJug = obj.get_vida() + damageMitigado;
                        if(vidaJug <= 0){
                            cout << "El combate termino" << endl;
                            obj.set_vida(0);
                        }
                        else{
                            obj.set_vida(vidaJug);
                            cout << "Hit!" << damageMitigado << " Damage!" << endl;
                        }
                    }
                    else{
                        cout << "El damage a sido completamente mitigado" << endl;
                    }
                    completeMon = 1;
                    break;
                case 2:
                    if(cdHab1Mon == 0){
                        armor = obj.get_armadura() + obj.get_armor().get_Aguante();
                        damageMitigado = armor - mos.get_habilidad().get_damage();
                        if(damageMitigado < 0){
                            vidaJug = obj.get_vida() + damageMitigado;
                            if(vidaJug <= 0){
                                cout << "El combate termino" << endl;
                                obj.set_vida(0);
                            }
                            else{
                                obj.set_vida(vidaJug);
                                cout << "Hit! " << damageMitigado << " Damage!" << endl;
                            }
                        }
                        else{
                            cout << "El damage a sido completamente mitigado" << endl;
                        }
                        completeMon = 1;
                        cdHab1Mon = mos.get_habilidad().get_cooldown();
                    }
                    else{
                        cout << "Esta habilidad esta en CD!" << endl;
                    }
                    break;
                }
            }
            turnoJug = true;
            system("pause");
        }
    }
}
