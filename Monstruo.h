#ifndef MONSTRUO_H_INCLUDED
#define MONSTRUO_H_INCLUDED
#include <cstring>

class Monstruo{
private:
    char nombre[20];
    int vida;
    int ataque;
public:
    ///CONSTRUCTOR
    Monstruo(int v = 100, int a = 25){
        vida = v;
        ataque = a;
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

    ///GETTERS
    int get_vida(){return vida;}
    int get_ataque(){return ataque;}
    char* get_nombre(){return nombre;}
};

#endif // MONSTRUO_H_INCLUDED
