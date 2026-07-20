#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "archivoConsulta.h"

int ArchivoConsulta::agregarRegistro(){
    Consulta reg;
    int registro;
    FILE *pCon;

    pCon = fopen(nombre,"ab");

    if(pCon == nullptr){
        return -1;
    }

    if(!reg.cargar()){
        cout << "No se cargo correctamente el registro" << endl;
        return -1;
    }

    registro = fwrite(&reg,tamanioRegistro,1,pCon);

    fclose(pCon);
    return registro;
}

bool ArchivoConsulta::bajaLogica(int id){
    Consulta reg;
    int pos = buscarPosicion(id);
    if(pos == -1)return false;

    reg = leerRegistro(pos);

    if(reg.getEstado()==false){
        return false;
    }
    else{
        reg.setEstado(false);
        return modificarRegistro(reg,pos);
    }
}


int ArchivoConsulta::modificarRegistro(Consulta reg,int pos){
    FILE *pCon;
    pCon= fopen(nombre,"rb+");
    if(pCon == nullptr){
        return -1;
    }

    fseek(pCon,pos * tamanioRegistro,0);
    int escribio = fwrite(&reg,tamanioRegistro,1,pCon);

    fclose(pCon);
    return escribio;
}

int ArchivoConsulta::buscarPosicion(int id){
    Consulta reg;
    int pos=0;
    FILE *pCon;

    pCon = fopen(nombre,"rb");

    if(pCon == nullptr){
        return -1;
    }

    while(fread(&reg,tamanioRegistro,1,pCon)==1){
        if(reg.getNumeroConsulta() == id){
            fclose(pCon);
            return pos;
        }
        pos++;
    }
    fclose(pCon);
    return -2;
}

Consulta ArchivoConsulta::leerRegistro(int pos){
    Consulta reg;
    FILE *pCon;
    reg.setNumeroConsulta(-1);

    pCon = fopen(nombre,"rb");

    if(pCon == nullptr){
        return reg;
    }

    fseek(pCon,pos * tamanioRegistro,0);
    fread(&reg,tamanioRegistro,1,pCon);

    fclose(pCon);
    return reg;
}

int ArchivoConsulta::cantidadRegistro(){
    Consulta reg;
    FILE *pCon;

    pCon = fopen(nombre,"rb");

    if(pCon == nullptr){
        return -1;
    }

    fseek(pCon,0,2);
    int tam = ftell(pCon);
    fclose(pCon);

    int cantReg;
    cantReg = tam / tamanioRegistro;
    return cantReg;
}

bool ArchivoConsulta::listarRegistros(){
    Consulta reg;
    FILE *pCon;

    pCon = fopen(nombre,"rb");
    if(pCon == nullptr){
        return false;
    }

    int cant = 1;

    cout << "== LISTADO DE REGISTROS ==" << endl;
    while(fread(&reg,tamanioRegistro,1,pCon)==1){
        if(reg.getEstado()){
            cout << "REGISTRO N"<<cant<< ":"<<endl;
            reg.mostrar();
            cout << endl;
            cant++;
        }
    }
    fclose(pCon);
    return true;
}

bool ArchivoConsulta::listarRegistrosInactivos(){
    Consulta reg;
    FILE *pCon;

    pCon = fopen(nombre,"rb");
    if(pCon == nullptr){
        return false;
    }

    int cant = 1;

    cout << "== LISTADO REGISTROS INACTIVOS ==" << endl;
    while(fread(&reg,tamanioRegistro,1,pCon)==1){
        if(reg.getEstado()==false){
            cout << "REGISTRO N"<<cant<<":"<<endl;
            reg.mostrar();
            cout << endl;
            cant++;
        }
    }
    fclose(pCon);
    return true;
}

