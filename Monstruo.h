#ifndef MONSTRUO_H_INCLUDED
#define MONSTRUO_H_INCLUDED
#include <cstring>

class Monstruo{
private:
    char nombre[20];
    int vida;
    int ataque;
    bool estado;
public:
    ///CONSTRUCTOR
    Monstruo(const char n[20] = " ", int v = 100, int a = 25, bool e = true, int i = -1){
        strcpy(nombre,n);
        vida = v;
        ataque = a;
        estado = e;
    }

    ///SETTERS
    void set_id(int _id);

    void set_vida(int _vida);

    void set_ataque(int _ataque);

    void set_nombre(const char* _nombre);

    void set_estado(bool _estado);

    ///GETTERS
    int get_vida(){return vida;}
    int get_ataque(){return ataque;}
    char* get_nombre(){return nombre;}
    bool get_estado(){return estado;}

    ///CARGAR

    bool cargar();

    void mostrar();
};

#endif // MONSTRUO_H_INCLUDED
