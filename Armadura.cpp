#include <iostream>

using namespace std;

#include <cstring>
#include "Armadura.h"
#include "archivoArmadura.h"

///SETTERS
void Armadura::set_Nombre(const char* _nombre){
    strcpy(nombre,_nombre);
}

void Armadura::set_Aguante(int _aguante){
    if(_aguante > 0){
        aguante = _aguante;
    }
}

void Armadura::set_Durabilidad(int _durabilidad){
    if(_durabilidad > 0){
        durabilidad = _durabilidad;
    }
}

void Armadura::set_Estado(bool _estado){
    estado = _estado;
}

///CARGAR

bool Armadura::cargar(){
    Armadura reg;
    ArchivoArmadura archi;

    int cantidad = archi.cantidadArmadura();

    cout << "Ingrese el nombre de la Armadura: ";
    cin >> nombre;
    cout << endl;

    for(int i = 0; i < cantidad; i++){
        reg = archi.leerArmadura(i);
        if(strcmp(reg.get_Nombre(),nombre) == 0 && reg.get_Estado()){
            cout << "Esta Armadura ya esta creada" << endl;
            return false;
        }
    }

    cout << "Ingrese el aguante de la Armadura: ";
    cin >> aguante;
    cout << endl;

    while(aguante <= 0){
        cout << "Este valor es invalido. Ingrese un valor valido: ";
        cin >> aguante;
        cout << endl;
    }

    cout << "Ingrese la durabilidad de la Armadura: ";
    cin >> durabilidad;
    cout << endl;

    while(durabilidad <= 0){
        cout << "Este valor es invalido. Ingrese un valor valido: ";
        cin >> durabilidad;
        cout << endl;
    }

    estado = true;
    return true;
}

///MOSTRAR

void Armadura::mostrar(){
    cout << "Nombre de la Armadura: " << nombre << endl;
    cout << "Aguante: " << aguante << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Estado: " << estado << endl;
}
