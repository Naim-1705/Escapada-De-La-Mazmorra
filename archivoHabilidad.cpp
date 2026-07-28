#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "archivoHabilidad.h"

int ArchivoHabilidad::agregarHabilidad(){
    Habilidad reg;
    int registro;
    FILE *pHab;

    pHab = fopen(nombre,"ab");

    if(pHab == nullptr){
        cout << "Error en memoria" << endl;
        return -1;
    }

    if(!reg.cargar()){
        cout << "No se cargo correctamente el registro" << endl;
        return -2;
    }

    registro = fwrite(&reg,tamanioRegistro,1,pHab);

    fclose(pHab);
    return registro;
}

bool ArchivoHabilidad::bajaLogica(const char* nom){
    Habilidad reg;
    int pos = buscarPosicion(nom);
    if(pos == -1)return false;

    reg = leerHabilidad(pos);

    if(reg.get_estado() == false){
        return false;
    }
    else{
        reg.set_estado(false);
        return modificarHabilidad(reg,pos);
    }
}


int ArchivoHabilidad::modificarHabilidad(Habilidad reg,int pos){
    FILE *pHab;
    pHab= fopen(nombre,"rb+");
    if(pHab == nullptr){
        return -1;
    }

    fseek(pHab,pos * tamanioRegistro,0);
    int escribio = fwrite(&reg,tamanioRegistro,1,pHab);

    fclose(pHab);
    return escribio;
}

int ArchivoHabilidad::buscarPosicion(const char* nom){
    Habilidad reg;
    FILE *pHab;

    int contador = cantidadHabilidad();

    pHab = fopen(nombre,"rb");

    if(pHab == nullptr){
        return -1;
    }

    for(int i = 0; i < contador; i++){
        reg = leerHabilidad(i);
        if(strcmp(reg.get_nombre(),nom) == 0){
            fclose(pHab);
            return i;
        }
    }
    fclose(pHab);
    return -2;
}

Habilidad ArchivoHabilidad::leerHabilidad(int pos){
    Habilidad reg;
    FILE *pHab;
    reg.set_nombre(" ");

    pHab = fopen(nombre,"rb");

    if(pHab == nullptr){
        return reg;
    }

    fseek(pHab,pos * tamanioRegistro,0);
    fread(&reg,tamanioRegistro,1,pHab);

    fclose(pHab);
    return reg;
}

int ArchivoHabilidad::cantidadHabilidad(){
    FILE *pHab;

    pHab = fopen(nombre,"rb");

    if(pHab == nullptr){
        return -1;
    }

    fseek(pHab,0,2);
    int tam = ftell(pHab);
    fclose(pHab);

    int cantReg;
    cantReg = tam / tamanioRegistro;
    return cantReg;
}

bool ArchivoHabilidad::copiaSeguridad(){
     Habilidad reg;

     FILE *pHb;
     FILE *pHab;

     pHb = fopen("copiaHabilidades.dat","wb");
     pHab = fopen(nombre,"rb");

     if(pHb == nullptr || pHab == nullptr){
        fclose(pHab);
        fclose(pHb);
        cout << "Error en memoria" << endl;
        return false;
     }

     while(fread(&reg,tamanioRegistro,1,pHab)==1){
        fwrite(&reg,tamanioRegistro,1,pHb);
     }

     fclose(pHab);
     fclose(pHb);

     return true;
}

bool ArchivoHabilidad::reestablecer(){
     Habilidad reg;

     FILE *pHb;
     FILE *pHab;

     pHb = fopen("copiaHabilidades.dat","rb");
     pHab = fopen(nombre,"wb");

     if(pHb == nullptr || pHab == nullptr){
        fclose(pHab);
        fclose(pHb);
        cout << "Error en memoria" << endl;
        return false;
     }

    while(fread(&reg,tamanioRegistro,1,pHb)==1){
        fwrite(&reg,tamanioRegistro,1,pHab);
     }

     fclose(pHab);
     fclose(pHb);

     return true;
}
