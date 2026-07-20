#pragma once

#include "Monstruo.h"
#include "string.h"

class ArchivoMonstruo{
    private:
        char nombre[30];
        int tamanioRegistro;
    public:
    ArchivoMonstruo(const char *n="Monstruos.dat"){
        strcpy(nombre,n);
        tamanioRegistro = sizeof(Monstruo);
    }
    int agregarMonstruo();
    bool bajaLogica(char *nombre);
    int modificarMonstruo(Monstruo reg,int pos);
    int buscarPosicion(int id);
    Monstruo leerMonstruo(int pos);
    int cantidadMonstruo();
    bool copiaSeguridad();
    bool reestablecer();
};
