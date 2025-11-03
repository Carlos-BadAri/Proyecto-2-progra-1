#pragma once
#include <sstream>
#include <string>
#include "Vehiculo.h"
using namespace std;

class NodoVehiculo {
private:
    Vehiculo* dato;
    NodoVehiculo* siguiente;
public:
    NodoVehiculo();
    NodoVehiculo(Vehiculo*);
    virtual ~NodoVehiculo();
    void agregarDato(Vehiculo*);
    void setSiguiente(NodoVehiculo*);
    NodoVehiculo* getSiguiente();
    Vehiculo* getDato();
};
