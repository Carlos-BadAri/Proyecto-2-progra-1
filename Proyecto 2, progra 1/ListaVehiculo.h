#pragma once
#include "nodoVehiculo.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class ListaVehiculo {
private:
    NodoVehiculo* ppio;
public:
    ListaVehiculo();
    virtual ~ListaVehiculo();

    void insertarFinal(NodoVehiculo*);
    string toString();
};
