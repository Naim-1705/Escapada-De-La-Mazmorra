#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class Jugador{
private:
    int vida;
    int damage;
    int armadura;
    int dinero;

public:
    ///CONSTRUCTOR
    Jugador(int v = 100, int d = 7, int a = 5, int m = 0){
        vida = v;
        damage = d;
        armadura = a;
        dinero = m;
    }

    ///SETTERS
    void set_vida(int _vida){
        if(_vida >= 0){
            vida = _vida;
        }
    }
    void set_damage(int _damage){
        if(_damage >= 0){
            damage = _damage;
        }
    }
    void set_armadura(int _armadura){
        if(_armadura >= 0){
            armadura = _armadura;
        }
    }
    void set_dinero(int _dinero){
        dinero = _dinero;
    }

    ///GETTERS
    int get_vida(){return vida;}
    int get_damage(){return damage;}
    int get_armadura(){return armadura;}
    int get_dinero(){return dinero;}
};

#endif // JUGADOR_H_INCLUDED
