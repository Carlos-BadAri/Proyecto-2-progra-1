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
    Vehiculo(string placa, string marca, string modelo, string color, int anio);
    ~Vehiculo();

    // Getters y Setters
    string getPlaca();
    string getMarca();
    string getModelo();
    string getColor();
    int getAnio();
    BitacoraEstado* getBitacora();

    void setPlaca(string placa);
    void setMarca(string marca);
    void setModelo(string modelo);
    void setColor(string color);
    void setAnio(int anio);
    void setBitacora(BitacoraEstado* bitacora);

    string toString();
};
