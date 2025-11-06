#pragma once
#include "nodoVehiculo.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class ListaVehiculo {
private:
    NodoVehiculo* ppio;
    NodoVehiculo* actual;
public:
    ListaVehiculo();
    virtual ~ListaVehiculo();

    Vehiculo* buscar(string placa);
    bool eliminar(string placa);

    void insertarFinal(NodoVehiculo*);
    string toString();
};
