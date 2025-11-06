#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "BitacoraEstado.h"
#include <fstream>
using namespace std;

class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;
    string color;
    int anio;
    BitacoraEstado* bitacora;
    string estado;

public:
    Vehiculo();
    Vehiculo(string, string, string, string, int,string);
    ~Vehiculo();
            
    string getPlaca();
    string getMarca();
    string getModelo();
    string getColor();
    int getAnio();
    BitacoraEstado* getBitacora();
    string getEstado();

    void setPlaca(string);
    void setMarca(string);
    void setModelo(string);
    void setColor(string);
    void setAnio(int);
    void setBitacora(BitacoraEstado*);
    void setEstado(string);

    string toString();
    void registrarCambioEstado(string,string,string,string);
};
