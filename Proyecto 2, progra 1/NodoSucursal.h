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
    NodoSucursal(Sucursal*);
    virtual ~NodoSucursal();
    void agregarDato(Sucursal*);
    void setSiguiente(NodoSucursal*);
    NodoSucursal* getSiguiente();
    Sucursal* getDato();

};
