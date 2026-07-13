#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class Jugador{
private:
    int vida;
    int arco;
    int espada;
public:
    ///CONSTRUCTOR
    Jugador(int v = 100, int a = 15, int e = 30){
        vida = v;
        arco = a;
        espada = e;
    }

    ///SETTERS
    void set_vida(int _vida){
        if(_vida >= 0){
            vida = _vida;
        }
    }
    void set_arco(int _arco){
        arco = arco + _arco;
    }
    void set_espada(int _espada){
        espada = espada + _espada;
    }

    ///GETTERS
    int get_vida(){return vida;}
    int get_arco(){return arco;}
    int get_espada(){return espada;}
};

#endif // JUGADOR_H_INCLUDED
