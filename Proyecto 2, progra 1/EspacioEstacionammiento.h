#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Vehiculo.h"
using namespace std;

class Vehiculo; // Declaración adelantada

class EspacioEstacionamiento {
private:
    string codigo;
    string estado; // "Disponible" o "Ocupado"
    Vehiculo* vehiculo; // Puede ser nullptr si está libre

public:
    EspacioEstacionamiento();
    EspacioEstacionamiento(string codigo);
    ~EspacioEstacionamiento();

    // Getters y Setters
    string getCodigo();
    string getEstado();
    Vehiculo* getVehiculo();

    void setCodigo(string codigo);
    void setEstado(string estado);
    void setVehiculo(Vehiculo* vehiculo);

    void mostrar();
};
