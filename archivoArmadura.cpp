#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "archivoArmadura.h"

int ArchivoArmadura::agregarArmadura(){
    Armadura reg;
    int registro;
    FILE *pArm;

    pArm = fopen(nombre,"ab");

    if(pArm == nullptr){
        cout << "Error en memoria" << endl;
        return -1;
    }

    if(!reg.cargar()){
        cout << "No se cargo correctamente el registro" << endl;
        return -2;
    }

    registro = fwrite(&reg,tamanioRegistro,1,pArm);

    fclose(pArm);
    return registro;
}

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


int ArchivoArmadura::modificarArmadura(Armadura reg,int pos){
    FILE *pArm;
    pArm= fopen(nombre,"rb+");
    if(pArm == nullptr){
        return -1;
    }

    fseek(pArm,pos * tamanioRegistro,0);
    int escribio = fwrite(&reg,tamanioRegistro,1,pArm);

    fclose(pArm);
    return escribio;
}

int ArchivoArmadura::buscarPosicion(const char* nom){
    Armadura reg;
    FILE *pArm;

    int contador = cantidadArmadura();

    pArm = fopen(nombre,"rb");

    if(pArm == nullptr){
        return -1;
    }

    for(int i = 0; i < contador; i++){
        reg = leerArmadura(i);
        if(strcmp(reg.get_Nombre(),nom) == 0){
            fclose(pArm);
            return i;
        }
    }
    fclose(pArm);
    return -2;
}

Armadura ArchivoArmadura::leerArmadura(int pos){
    Armadura reg;
    FILE *pArm;
    reg.set_Nombre(" ");

    pArm = fopen(nombre,"rb");

    if(pArm == nullptr){
        return reg;
    }

    fseek(pArm,pos * tamanioRegistro,0);
    fread(&reg,tamanioRegistro,1,pArm);

    fclose(pArm);
    return reg;
}

int ArchivoArmadura::cantidadArmadura(){
    FILE *pArm;

    pArm = fopen(nombre,"rb");

    if(pArm == nullptr){
        return -1;
    }

    fseek(pArm,0,2);
    int tam = ftell(pArm);
    fclose(pArm);

    int cantReg;
    cantReg = tam / tamanioRegistro;
    return cantReg;
}

bool ArchivoArmadura::copiaSeguridad(){
     Armadura reg;

     FILE *pAr;
     FILE *pArm;

     pAr = fopen("copiaArmaduras.dat","wb");
     pArm = fopen(nombre,"rb");

     if(pAr == nullptr || pArm == nullptr){
        fclose(pArm);
        fclose(pAr);
        cout << "Error en memoria" << endl;
        return false;
     }

     while(fread(&reg,tamanioRegistro,1,pArm)==1){
        fwrite(&reg,tamanioRegistro,1,pAr);
     }

     fclose(pArm);
     fclose(pAr);

     return true;
}

bool ArchivoArmadura::reestablecer(){
     Armadura reg;

     FILE *pAr;
     FILE *pArm;

     pAr = fopen("copiaArmaduras.dat","rb");
     pArm = fopen(nombre,"wb");

     if(pAr == nullptr || pArm == nullptr){
        fclose(pArm);
        fclose(pAr);
        cout << "Error en memoria" << endl;
        return false;
     }

    while(fread(&reg,tamanioRegistro,1,pAr)==1){
        fwrite(&reg,tamanioRegistro,1,pArm);
     }

     fclose(pArm);
     fclose(pAr);

     return true;
}
