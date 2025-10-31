#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Colaborador {
private:
    string idColaborador;
    string nombre;
    string puesto;
    string sucursalAsignada;

public:
    Colaborador();
    Colaborador(string, string, string, string);
    ~Colaborador();

    string getIdColaborador();
    string getNombre();
    string getPuesto();
    string getSucursalAsignada();

    void setIdColaborador(string);
    void setNombre(string);
    void setPuesto(string);
    void setSucursalAsignada(string);

    string toString();
};
