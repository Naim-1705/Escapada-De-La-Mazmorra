#ifndef ARCHIVOESPADA_H_INCLUDED
#define ARCHIVOESPADA_H_INCLUDED

#pragma once

#include "Espada.h"
#include "string.h"

class ArchivoEspada{
    private:
        char nombre[30];
        int tamanioRegistro;
    public:
    ArchivoEspada(const char *n="Espadas.dat"){
        strcpy(nombre,n);
        tamanioRegistro = sizeof(Espada);
    }
    int agregarEspada();
    bool bajaLogica(const char* nom);
    int modificarEspada(Espada reg,int pos);
    int buscarPosicion(const char* nom);
    Espada leerEspada(int pos);
    int cantidadEspada();
    bool copiaSeguridad();
    bool reestablecer();
};

#endif // ARCHIVOESPADA_H_INCLUDED
