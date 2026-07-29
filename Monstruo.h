#ifndef MONSTRUO_H_INCLUDED
#define MONSTRUO_H_INCLUDED
#include <cstring>
#include "Habilidad.h"

class Monstruo{
private:
    char nombre[20];
    int vida;
    int ataque;
    int armadura;
    Habilidad ability;
    bool estado;
public:
    ///CONSTRUCTOR
    Monstruo(const char n[20] = " ", int v = 100, int a = 25,int ar = 20,Habilidad ab = Habilidad(), bool e = true){
        strcpy(nombre,n);
        vida = v;
        ataque = a;
        armadura = ar;
        ability = ab;
        estado = e;
    }

    ///SETTERS
    void set_nombre(const char* _nombre);

    void set_vida(int _vida);

    void set_ataque(int _ataque);

    void set_armadura(int _armadura);

    void set_habilidad(Habilidad _ability);

    void set_estado(bool _estado);

    ///GETTERS
    char* get_nombre(){return nombre;}
    int get_vida(){return vida;}
    int get_ataque(){return ataque;}
    int get_armadura(){return armadura;}
    Habilidad get_habilidad(){return ability;}
    bool get_estado(){return estado;}

    ///CARGAR

    bool cargar();

    void mostrar();
};

#endif // MONSTRUO_H_INCLUDED
