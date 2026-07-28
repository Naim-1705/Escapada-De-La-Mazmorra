#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "archivoJugador.h"

int ArchivoJugador::agregarJugador(){
    int cantidad = cantidadJugador();

    if(cantidad < 0){
        Jugador reg;
        int registro;
        FILE *pJug;

        pJug = fopen(nombre,"ab");

        if(pJug == nullptr){
            cout << "Error en memoria" << endl;
            return -1;
        }

        if(!reg.cargar()){
            cout << "No se cargo correctamente el registro" << endl;
            return -2;
        }

        registro = fwrite(&reg,tamanioRegistro,1,pJug);

        fclose(pJug);
        return registro;
    }
    else{
        cout << "Ya existe un jugador creado" << endl;
        return -3;
    }
}

/*
bool ArchivoArmadura::bajaLogica(const char* nom){
    Armadura reg;
    int pos = buscarPosicion(nom);
    if(pos == -1)return false;

    reg = leerArmadura(pos);

    if(reg.get_Estado() == false){
        return false;
    }
    else{
        reg.set_Estado(false);
        return modificarArmadura(reg,pos);
    }
}
*/

int ArchivoJugador::modificarJugador(Jugador reg,int pos){
    FILE *pJug;
    pJug = fopen(nombre,"rb+");
    if(pJug == nullptr){
        return -1;
    }

    fseek(pJug,pos * tamanioRegistro,0);
    int escribio = fwrite(&reg,tamanioRegistro,1,pJug);

    fclose(pJug);
    return escribio;
}

int ArchivoJugador::buscarPosicion(const char* nom){
    Jugador reg;
    FILE *pJug;

    int contador = cantidadJugador();

    pJug = fopen(nombre,"rb");

    if(pJug == nullptr){
        return -1;
    }

    for(int i = 0; i < contador; i++){
        reg = leerJugador(i);
        if(strcmp(reg.get_nombre(),nom) == 0){
            fclose(pJug);
            return i;
        }
    }
    fclose(pJug);
    return -2;
}

Jugador ArchivoJugador::leerJugador(int pos){
    Jugador reg;
    FILE *pJug;
    reg.set_nombre(" ");

    pJug = fopen(nombre,"rb");

    if(pJug == nullptr){
        return reg;
    }

    fseek(pJug,pos * tamanioRegistro,0);
    fread(&reg,tamanioRegistro,1,pJug);

    fclose(pJug);
    return reg;
}

int ArchivoJugador::cantidadJugador(){
    FILE *pJug;

    pJug = fopen(nombre,"rb");

    if(pJug == nullptr){
        return -1;
    }

    fseek(pJug,0,2);
    int tam = ftell(pJug);
    fclose(pJug);

    int cantReg;
    cantReg = tam / tamanioRegistro;
    return cantReg;
}

bool ArchivoJugador::copiaSeguridad(){
     Jugador reg;

     FILE *pJu;
     FILE *pJug;

     pJu = fopen("copiaJugadores.dat","wb");
     pJug = fopen(nombre,"rb");

     if(pJu == nullptr || pJug == nullptr){
        fclose(pJug);
        fclose(pJu);
        cout << "Error en memoria" << endl;
        return false;
     }

     while(fread(&reg,tamanioRegistro,1,pJug)==1){
        fwrite(&reg,tamanioRegistro,1,pJu);
     }

     fclose(pJug);
     fclose(pJu);

     return true;
}

bool ArchivoJugador::reestablecer(){
     Jugador reg;

     FILE *pJu;
     FILE *pJug;

     pJu = fopen("copiaJugadores.dat","rb");
     pJug = fopen(nombre,"wb");

     if(pJu == nullptr || pJug == nullptr){
        fclose(pJug);
        fclose(pJu);
        cout << "Error en memoria" << endl;
        return false;
     }

    while(fread(&reg,tamanioRegistro,1,pJu)==1){
        fwrite(&reg,tamanioRegistro,1,pJug);
     }

     fclose(pJug);
     fclose(pJu);

     return true;
}
