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
    void insertarInicio(NodoSucursal* n);
    void insertarFinal(NodoSucursal* n);
    bool insertarPosicion(NodoSucursal* n, int pos);
    void eliminarInicio();
    void eliminarFinal();
    bool eliminarPosicion(int pos);
    string toString();
    NodoSucursal* getPpio();

};
