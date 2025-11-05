#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "BitacoraEstado.h"
using namespace std;

class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;
    string color;
    int anio;
    BitacoraEstado* bitacora;

public:
    Vehiculo();
    Vehiculo(string, string, string, string, int);
    ~Vehiculo();
            
    string getPlaca();
    string getMarca();
    string getModelo();
    string getColor();
    int getAnio();
    BitacoraEstado* getBitacora();

    void setPlaca(string);
    void setMarca(string);
    void setModelo(string);
    void setColor(string);
    void setAnio(int);
    void setBitacora(BitacoraEstado*);

    string toString();
};
