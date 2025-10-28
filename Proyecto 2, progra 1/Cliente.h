#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Cliente {
protected:
    string identificacion;
    string nombre;
    string paisResidencia;

public:
    Cliente();
    Cliente(string identificacion, string nombre, string paisResidencia);
    virtual ~Cliente();

    // Getters
    string getIdentificacion();
    string getNombre();
    string getPaisResidencia();

    // Setters
    void setIdentificacion(string identificacion);
    void setNombre(string nombre);
    void setPaisResidencia(string paisResidencia);

    virtual string toString();
};
