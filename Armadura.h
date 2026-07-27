#ifndef ARMADURA_H_INCLUDED
#define ARMADURA_H_INCLUDED
#include <cstring>

class Armadura{
private:
    char nombre[30];
    int aguante;
    int durabilidad;
    bool estado;
public:
    ///Constructor
    Armadura(const char n[30] = " ",int a = 0, int du = 0,bool e = true){
        strcpy(nombre,n);
        aguante = a;
        durabilidad = du;
        estado = e;
    }

    ///SETTERS
    void set_Nombre(const char* _nombre);

    void set_Aguante(int _aguante);

    void set_Durabilidad(int _durabilidad);

    void set_Estado(bool _estado);

    ///GETTERS
    char* get_Nombre(){return nombre;}

    int get_Aguante(){return aguante;}

    int get_Durabilidad(){return durabilidad;}

    bool get_Estado(){return estado;}

    ///CARGAR

    bool cargar();

    ///MOSTRAR

    void mostrar();
};

#endif // ARMADURA_H_INCLUDED
