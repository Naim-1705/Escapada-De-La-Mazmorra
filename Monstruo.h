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
    Monstruo(int v = 100, int a = 25, bool e = true){
        vida = v;
        ataque = a;
        estado = e;
    }

    ///SETTERS
    void set_vida(int _vida){
        if(_vida >= 0){
            vida = _vida;
        }
    }
    void set_ataque(int _ataque){
        ataque = _ataque;
    }
    void set_nombre(const char* _nombre){
        strcpy(nombre,_nombre);
    }

    void set_estado(bool _estado){
        estado = _estado;
    }

    ///GETTERS
    int get_vida(){return vida;}
    int get_ataque(){return ataque;}
    char* get_nombre(){return nombre;}
    bool get_estado(){return estado;}
};

#endif // MONSTRUO_H_INCLUDED
