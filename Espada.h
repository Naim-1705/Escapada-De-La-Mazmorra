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
    Espada(char n[30] = " ", int d = 0, int du = 0){
        strcpy(nombre,n);
        damage = d;
        durabilidad = du;
    }

    ///SETTERS
    void set_nombre(const char* _nombre){
        strcpy(nombre,_nombre);
    }
    void set_damage(int _damage){
        if(_damage >= 0){
            damage = _damage;
        }
    }
    void set_durabilidad(int _durabilidad){
        if(_durabilidad >= 0){
            durabilidad = _durabilidad;
        }
    }

    ///GETTERS
    char* get_nombre(){return nombre;}
    int get_damage(){return damage;}
    int get_durabilidad(){return durabilidad;}

    ///CARGAR
    /*
    bool cargar(){
        Espada armor;
        ArchivoEspada archi;

        int contador = archi.cantidadEspada();

        cout << "Ingrese el nombre de la Espada: ";
        cin.getline(nombre);
        cout << endl;

        for(int i = 0; i < contador; i++){
            if(strcmp(armor.get_nombre(),nombre)==0 && armor.get_estado()){
                cout << "Esta Espada ya existe" << endl;
                return false;
            }
        }

        cout << "Ingrese el Damage de la Espada: ";
        cin >> damage;
        cout << endl;
        while(damage < 0){
            cout << "El Damage no es valido! Ingrese otro valor valido: ";
            cin  >> damage;
            cout << endl;
        }

        cout << "Ingrese la Durabilidad de la Espada: ";
        cin >> durabilidad;
        cout << endl;
        while(durabilidad < 0){
            cout << "Este Damage no es valido! Ingrese otro valor valido: ";
            cin  >> ataque;
            cout << endl;
        }

        estado = true;
        return true;
    }
    */
};

#endif // ESPADA_H_INCLUDED
