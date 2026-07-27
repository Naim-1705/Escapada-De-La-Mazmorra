#include <iostream>

using namespace std;

#include <cstring>
#include "Espada.h"
#include "archivoEspada.h"

///SETTERS
void Espada::set_nombre(const char* _nombre){
    strcpy(nombre,_nombre);
}
void Espada::set_damage(int _damage){
    if(_damage >= 0){
        damage = _damage;
    }
}
void Espada::set_durabilidad(int _durabilidad){
    if(_durabilidad >= 0){
        durabilidad = _durabilidad;
    }
}
void Espada::set_estado(bool _estado){
    estado = _estado;
}

///CARGAR
bool Espada::cargar(){
    ArchivoEspada archi;
    Espada armor;

    int contador = archi.cantidadEspada();

    cout << "Ingrese el nombre de la Espada: ";
    cin >> nombre;
    cout << endl;

    for(int i = 0; i < contador; i++){
        armor = archi.leerEspada(i);
        if(strcmp(armor.get_nombre(),nombre)== 0 && armor.get_estado()){
            cout << "Esta Espada ya existe" << endl;
            return false;
        }
    }

    cout << "Ingrese el Damage de la Espada: ";
    cin >> damage;
    cout << endl;
    while(damage < 0){
        cout << "El Damage no es valido! Ingrese otro valor valido: ";
        cin  >> damage;
        cout << endl;
    }

    cout << "Ingrese la Durabilidad de la Espada: ";
    cin >> durabilidad;
    cout << endl;
    while(durabilidad < 0){
        cout << "Este Damage no es valido! Ingrese otro valor valido: ";
        cin  >> durabilidad;
        cout << endl;
    }

    estado = true;
    return true;
}

///MOSTRAR

void Espada::mostrar(){
    cout << "Nombre: " << nombre << endl;
    cout << "Damage: " << damage << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Estado: " << estado << endl;
}
