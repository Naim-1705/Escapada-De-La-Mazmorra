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

bool ArchivoEspada::bajaLogica(char* nom){
    Espada reg;
    int pos = buscarPosicion(&nom);
    if(pos == -1)return false;

    reg = leerRegistro(pos);

    if(reg.getEstado()==false){
        return false;
    }
    else{
        reg.setEstado(false);
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

int ArchivoEspada::buscarPosicion(char* nom){
    Espada reg;
    FILE *pEsp;

    int contador = archi.cantidadEspada();

    pEsp = fopen(nombre,"rb");

    if(pEsp == nullptr){
        return -1;
    }

    for(int i = 0; i < contador; i++){
        reg = leerEspada(i);
        if(strcmp(reg.get_nombre(),nom) == 1){
            fclose(pMon);
            return i;
        }
    }
    fclose(pMon);
    return -2;
}

Espada ArchivoEspada::leerEspada(int pos){
    Espada reg;
    FILE *pEsp;
    reg.set_id(-1);

    pMon = fopen(nombre,"rb");

    if(pMon == nullptr){
        return reg;
    }

    fseek(pMon,pos * tamanioRegistro,0);
    fread(&reg,tamanioRegistro,1,pMon);

    fclose(pMon);
    return reg;
}

int ArchivoMonstruo::cantidadMonstruo(){
    Monstruo reg;
    FILE *pMon;

    pMon = fopen(nombre,"rb");

    if(pMon == nullptr){
        return -1;
    }

    fseek(pMon,0,2);
    int tam = ftell(pMon);
    fclose(pMon);

    int cantReg;
    cantReg = tam / tamanioRegistro;
    return cantReg;
}

bool ArchivoMonstruo::copiaSeguridad(){
    Monstruo reg;

     FILE *pMo;
     FILE *pMon;

     pMo = fopen("copiaMonstruos.dat","wb");
     pMon = fopen(nombre,"rb");

     if(pMo == nullptr || pMon == nullptr){
        fclose(pMon);
        fclose(pMo);
        cout << "Error en memoria" << endl;
        return false;
     }

     while(fread(&reg,tamanioRegistro,1,pMon)==1){
        fwrite(&reg,tamanioRegistro,1,pMo);
     }

     fclose(pMon);
     fclose(pMo);

     return true;
}

bool ArchivoMonstruo::reestablecer(){
    Monstruo reg;

     FILE *pMo;
     FILE *pMon;

     pMo = fopen("copiaMonstruos.dat","rb");
     pMon = fopen(nombre,"wb");

     if(pMo == nullptr || pMon == nullptr){
        fclose(pMon);
        fclose(pMo);
        cout << "Error en memoria" << endl;
        return false;
     }

    while(fread(&reg,tamanioRegistro,1,pMo)==1){
        fwrite(&reg,tamanioRegistro,1,pMon);
     }

     fclose(pMon);
     fclose(pMo);

     return true;
}
