#pragma once
#include "NodoSucursal.h"
#include <sstream>
#include <string>
using namespace std;

class ListaSucursal {
private:
    NodoSucursal* ppio;
    NodoSucursal* actual;
public:
    ListaSucursal();
    virtual ~ListaSucursal();
    void insertarInicio(NodoSucursal*);
    void insertarFinal(NodoSucursal*);
    bool insertarPosicion(NodoSucursal*, int);
    void eliminarInicio();
    void eliminarFinal();
    bool eliminarPosicion(int);
    string toString();
    NodoSucursal* getPpio();
    Sucursal* buscar(string);
    bool Eliminar(const string&);


};
