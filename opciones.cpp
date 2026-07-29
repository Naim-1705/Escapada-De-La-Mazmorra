#include <iostream>

using namespace std;

#include "opciones.h"
#include "funcionesEspada.h"

void menuEspada(){
    bool seguir = true;
    int opc;

    while(seguir){
        system("cls");
        cout << "---MENU DE ESPADAS---" << endl;
        cout << "1- Agregar una espada" << endl;
        cout << "2- Modificar una espada" << endl;
        cout << "3- Eliminar una espada" << endl;
        cout << "4- Mostrar todas las espadas" << endl;
        cout << "0- Salir al menu de opciones" << endl;

        cout << "Elije una opcion: ";
        cin >> opc;
        cout << endl;

        switch(opc){
        case 1:
            if(agregarEspada()){
                cout << "El registro se cargo con exito" << endl;
            }
            else{
                cout << "No se pudo cargar el registro" << endl;
            }
            break;
        case 2:
            if(modificarEspada()){
                cout << "Se modifico el registro con exito" << endl;
            }
            else{
                cout << "No se pudo modificar el registro" << endl;
            }
            break;
        case 3:
            if(eliminarEspada()){
                cout << "Se elimino el registro con exito" << endl;
            }
            else{
                cout << "No se pudo eliminar el registro" << endl;
            }
            break;
        case 4:
            if(mostrarEspada()){
                cout << "Se mostraron los registros con exito" << endl;
            }
            else{
                cout << "No se pudo mostrar los registros" << endl;
            }
            break;
        case 0:
            cout << "Saliendo del menu de espada..." << endl;
            seguir = false;
            break;
        default:
            cout << "La opcion ingresada es invalida. Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }
}

void menuArmadura(){
    bool seguir = true;
    int opc;

    while(seguir){
        system("cls");
        cout << "---MENU DE ARMADURAS---" << endl;
        cout << "1- Agregar una armadura" << endl;
        cout << "2- Modificar una armadura" << endl;
        cout << "3- Eliminar una armadura" << endl;
        cout << "4- Mostrar todas las armaduras" << endl;
        cout << "0- Salir al menu de opciones" << endl;

        cout << "Elije una opcion: ";
        cin >> opc;
        cout << endl;

        switch(opc){
        case 1:
            if(agregarArmadura()){
                cout << "El registro se cargo con exito" << endl;
            }
            else{
                cout << "No se pudo cargar el registro" << endl;
            }
            break;
        case 2:
            if(modificarArmadura()){
                cout << "Se modifico el registro con exito" << endl;
            }
            else{
                cout << "No se pudo modificar el registro" << endl;
            }
            break;
        case 3:
            if(eliminarArmadura()){
                cout << "Se elimino el registro con exito" << endl;
            }
            else{
                cout << "No se pudo eliminar el registro" << endl;
            }
            break;
        case 4:
            if(mostrarArmadura()){
                cout << "Se mostraron los registros con exito" << endl;
            }
            else{
                cout << "No se pudo mostrar los registros" << endl;
            }
            break;
        case 0:
            cout << "Saliendo del menu de armaduras..." << endl;
            seguir = false;
            break;
        default:
            cout << "La opcion ingresada es invalida. Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }
}

void menuHabilidad(){
    bool seguir = true;
    int opc;

    while(seguir){
        system("cls");
        cout << "---MENU DE HABILIDADES---" << endl;
        cout << "1- Agregar una habilidad" << endl;
        cout << "2- Modificar una habilidad" << endl;
        cout << "3- Eliminar una habilidad" << endl;
        cout << "4- Mostrar todas las habilidades" << endl;
        cout << "0- Salir al menu de opciones" << endl;

        cout << "Elije una opcion: ";
        cin >> opc;
        cout << endl;

        switch(opc){
        case 1:
            if(agregarHabilidad()){
                cout << "El registro se cargo con exito" << endl;
            }
            else{
                cout << "No se pudo cargar el registro" << endl;
            }
            break;
        case 2:
            if(modificarHabilidad()){
                cout << "Se modifico el registro con exito" << endl;
            }
            else{
                cout << "No se pudo modificar el registro" << endl;
            }
            break;
        case 3:
            if(eliminarHabilidad()){
                cout << "Se elimino el registro con exito" << endl;
            }
            else{
                cout << "No se pudo eliminar el registro" << endl;
            }
            break;
        case 4:
            if(mostrarHabilidad()){
                cout << "Se mostraron los registros con exito" << endl;
            }
            else{
                cout << "No se pudo mostrar los registros" << endl;
            }
            break;
        case 0:
            cout << "Saliendo del menu de habilidades..." << endl;
            seguir = false;
            break;
        default:
            cout << "La opcion ingresada es invalida. Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }
}

void menuJugador(){
    bool seguir = true;
    int opc;

    while(seguir){
        system("cls");
        cout << "---MENU DEL JUGADOR---" << endl;
        cout << "1- Agregar un jugador" << endl;
        cout << "2- Modificar un jugador" << endl;
        ///cout << "3- Eliminar una habilidad" << endl;
        cout << "3- Mostrar todas las habilidades" << endl;
        cout << "0- Salir al menu de opciones" << endl;

        cout << "Elije una opcion: ";
        cin >> opc;
        cout << endl;

        switch(opc){
        case 1:
            if(agregarJugador()){
                cout << "El registro se cargo con exito" << endl;
            }
            else{
                cout << "No se pudo cargar el registro" << endl;
            }
            break;
        case 2:
            if(modificarJugador()){
                cout << "Se modifico el registro con exito" << endl;
            }
            else{
                cout << "No se pudo modificar el registro" << endl;
            }
            break;
            /*
        case 3:
            if(eliminarHabilidad()){
                cout << "Se elimino el registro con exito" << endl;
            }
            else{
                cout << "No se pudo eliminar el registro" << endl;
            }
            break;*/
        case 3:
            if(mostrarJugador()){
                cout << "Se mostraron los registros con exito" << endl;
            }
            else{
                cout << "No se pudo mostrar los registros" << endl;
            }
            break;
        case 0:
            cout << "Saliendo del menu de los jugadores..." << endl;
            seguir = false;
            break;
        default:
            cout << "La opcion ingresada es invalida. Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }
}

///MENU DE MONSTRUOS
void menuMonstruo(){
    bool seguir = true;
    int opc;

    while(seguir){
        system("cls");
        cout << "---MENU DE MONSTRUOS---" << endl;
        cout << "1- Agregar un monstruo" << endl;
        cout << "2- Modificar un monstruo" << endl;
        cout << "3- Eliminar un monstruo" << endl;
        cout << "4- Mostrar todos los monstruos" << endl;
        cout << "0- Salir al menu de opciones" << endl;

        cout << "Elije una opcion: ";
        cin >> opc;
        cout << endl;

        switch(opc){
        case 1:
            if(agregarMonstruo()){
                cout << "El registro se cargo con exito" << endl;
            }
            else{
                cout << "No se pudo cargar el registro" << endl;
            }
            break;
        case 2:
            if(modificarMonstruo()){
                cout << "Se modifico el registro con exito" << endl;
            }
            else{
                cout << "No se pudo modificar el registro" << endl;
            }
            break;
        case 3:
            if(eliminarMonstruo()){
                cout << "Se elimino el registro con exito" << endl;
            }
            else{
                cout << "No se pudo eliminar el registro" << endl;
            }
            break;
        case 4:
            if(mostrarMonstruo()){
                cout << "Se mostraron los registros con exito" << endl;
            }
            else{
                cout << "No se pudo mostrar los registros" << endl;
            }
            break;
        case 0:
            cout << "Saliendo del menu de monstruos..." << endl;
            seguir = false;
            break;
        default:
            cout << "La opcion ingresada es invalida. Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }
}

void menuOpciones(){
    bool sigue = true;
    int opc;
    while(sigue){
        system("cls");
        cout << "---MENU DE OPCIONES---" << endl;
        cout << "1- Menu de Espadas" << endl;
        cout << "2- Menu de Armaduras" << endl;
        cout << "3- Menu de Habilidades" << endl;
        cout << "4- Menu de Jugadores" << endl;
        cout << "5- Menu de Monstruos" << endl,
        cout << "0- Salir a menu principal" << endl;

        cout << "Ingrese una opcion:";
        cin >> opc;
        cout << endl;

        switch(opc){
        case 0:
            cout << "Saliendo del menu de opciones..." << endl;
            system("pause");
            sigue = false;
            break;
        case 1:
            menuEspada();
            break;
        case 2:
            menuArmadura();
            break;
        case 3:
            menuHabilidad();
            break;
        case 4:
            menuJugador();
            break;
        case 5:
            menuMonstruo();
            break;
        default:
            cout << "Esta opcion no es valida. Ingrese un valor valido!" << endl;
            break;
        }
    }
}
