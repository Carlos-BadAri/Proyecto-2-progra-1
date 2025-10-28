#pragma once
#include "EspacioEstacionammiento.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Plantel
{
private:
    char letra;       // Ejemplo: 'A', 'B', ...
    int tipo;         // 1 a 4
    int filas;
    int columnas;
    int capacidadMax;
    EspacioEstacionamiento** matriz; // Matriz dinámica de espacios

public:
    Plantel();
    Plantel(char letra, int tipo, int filas, int columnas);
    ~Plantel();

    // Métodos principales
    void mostrarMatriz();
    void recomendarEspacios();

    // Getters y Setters
    char getLetra();
    int getTipo();
    int getFilas();
    int getColumnas();
    int getCapacidadMax();
    EspacioEstacionamiento** getMatriz();

    void setLetra(char letra);
    void setTipo(int tipo);
    void setFilas(int filas);
    void setColumnas(int columnas);
};

