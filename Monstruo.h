#ifndef MONSTRUO_H_INCLUDED
#define MONSTRUO_H_INCLUDED

class Monstruo{
private:
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
        ataque = ataque + _ataque;
    }

    ///GETTERS
    int get_vida(){return vida;}
    int get_ataque(){return ataque;}
};

#endif // MONSTRUO_H_INCLUDED
