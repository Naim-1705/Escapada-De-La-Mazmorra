#ifndef ESPADA_H_INCLUDED
#define ESPADA_H_INCLUDED
#include <cstring>

class Espada{
private:
    char nombre[30];
    int damage;
    ///EFECTO encantamiento;
    int durabilidad;
    bool estado;

public:
    ///CONSTRUCTOR
    Espada(const char n[30] = " ", int d = 0, int du = 0, bool e = true){
        strcpy(nombre,n);
        damage = d;
        durabilidad = du;
        estado = e;
    }

    ///SETTERS
    void set_nombre(const char* _nombre);

    void set_damage(int _damage);

    void set_durabilidad(int _durabilidad);

    void set_estado(bool _estado);

    ///GETTERS
    char* get_nombre(){return nombre;}
    int get_damage(){return damage;}
    int get_durabilidad(){return durabilidad;}
    bool get_estado(){return  estado;}

    ///CARGAR
    bool cargar();

    ///MOSTRAR

    void mostrar();
};

#endif // ESPADA_H_INCLUDED
