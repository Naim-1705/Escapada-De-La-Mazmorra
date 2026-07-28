#include <iostream>
#include <cstring>

using namespace std;

#include "Habilidad.h"
#include "archivoHabilidad.h"

///SETTERS
void Habilidad::set_nombre(const char* _nombre){
    strcpy(nombre,_nombre);
}

void Habilidad::set_damage(int _damage){
    if(_damage > 0){
        damage = _damage;
    }
}

void Habilidad::set_cooldown(int _cooldown){
    if(_cooldown > 0){
        cooldown = _cooldown;
    }
}

void Habilidad::set_estado(bool _estado){
    estado = _estado;
}

///CARGAR

bool Habilidad::cargar(){
    Habilidad reg;
    ArchivoHabilidad archi;

    int cantidad = archi.cantidadHabilidad();

    cout << "Ingrese el nombre de la Habilidad: ";
    cin >> nombre;
    cout << endl;

    for(int i = 0; i < cantidad; i++){
        reg = archi.leerHabilidad(i);
        if(strcmp(reg.get_nombre(),nombre)==0 && reg.get_estado()){
            cout << "Esta habilidad ya existe!" << endl;
            return false;
        }
    }

    cout << "Ingrese el Damage que realiza la Habilidad: ";
    cin >> damage;
    cout << endl;
    while(damage <= 0){
        cout << "Este valor no es valido.Ingrese un valor que sea valido: ";
        cin >> damage;
        cout << endl;
    }

    cout << "Ingrese el Cooldown que tiene la Habilidad: ";
    cin >> cooldown;
    cout << endl;
    while(cooldown <= 0){
        cout << "Este valor no es valido.Ingrese un valor que sea valido: ";
        cin >> cooldown;
        cout << endl;
    }

    estado = true;
    return true;
}


///MOSTRAR
void Habilidad::mostrar(){
    cout << "Nombre de la Habilidad: " << nombre << endl;
    cout << "Damage: " << damage << endl;
    cout << "Cooldown: " << cooldown << endl;
    cout << "Estado: " << estado << endl;
}
