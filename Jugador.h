#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <cstring>
#include "Espada.h"
#include "Armadura.h"
#include "Habilidad.h"

class Jugador{
private:
    char nombre[30];
    int vida;
    int damage;
    int armadura;
    int dinero;
    Espada sword;
    Armadura armor;
    Habilidad ability;

public:
    ///CONSTRUCTOR
    Jugador(const char n[30] = " ",int v = 100, int d = 7, int a = 5, int m = 0, Espada e = Espada(), Armadura ar = Armadura(), Habilidad ab = Habilidad()){
        strcpy(nombre,n);
        vida = v;
        damage = d;
        armadura = a;
        dinero = m;
        sword = e;
        armor = ar;
        ability = ab;
    }

    ///SETTERS
    void set_nombre(const char* _nombre);

    void set_vida(int _vida);

    void set_damage(int _damage);

    void set_armadura(int _armadura);

    void set_dinero(int _dinero);

    void set_sword(Espada _sword);

    void set_armor(Armadura _armor);

    void set_ability(Habilidad _ability);

    ///GETTERS
    char* get_nombre(){return nombre;}
    int get_vida(){return vida;}
    int get_damage(){return damage;}
    int get_armadura(){return armadura;}
    int get_dinero(){return dinero;}
    Espada get_sword(){return sword;}
    Armadura get_armor(){return armor;}
    Habilidad get_ability(){return ability;}

    ///CARGAR
    bool cargar();

    ///MOSTRAR
    void mostrar();
};

#endif // JUGADOR_H_INCLUDED
