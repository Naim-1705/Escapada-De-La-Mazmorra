#ifndef ARCHIVOJUGADOR_H_INCLUDED
#define ARCHIVOJUGADOR_H_INCLUDED

#pragma once

#include "Jugador.h"
#include "string.h"

class ArchivoJugador{
    private:
        char nombre[30];
        int tamanioRegistro;
    public:
    ArchivoJugador(const char *n="Jugadores.dat"){
        strcpy(nombre,n);
        tamanioRegistro = sizeof(Jugador);
    }
    int agregarJugador();
    ///bool bajaLogica(const char* nom);
    int modificarJugador(Jugador reg,int pos);
    int buscarPosicion(const char* nom);
    Jugador leerJugador(int pos);
    int cantidadJugador();
    bool copiaSeguridad();
    bool reestablecer();
};


#endif // ARCHIVOJUGADOR_H_INCLUDED
