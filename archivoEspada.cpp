#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "archivoEspada.h"

int ArchivoEspada::agregarEspada(){
    Espada reg;
    int registro;
    FILE *pEsp;

    pEsp = fopen(nombre,"ab");

    if(pEsp == nullptr){
        cout << "Error en memoria" << endl;
        return -1;
    }

    if(!reg.cargar()){
        cout << "No se cargo correctamente el registro" << endl;
        return -2;
    }

    registro = fwrite(&reg,tamanioRegistro,1,pEsp);

    fclose(pEsp);
    return registro;
}

bool ArchivoEspada::bajaLogica(const char* nom){
    Espada reg;
    int pos = buscarPosicion(nom);
    if(pos == -1)return false;

    reg = leerEspada(pos);

    if(reg.get_estado()==false){
        return false;
    }
    else{
        reg.set_estado(false);
        return modificarEspada(reg,pos);
    }
}


int ArchivoEspada::modificarEspada(Espada reg,int pos){
    FILE *pEsp;
    pEsp= fopen(nombre,"rb+");
    if(pEsp == nullptr){
        return -1;
    }

    fseek(pEsp,pos * tamanioRegistro,0);
    int escribio = fwrite(&reg,tamanioRegistro,1,pEsp);

    fclose(pEsp);
    return escribio;
}

int ArchivoEspada::buscarPosicion(const char* nom){
    ArchivoEspada archi;
    Espada reg;
    FILE *pEsp;

    int contador = archi.cantidadEspada();

    pEsp = fopen(nombre,"rb");

    if(pEsp == nullptr){
        return -1;
    }

    for(int i = 0; i < contador; i++){
        reg = leerEspada(i);
        if(strcmp(reg.get_nombre(),nom) == 0){
            fclose(pEsp);
            return i;
        }
    }
    fclose(pEsp);
    return -2;
}

Espada ArchivoEspada::leerEspada(int pos){
    Espada reg;
    FILE *pEsp;
    reg.set_nombre(" ");

    pEsp = fopen(nombre,"rb");

    if(pEsp == nullptr){
        return reg;
    }

    fseek(pEsp,pos * tamanioRegistro,0);
    fread(&reg,tamanioRegistro,1,pEsp);

    fclose(pEsp);
    return reg;
}

int ArchivoEspada::cantidadEspada(){
    FILE *pEsp;

    pEsp = fopen(nombre,"rb");

    if(pEsp == nullptr){
        return -1;
    }

    fseek(pEsp,0,2);
    int tam = ftell(pEsp);
    fclose(pEsp);

    int cantReg;
    cantReg = tam / tamanioRegistro;
    return cantReg;
}

bool ArchivoEspada::copiaSeguridad(){
     Espada reg;

     FILE *pEs;
     FILE *pEsp;

     pEs = fopen("copiaEspadas.dat","wb");
     pEsp = fopen(nombre,"rb");

     if(pEs == nullptr || pEsp == nullptr){
        fclose(pEsp);
        fclose(pEs);
        cout << "Error en memoria" << endl;
        return false;
     }

     while(fread(&reg,tamanioRegistro,1,pEsp)==1){
        fwrite(&reg,tamanioRegistro,1,pEs);
     }

     fclose(pEsp);
     fclose(pEs);

     return true;
}

bool ArchivoEspada::reestablecer(){
     Espada reg;

     FILE *pEs;
     FILE *pEsp;

     pEs = fopen("copiaEspadas.dat","rb");
     pEsp = fopen(nombre,"wb");

     if(pEs == nullptr || pEsp == nullptr){
        fclose(pEsp);
        fclose(pEs);
        cout << "Error en memoria" << endl;
        return false;
     }

    while(fread(&reg,tamanioRegistro,1,pEs)==1){
        fwrite(&reg,tamanioRegistro,1,pEsp);
     }

     fclose(pEsp);
     fclose(pEs);

     return true;
}
