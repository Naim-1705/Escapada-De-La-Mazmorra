#ifndef HABILIDAD_H_INCLUDED
#define HABILIDAD_H_INCLUDED
#include <cstring>

class Habilidad{
private:
    char nombre[30];
    int damage;
    ///EXTRA efecto;
    int cooldown;
    bool estado;
public:
    ///CONSTRUCTOR
    Habilidad(const char n[30] = " ", int d = 1,int c = 1, bool e = true){
        strcpy(nombre,n);
        damage = d;
        cooldown = c;
        estado = e;
    }

    ///SETTERS
    void set_nombre(const char* _nombre);

    void set_damage(int _damage);

    void set_cooldown(int _cooldown);

    void set_estado(bool _estado);

    ///GETTERS
    char* get_nombre(){return nombre;}

    int get_damage(){return damage;}

    int get_cooldown(){return cooldown;}

    bool get_estado(){return estado;}

    ///CARGAR
    bool cargar();

    ///MOSTRAR
    void mostrar();
};

#endif // HABILIDAD_H_INCLUDED
