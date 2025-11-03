#pragma once
#include "EspacioEstacionammiento.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Plantel
{
private:
    char letra;
    int tipo;
    int filas;
    int columnas;
    int capacidadMax;
    EspacioEstacionamiento** matriz; // Matriz dinámica de espacios

public:
    Plantel();
    Plantel(char, int, int, int);
    ~Plantel();

    void mostrarMatriz();
    void recomendarEspacios();

    char getLetra();
    int getTipo();
    int getFilas();
    int getColumnas();
    int getCapacidadMax();
    EspacioEstacionamiento** getMatriz();

    void setLetra(char);
    void setTipo(int);
    void setFilas(int);
    void setColumnas(int);

    string toString();
};

