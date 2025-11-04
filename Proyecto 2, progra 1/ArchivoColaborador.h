#pragma once
#include <sstream>
#include <string>
#include <fstream>
#include "ListaColaborador.h"
using namespace std;

class ArchivoColaborador {
private:
    string nombreArchivo;

public:
    ArchivoColaborador(string nombreArchivo = "colaboradores.txt");
    virtual ~ArchivoColaborador();

    void guardar(ListaColaborador* lista);
    void cargar(ListaColaborador* lista);
};
