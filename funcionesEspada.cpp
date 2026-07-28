#include <iostream>

using namespace std;

#include "funcionesEspada.h"
#include "archivoEspada.h"
#include "archivoArmadura.h"
#include "archivoHabilidad.h"
#include "archivoJugador.h"
#include "Espada.h"
#include "Armadura.h"
#include "Habilidad.h"
#include "Jugador.h"

ArchivoEspada archi;
Espada reg;
ArchivoArmadura archiArm;
Armadura regArm;
ArchivoHabilidad archiHab;
Habilidad regHab;
ArchivoJugador archiJug;
Jugador regJug;


///FUNCIONES DE ESPADAS
bool agregarEspada(){
    int valor;
    valor = archi.agregarEspada();

    if(valor < 0){
        return false;
    }
    else{
        return true;
    }
}

bool modificarEspada(){
    char nombre[30];
    int opc,valor;

    cout << "Ingrese el nombre de la Espada a modificar: ";
    cin >> nombre;

    int pos = archi.buscarPosicion(nombre);
    if(pos < 0){
        return false;
    }

    reg = archi.leerEspada(pos);

    cout << "Que aspecto desea modificar?" << endl;
    cout << "1- Nombre" << endl;
    cout << "2- Damage" << endl;
    cout << "3- Durabilidad" << endl;
    cout << "4- Estado" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opc;

    switch(opc){
    case 1:
        cout << "Ingrese un nuevo nombre: ";
        cin >> nombre;
        cout << endl;
        reg.set_nombre(nombre);
        break;
    case 2:
        cout << "Ingrese un nuevo damage: ";
        cin >> valor;
        cout << endl;
        reg.set_damage(valor);
        break;
    case 3:
        cout << "Ingrese una nueva durabilidad: ";
        cin >> valor;
        cout << endl;
        reg.set_durabilidad(valor);
        break;
    case 4:
        cout << "Ingrese un nuevo estado(1-Activo / 0-Inactivo): ";
        cin >> valor;
        while(valor > 1 || valor < 0){
            cout << "Este valor no es valido, ingrese uno nuevo: ";
            cin >> valor;
            cout << endl;
        }
        if(valor == 1){
            reg.set_estado(true);
        }
        if(valor == 0){
            reg.set_estado(false);
        }
    }

    bool modifico = archi.modificarEspada(reg,pos);

    return modifico;

}

bool eliminarEspada(){
    char nombre[30];

    int cantidad = archi.cantidadEspada();

    cout << "Ingrese el nombre de la Espada: ";
    cin >> nombre;

    for(int i = 0; i < cantidad; i++){
        reg = archi.leerEspada(i);
        if(strcmp(reg.get_nombre(),nombre) == 0){
            archi.bajaLogica(nombre);
            return true;
        }
    }
    return false;
}

bool mostrarEspada(){
    int cantidad = archi.cantidadEspada();
    int acumulador = 1;

    if(cantidad == 0){
        cout << "No hay registros que mostrar" << endl;
        return false;
    }

    for(int i = 0; i < cantidad; i++){
        reg = archi.leerEspada(i);
        if(reg.get_estado()){
            cout << "ESPADA N°" << acumulador << ": " << endl;
            reg.mostrar();
            cout << endl;
            acumulador++;
        }
    }
    return true;
}

///FUNCIONES DE ARMADURAS
bool agregarArmadura(){
    int valor;
    valor = archiArm.agregarArmadura();

    if(valor < 0){
        return false;
    }
    else{
        return true;
    }
}

