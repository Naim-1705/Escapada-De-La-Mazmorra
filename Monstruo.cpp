#include <iostream>

using namespace std;

#include <cstring>

#include "archivoHabilidad.h"
#include "archivoMonstruo.h"
#include "Monstruo.h"
#include "Habilidad.h"

///SETTERS
void Monstruo::set_nombre(const char* _nombre){
    strcpy(nombre,_nombre);
}
void Monstruo::set_vida(int _vida){
    if(_vida >= 0){
        vida = _vida;
    }
}
void Monstruo::set_ataque(int _ataque){
    if(_ataque > 0){
       ataque = _ataque;
    }
}
void Monstruo::set_armadura(int _armadura){
    if(_armadura > 0){
        armadura = _armadura;
    }
}
void Monstruo::set_habilidad(Habilidad _ability){
    ability = _ability;
}
void Monstruo::set_estado(bool _estado){
    estado = _estado;
}

///CARGAR

bool Monstruo::cargar(){
    Monstruo mon;
    ArchivoMonstruo archi;
    Habilidad regHab;
    ArchivoHabilidad archiHab;

    char nom[30];
    int pos;

    int contador = archi.cantidadMonstruo();

    cout << "Ingrese el nombre del Monstruo: ";
    cin >> nombre;
    cout << endl;

    for(int i = 0; i < contador; i++){
        if(strcmp(mon.get_nombre(),nombre)==0 && mon.get_estado()){
            cout << "Este Monstruo ya existe" << endl;
            return false;
        }
    }

    cout << "Ingrese la vida del Monstruo: ";
    cin >> vida;
    cout << endl;
    while(vida < 0){
        cout << "Esta vida no es valido! Ingrese otro valor valido: ";
        cin  >> vida;
        cout << endl;
    }

    cout << "Ingrese el Damage del Monstruo: ";
    cin >> ataque;
    cout << endl;
    while(ataque < 0){
        cout << "Este Damage no es valido! Ingrese otro valor valido: ";
        cin  >> ataque;
        cout << endl;
    }

    cout << "Ingrese la Armadura del Monstruo: ";
    cin >> armadura;
    cout << endl;
    while(armadura < 0){
        cout << "Este valor no es valido! Ingrese otro valor valido: ";
        cin  >> armadura;
        cout << endl;
    }

    cout << "Ingrese el nombre de la Habilidad: ";
    cin >> nom;
    cout << endl;
    pos = archiHab.buscarPosicion(nom);
    if(pos < 0){
        cout << "No se encontro la habilidad " << endl;
        return false;
    }
    else{
        regHab = archiHab.leerHabilidad(pos);
        ability = regHab;
    }

    estado = true;
    return true;
}

void Monstruo::mostrar(){
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Damage: " << ataque << endl;
    cout << "Armadura:" << armadura << endl;
    cout << "Habilidad 1:" << endl;
    ability.mostrar();
    cout << endl;
    cout << "Estado: " << estado << endl;
}
