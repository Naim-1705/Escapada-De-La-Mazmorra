#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "archivoMonstruo.h"

int ArchivoMonstruo::agregarMonstruo(){
    Monstruo reg;
    int registro;
    FILE *pMon;

    pMon = fopen(nombre,"ab");

    if(pMon == nullptr){
        return -1;
    }

    if(!reg.cargar()){
        cout << "No se cargo correctamente el registro" << endl;
        return -2;
    }

    registro = fwrite(&reg,tamanioRegistro,1,pMon);

    fclose(pMon);
    return registro;
}

bool ArchivoMonstruo::bajaLogica(int id){
    Monstruo reg;
    int pos = buscarPosicion(id);
    if(pos == -1)return false;

    reg = leerRegistro(pos);

    if(reg.getEstado()==false){
        return false;
    }
    else{
        reg.setEstado(false);
        return modificarMonstruo(reg,pos);
    }
}


int ArchivoMonstruo::modificarMonstruo(Monstruo reg,int pos){
    FILE *pMon;
    pMon= fopen(nombre,"rb+");
    if(pMon == nullptr){
        return -1;
    }

    fseek(pMon,pos * tamanioRegistro,0);
    int escribio = fwrite(&reg,tamanioRegistro,1,pMon);

    fclose(pMon);
    return escribio;
}

int ArchivoMonstruo::buscarPosicion(int id){
    Monstruo reg;
    int pos=0;
    FILE *pMon;

    pMon = fopen(nombre,"rb");

    if(pMon == nullptr){
        return -1;
    }

    while(fread(&reg,tamanioRegistro,1,pMon)==1){
        if(reg.getId()==id){
            fclose(pMon);
            return pos;
        }
        pos++;
    }
    fclose(pMon);
    return -2;
}

Monstruo ArchivoMonstruo::leerMonstruo(int pos){
    Monstruo reg;
    FILE *pMon;
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
