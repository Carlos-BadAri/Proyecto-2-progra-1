#pragma once
#include <sstream>
#include <string>
#include "Sucursal.h"
using namespace std;

class NodoSucursal {
private:
    Sucursal* dato;
    NodoSucursal* siguiente;
public:
    NodoSucursal();
    NodoSucursal(Sucursal* s);
    virtual ~NodoSucursal();
    void agregarDato(Sucursal* s);
    void setSiguiente(NodoSucursal* sig);
    NodoSucursal* getSiguiente();
    Sucursal* getDato();

};