bool modificarArmadura(){
    char nombre[30];
    int opc,valor;

    cout << "Ingrese el nombre de la Armadura a modificar: ";
    cin >> nombre;

    int pos = archiArm.buscarPosicion(nombre);
    if(pos < 0){
        return false;
    }

    regArm = archiArm.leerArmadura(pos);

    cout << "Que aspecto desea modificar?" << endl;
    cout << "1- Nombre" << endl;
    cout << "2- Aguante" << endl;
    cout << "3- Durabilidad" << endl;
    cout << "4- Estado" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opc;

    switch(opc){
    case 1:
        cout << "Ingrese un nuevo nombre: ";
        cin >> nombre;
        cout << endl;
        regArm.set_Nombre(nombre);
        break;
    case 2:
        cout << "Ingrese un nuevo aguante: ";
        cin >> valor;
        cout << endl;
        regArm.set_Aguante(valor);
        break;
    case 3:
        cout << "Ingrese una nueva durabilidad: ";
        cin >> valor;
        cout << endl;
        reg.set_durabilidad(valor);
        break;
    case 4:
        cout << "Ingrese un nuevo estado(1-Activo / 0-Inactivo): ";
        cin >> valor;
        while(valor > 1 || valor < 0){
            cout << "Este valor no es valido, ingrese uno nuevo: ";
            cin >> valor;
            cout << endl;
        }
        if(valor == 1){
            regArm.set_Estado(true);
        }
        if(valor == 0){
            regArm.set_Estado(false);
        }
    }

    bool modifico = archiArm.modificarArmadura(regArm,pos);

    return modifico;

}

bool eliminarArmadura(){
    char nombre[30];

    int cantidad = archiArm.cantidadArmadura();

    cout << "Ingrese el nombre de la Armadura: ";
    cin >> nombre;

    for(int i = 0; i < cantidad; i++){
        regArm = archiArm.leerArmadura(i);
        if(strcmp(regArm.get_Nombre(),nombre) == 0){
            archiArm.bajaLogica(nombre);
            return true;
        }
    }
    return false;
}

bool mostrarArmadura(){
    int cantidad = archiArm.cantidadArmadura();
    int acumulador = 1;

    if(cantidad == 0){
        cout << "No hay registros que mostrar" << endl;
        return false;
    }

    for(int i = 0; i < cantidad; i++){
        regArm = archiArm.leerArmadura(i);
        if(regArm.get_Estado()){
            cout << "ARMADURA N°" << acumulador << ": " << endl;
            regArm.mostrar();
            cout << endl;
            acumulador++;
        }
    }
    return true;
}

///FUNCIONES DE HABILIDAD
bool agregarHabilidad(){
    int valor;
    valor = archiHab.agregarHabilidad();

    if(valor < 0){
        return false;
    }
    else{
        return true;
    }
}

bool modificarHabilidad(){
    char nombre[30];
    int opc,valor;

    cout << "Ingrese el nombre de la Habilidad a modificar: ";
    cin >> nombre;

    int pos = archiHab.buscarPosicion(nombre);
    if(pos < 0){
        return false;
    }

    regHab = archiHab.leerHabilidad(pos);

    cout << "Que aspecto desea modificar?" << endl;
    cout << "1- Nombre" << endl;
    cout << "2- Damage" << endl;
    cout << "3- Cooldown" << endl;
    cout << "4- Estado" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opc;

    switch(opc){
    case 1:
        cout << "Ingrese un nuevo nombre: ";
        cin >> nombre;
        cout << endl;
        regHab.set_nombre(nombre);
        break;
    case 2:
        cout << "Ingrese un nuevo damage: ";
        cin >> valor;
        cout << endl;
        regHab.set_damage(valor);
        break;
    case 3:
        cout << "Ingrese el nuevo cooldown: ";
        cin >> valor;
        cout << endl;
        regHab.set_cooldown(valor);
        break;
    case 4:
        cout << "Ingrese un nuevo estado(1-Activo / 0-Inactivo): ";
        cin >> valor;
        while(valor > 1 || valor < 0){
            cout << "Este valor no es valido, ingrese uno nuevo: ";
            cin >> valor;
            cout << endl;
        }
        if(valor == 1){
            regHab.set_estado(true);
        }
        if(valor == 0){
            regHab.set_estado(false);
        }
    }

    bool modifico = archiHab.modificarHabilidad(regHab,pos);

    return modifico;

}

bool eliminarHabilidad(){
    char nombre[30];

    int cantidad = archiHab.cantidadHabilidad();

    cout << "Ingrese el nombre de la Habilidad: ";
    cin >> nombre;

    for(int i = 0; i < cantidad; i++){
        regHab = archiHab.leerHabilidad(i);
        if(strcmp(regHab.get_nombre(),nombre) == 0){
            archiHab.bajaLogica(nombre);
            return true;
        }
    }
    return false;
}