bool ArchivoConsulta::listarFecha(){
    Consulta aux;
    int cant = cantidadRegistro();
    if(cant <= 0){
        cout << "no hay registros" << endl;
        return false;
    }

    Consulta *registro;
    registro = new Consulta[cant];

    if(registro == nullptr){
        cout << "Error de memoria" << endl;
        return false;
    }

    ///Cargar vector
    for(int y = 0; y < cant ; y++){
        registro[y] = leerRegistro(y);
    }

    ///Ordenar vector
    for(int i = 0; i < cant; i++){
        for(int j = 0; j < cant; j++){
            if(registro[i].getFechaConsulta().getAnio() > registro[j].getFechaConsulta().getAnio() && j > i){
                aux = registro[i];
                registro[i] = registro[j];
                registro[j] = aux;
            }
            if(registro[i].getFechaConsulta().getAnio() == registro[j].getFechaConsulta().getAnio() && registro[i].getFechaConsulta().getMes() > registro[j].getFechaConsulta().getMes() && j > i){
                aux = registro[i];
                registro[i] = registro[j];
                registro[j] = aux;
            }
            if(registro[i].getFechaConsulta().getAnio() == registro[j].getFechaConsulta().getAnio() && registro[i].getFechaConsulta().getMes() == registro[j].getFechaConsulta().getMes() && registro[i].getFechaConsulta().getDia() > registro[j].getFechaConsulta().getDia() && j > i){
                aux = registro[i];
                registro[i] = registro[j];
                registro[j] = aux;
            }
        }
    }

    int cont = 1;

    cout<<"== LISTADO POR ORDEN DE FECHA REGISTRO =="<<endl;
    for(int x = 0; x < cant; x++){
        if(registro[x].getEstado()==true){
            cout << "REGISTRO N" <<cont<< ":" << endl;
            registro[x].mostrar();
            cout << endl;
            cont++;
        }
    }

    delete[] registro;
    return true;
}

bool ArchivoConsulta::listarPrecio(){
    Consulta aux;
    int cant = cantidadRegistro();
    if(cant <= 0){
        cout << "no hay registros" << endl;
        return false;
    }

    Consulta *precio;
    precio = new Consulta[cant];

    if(precio == nullptr){
        cout << "Error de memoria" << endl;
        return false;
    }

    ///Cargar vector
    for(int y = 0; y < cant ; y++){
        precio[y] = leerRegistro(y);
    }

    ///Ordenar vector
    for(int i = 0; i < cant; i++){
        for(int j = 0; j < cant; j++){
            if(precio[i].getPrecioConsulta() > precio[j].getPrecioConsulta() && j > i){
                aux = precio[i];
                precio[i] = precio[j];
                precio[j] = aux;
            }
        }
    }

    int cont = 1;

    cout<<"== LISTADO POR ORDEN DE FECHA REGISTRO =="<<endl;
    for(int x = 0; x < cant; x++){
        if(precio[x].getEstado()==true){
            cout << "REGISTRO N" <<cont<< ":" << endl;
            precio[x].mostrar();
            cout << endl;
            cont++;
        }
    }

    delete[] precio;
    return true;
}

bool ArchivoConsulta::buscarConsultaPorID(){
    Consulta reg;
    int id;
    cout << "Ingreses el ID de la consulta: ";
    cin >> id;

    int pos = buscarPosicion(id);
    if(pos == -1){
        cout << "Error en memoria" << endl;
        return false;
    }
    if(pos == -2){
        cout << "El ID ingresado no existe dentro del sistema" << endl;
        return false;
    }

    reg = leerRegistro(pos);

    cout << "== CONSULTA BUSCADA POR ID ==" << endl;

    reg.mostrar();
    return true;
}

bool ArchivoConsulta::buscarPorRangoFechaMedicamento(){
    Consulta reg;
    int anioMin,anioMax;
    cout << "Ingrese el anio minimo del inicio del medicamento: ";
    cin >> anioMin;
    cout << endl;
    cout << "Ingrese el anio maximo del inicio del medicamento: ";
    cin >> anioMax;
    cout << endl;

    int cant = cantidadRegistro();
    if(cant <= 0){
        cout << "No hay registros para mostrar" << endl;
        return false;
    }

    int cont = 1;
    int alMenosUno = 0;

    for(int i = 0; i < cant; i++){
        reg = leerRegistro(i);
        if(reg.getFechaInicioMedicamento().getAnio() >= anioMin && reg.getFechaInicioMedicamento().getAnio() <= anioMax && reg.getIDMedicamento() > 0){
            cout << "REGISTRO N" << cont << ":" << endl;
            reg.mostrar();
            cont++;
            alMenosUno = 1;
            cout << endl;
        }
    }

    if(alMenosUno == 0){
        cout << "No hay registros con el inicio de medicacion entre esos anios" << endl;
        return false;
    }

    return true;

}

