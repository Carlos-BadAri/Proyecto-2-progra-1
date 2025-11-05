#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ListaContrato.h"
using namespace std;

class ArchivoContrato {
private:
    string nombreArchivo;

public:
    ArchivoContrato(string);
    virtual ~ArchivoContrato();

    void guardar(ListaContrato*);
    void cargar(ListaContrato*);
};