bool mostrarHabilidad(){
    int cantidad = archiHab.cantidadHabilidad();
    int acumulador = 1;

    if(cantidad == 0){
        cout << "No hay registros que mostrar" << endl;
        return false;
    }

    for(int i = 0; i < cantidad; i++){
        regHab = archiHab.leerHabilidad(i);
        if(regHab.get_estado()){
            cout << "HABILIDAD N°" << acumulador << ": " << endl;
            regHab.mostrar();
            cout << endl;
            acumulador++;
        }
    }
    return true;
}

///FUNCIONES DE JUGADOR
bool agregarJugador(){
    int valor;
    valor = archiJug.agregarJugador();

    if(valor < 0){
        return false;
    }
    else{
        return true;
    }
}

bool modificarJugador(){
    char nombre[30];
    int opc,valor;

    cout << "Ingrese el nombre del Jugador a modificar: ";
    cin >> nombre;

    int pos = archiJug.buscarPosicion(nombre);
    if(pos < 0){
        return false;
    }

    regJug = archiJug.leerJugador(pos);

    cout << "Que aspecto desea modificar?" << endl;
    cout << "1- Nombre" << endl;
    cout << "2- Damage base" << endl;
    cout << "3- Armadura base" << endl;
    cout << "4- Dinero" << endl;
    cout << "5- Espada" << endl;
    cout << "6- Armadura" << endl;
    cout << "7- Habilidad 1" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opc;

    switch(opc){
    case 1:
        cout << "Ingrese un nuevo nombre: ";
        cin >> nombre;
        cout << endl;
        regJug.set_nombre(nombre);
        break;
    case 2:
        cout << "Ingrese un nuevo damage base: ";
        cin >> valor;
        cout << endl;
        regJug.set_damage(valor);
        break;
    case 3:
        cout << "Ingrese una nueva armadura base: ";
        cin >> valor;
        cout << endl;
        regJug.set_armadura(valor);
        break;
    case 4:
        cout << "Ingrese el dinero: ";
        cin >> valor;
        cout << endl;
        regJug.set_dinero(valor);
        break;
    case 5:
        cout << "Ingrese las especificaciones de la espada: " << endl;
        if(reg.cargar()){
            regJug.set_sword(reg);
        }
        else{
            return false;
        }
        break;
    case 6:
        cout << "Ingrese las especificaciones de la armadura: " << endl;
        if(regArm.cargar()){
            regJug.set_armor(regArm);
        }
        else{
            return false;
        }
        break;
    case 7:
        cout << "Ingrese las especificaciones de la habilidad 1: " << endl;
        if(regHab.cargar()){
            regJug.set_ability(regHab);
        }
        else{
            return false;
        }
        break;
    default:
        cout << "El valor ingresado no es valido, ingrese otro" << endl;
        break;
    }

    bool modifico = archiHab.modificarHabilidad(regHab,pos);

    return modifico;

}

/*
bool eliminarHabilidad(){
    char nombre[30];

    int cantidad = archiHab.cantidadHabilidad();

    cout << "Ingrese el nombre de la Habilidad: ";
    cin >> nombre;

    for(int i = 0; i < cantidad; i++){
        regHab = archiHab.leerHabilidad(i);
        if(strcmp(regHab.get_nombre(),nombre) == 0){
            archiHab.bajaLogica(nombre);
            return true;
        }
    }
    return false;
}
*/

bool mostrarJugador(){
    int cantidad = archiJug.cantidadJugador();
    int acumulador = 1;

    if(cantidad == 0){
        cout << "No hay registros que mostrar" << endl;
        return false;
    }

    for(int i = 0; i < cantidad; i++){
        regJug = archiJug.leerJugador(i);
        cout << "JUGADOR N°" << acumulador << ": " << endl;
        regJug.mostrar();
        cout << endl;
        acumulador++;
    }
    return true;
}
