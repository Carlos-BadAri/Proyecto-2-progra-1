#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Vehiculo.h"
using namespace std;

class Vehiculo;

class EspacioEstacionamiento {
private:
    string codigo;
    string estado; // "Disponible" o "Ocupado"
    Vehiculo* vehiculo;

public:
    EspacioEstacionamiento();
    EspacioEstacionamiento(string codigo);
    ~EspacioEstacionamiento();

    string getCodigo();
    string getEstado();
    Vehiculo* getVehiculo();

    void setCodigo(string codigo);
    void setEstado(string estado);
    void setVehiculo(Vehiculo* vehiculo);

    string toString();
};
