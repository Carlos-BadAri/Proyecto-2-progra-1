#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Sucursal {
private:
    string codigo;
    string nombre;
    string direccion;
    string pais;

public:
    Sucursal();
    Sucursal(string, string, string, string);
    ~Sucursal();

    string getCodigo();
    string getNombre();
    string getDireccion();
    string getPais();

    void setCodigo(string);
    void setNombre(string);
    void setDireccion(string);
    void setPais(string);

    string toString();
};
