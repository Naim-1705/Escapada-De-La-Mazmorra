#include <iostream>

using namespace std;

#include "funcionesEspada.h"
#include "archivoEspada.h"
#include "archivoArmadura.h"
#include "Espada.h"
#include "Armadura.h"

ArchivoEspada archi;
Espada reg;
ArchivoArmadura archiArm;
Armadura regArm;


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
