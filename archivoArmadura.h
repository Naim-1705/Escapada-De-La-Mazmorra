#ifndef ARCHIVOARMADURA_H_INCLUDED
#define ARCHIVOARMADURA_H_INCLUDED

#pragma once

#include "Armadura.h"
#include "string.h"

class ArchivoArmadura{
    private:
        char nombre[30];
        int tamanioRegistro;
    public:
    ArchivoArmadura(const char *n="Armaduras.dat"){
        strcpy(nombre,n);
        tamanioRegistro = sizeof(Armadura);
    }
    int agregarArmadura();
    bool bajaLogica(const char* nom);
    int modificarArmadura(Armadura reg,int pos);
    int buscarPosicion(const char* nom);
    Armadura leerArmadura(int pos);
    int cantidadArmadura();
    bool copiaSeguridad();
    bool reestablecer();
};

#endif // ARCHIVOARMADURA_H_INCLUDED
