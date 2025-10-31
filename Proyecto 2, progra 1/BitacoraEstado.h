#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class BitacoraEstado {
private:
    string fecha;
    string horaEntrada;
    string horaSalida;
    string descripcion;

public:
    BitacoraEstado();
    BitacoraEstado(string, string, string, string);
    ~BitacoraEstado();

    string getFecha();
    string getHoraEntrada();
    string getHoraSalida();
    string getDescripcion();

    void setFecha(string);
    void setHoraEntrada(string);
    void setHoraSalida(string);
    void setDescripcion(string);

    string toString();
};