bool ArchivoConsulta::buscarPorRangoFechaConsulta(){
    Consulta reg;
    int anioMin,anioMax;
    cout << "Ingrese el anio minimo de la consulta: ";
    cin >> anioMin;
    cout << endl;
    cout << "Ingrese el anio maximo de la consulta: ";
    cin >> anioMax;
    cout << endl;

    int cant = cantidadRegistro();
    if(cant <= 0){
        cout << "No hay registros para mostrar" << endl;
        return false;
    }

    int cont = 1;
    int alMenosUno = 0;

    for(int i = 0; i < cant; i++){
        reg = leerRegistro(i);
        if(reg.getFechaConsulta().getAnio() >= anioMin && reg.getFechaConsulta().getAnio() <= anioMax){
            cout << "REGISTRO N" << cont << ":" << endl;
            reg.mostrar();
            cont++;
            alMenosUno = 1;
            cout << endl;
        }
    }

    if(alMenosUno == 0){
        cout << "No hay registros con el inicio de medicacion entre esos anios" << endl;
        return false;
    }

    return true;
}

bool ArchivoConsulta::buscarPorRangoPrecioConsulta(){
    Consulta reg;
    float precioMin,precioMax;
    cout << "Ingrese el precio minimo de la consulta: $";
    cin >> precioMin;
    cout << endl;
    cout << "Ingrese el precio maximo de la consulta: $";
    cin >> precioMax;
    cout << endl;

    int cant = cantidadRegistro();
    if(cant <= 0){
        cout << "No hay registros para mostrar" << endl;
        return false;
    }

    int cont = 1;
    int alMenosUno = 0;

    for(int i = 0; i < cant; i++){
        reg = leerRegistro(i);
        if(reg.getPrecioConsulta() >= precioMin && reg.getPrecioConsulta() <= precioMax){
            cout << "REGISTRO N" << cont << ":" << endl;
            reg.mostrar();
            cont++;
            alMenosUno = 1;
            cout << endl;
        }
    }

    if(alMenosUno == 0){
        cout << "No hay registros con el inicio de medicacion entre esos anios" << endl;
        return false;
    }

    return true;
}

bool ArchivoConsulta::buscarPorIDMedicamento(){
    Consulta reg;
    int id;
    cout << "Ingrese el ID del medicamento: ";
    cin >> id;
    cout << endl;

    int cant = cantidadRegistro();
    if(cant <= 0){
        cout << "No hay registros para mostrar" << endl;
        return false;
    }

    int cont = 1;
    int alMenosUno = 0;

    for(int i = 0; i < cant; i++){
        reg = leerRegistro(i);
        if(reg.getIDMedicamento() == id){
            cout << "REGISTRO N" << cont << ":" << endl;
            reg.mostrar();
            cont++;
            alMenosUno = 1;
            cout << endl;
        }
    }

    if(alMenosUno == 0){
        cout << "No hay registros con el inicio de medicacion entre esos anios" << endl;
        return false;
    }

    return true;
}

bool ArchivoConsulta::copiaSeguridad(){
    Consulta reg;

     FILE *pCo;
     FILE *pConsulta;

     pCo = fopen("copiaConsulta.dat","wb");
     pConsulta = fopen(nombre,"rb");

     if(pCo == nullptr || pConsulta == nullptr){
        fclose(pConsulta);
        fclose(pCo);
        cout << "Error en memoria" << endl;
        return false;
     }

     while(fread(&reg,tamanioRegistro,1,pConsulta)==1){
        fwrite(&reg,tamanioRegistro,1,pCo);
     }

     fclose(pConsulta);
     fclose(pCo);

     return true;
}

bool ArchivoConsulta::reestablecer(){
    Consulta reg;

     FILE *pCo;
     FILE *pConsulta;

     pCo = fopen("copiaConsulta.dat","rb");
     pConsulta = fopen(nombre,"wb");

     if(pCo == nullptr || pConsulta == nullptr){
        fclose(pConsulta);
        fclose(pCo);
        cout << "Error en memoria" << endl;
        return false;
     }

    while(fread(&reg,tamanioRegistro,1,pCo)==1){
        fwrite(&reg,tamanioRegistro,1,pConsulta);
     }

     fclose(pConsulta);
     fclose(pCo);

     return true;
}
