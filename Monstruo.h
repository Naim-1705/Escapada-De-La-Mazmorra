#ifndef MONSTRUO_H_INCLUDED
#define MONSTRUO_H_INCLUDED
#include <cstring>

#include "archivoMonstruo.h"

class Monstruo{
private:
    int id;
    char nombre[20];
    int vida;
    int ataque;
    bool estado;
public:
    ///CONSTRUCTOR
    Monstruo(int v = 100, int a = 25, bool e = true, int i = -1){
        vida = v;
        ataque = a;
        estado = e;
        id = i;
    }

    ///SETTERS
    void set_id(int _id){
        if(_id >= 0){
            id = _id;
        }
    }
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
    int getId(){return id;}
    int get_vida(){return vida;}
    int get_ataque(){return ataque;}
    char* get_nombre(){return nombre;}
    bool get_estado(){return estado;}

    bool cargar(){
        Monstruo mon;
        ArchivoMonstruo archi;

        int contador = archi.cantidadMonstruo();

        cout << "Ingrese el nombre del Monstruo: ";
        cin >> nombre;
        cout << endl;

        for(int i = 0; i < contador; i++){
            if(strcmp(mon.get_nombre(),nombre)==0 && mon.get_estado()){
                cout << "Este Monstruo ya existe" << endl;
                return false;
            }
        }

        id = contador + 1;

        cout << "Ingrese la vida del Monstruo: ";
        cin >> vida;
        cout << endl;
        while(vida < 0){
            cout << "Esta vida no es valido! Ingrese otro valor valido: ";
            cin  >> vida;
            cout << endl;
        }

        cout << "Ingrese el Damage del Monstruo: ";
        cin >> ataque;
        cout << endl;
        while(ataque < 0){
            cout << "Este Damage no es valido! Ingrese otro valor valido: ";
            cin  >> ataque;
            cout << endl;
        }

        estado = true;
        return true;
    }
};

#endif // MONSTRUO_H_INCLUDED
