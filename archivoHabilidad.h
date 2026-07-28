#ifndef ARCHIVOHABILIDAD_H_INCLUDED
#define ARCHIVOHABILIDAD_H_INCLUDED

#pragma once

#include "Habilidad.h"
#include "string.h"

class ArchivoHabilidad{
    private:
        char nombre[30];
        int tamanioRegistro;
    public:
    ArchivoHabilidad(const char *n="Habilidades.dat"){
        strcpy(nombre,n);
        tamanioRegistro = sizeof(Habilidad);
    }
    int agregarHabilidad();
    bool bajaLogica(const char* nom);
    int modificarHabilidad(Habilidad reg,int pos);
    int buscarPosicion(const char* nom);
    Habilidad leerHabilidad(int pos);
    int cantidadHabilidad();
    bool copiaSeguridad();
    bool reestablecer();
};

#endif // ARCHIVOHABILIDAD_H_INCLUDED
