#include <iostream>
#include <cstring>

using namespace std;

#include "Jugador.h"

///SETTERS
void Jugador::set_nombre(const char* _nombre){
    strcpy(nombre,_nombre);
}
void Jugador::set_vida(int _vida){
    if(_vida >= 0){
        vida = _vida;
    }
}
void Jugador::set_damage(int _damage){
    if(_damage >= 0){
        damage = _damage;
    }
}
void Jugador::set_armadura(int _armadura){
    if(_armadura >= 0){
        armadura = _armadura;
    }
}
void Jugador::set_dinero(int _dinero){
    dinero = _dinero;
}

void Jugador::set_sword(Espada _sword){
    sword = _sword;
}

void Jugador::set_armor(Armadura _armor){
    armor = _armor;
}

void Jugador::set_ability(Habilidad _ability){
    ability = _ability;
}

///CARGAR
bool Jugador::cargar(){
    cout << "Ingrese el nombre del Jugador: ";
    cin >> nombre;
    cout << endl;

    cout << "Ingrese la vida del jugador: ";
    cin >> vida;
    cout << endl;
    if(vida <= 0){
        cout << "Este valor no es valido!";
        return false;
    }

    cout << "Ingrese el damage Base: ";
    cin >> damage;
    cout << endl;
    if(damage <= 0){
        cout << "Este valor no es valido!" << endl;
        return false;
    }

    cout << "Ingrese el dinero del jugador: " << endl;
    cin >> dinero;
    cout << endl;
    if(dinero < 0){
        cout << "Este valor no es valido!" << endl;
        return false;
    }

    cout << "Cargue la espada: " << endl;
    if(!sword.cargar()){
        cout << "No se pudo cargar la espada" << endl;
        return false;
    }
    cout << endl;

    cout << "Cargue la Armadura: " << endl;
    if(!armor.cargar()){
        cout << "No se pudo cargar la armadura" << endl;
        return false;
    }
    cout << endl;

    cout << "Cargue l Habilidad 1: " << endl;
    if(!ability.cargar()){
        cout << "No se pudo cargar la Habilidad" << endl;
        return false;
    }
    return true;
}

///MOSTRAR
void Jugador::mostrar(){
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Damage base: " <<damage << endl;
    cout << "Armadura base: " << armadura << endl;
    cout << "Dinero: $" << dinero << endl;
    cout << "Caracteristicas de la Espada: " << endl;
    sword.mostrar();
    cout << endl;
    cout << "Caracteristicas de la armadura: " << endl;
    armor.mostrar();
    cout << endl;
    cout << "Damage total: " << damage + sword.get_damage() << endl;
    cout << "Armadura total: " << armadura + armor.get_Aguante() << endl;
    cout << "Habilidad 1: " << endl;
    ability.mostrar();
    cout << endl;
}
