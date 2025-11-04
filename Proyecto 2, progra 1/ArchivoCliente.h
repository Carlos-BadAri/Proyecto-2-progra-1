#pragma once
#include <sstream>
#include <string>
#include <fstream>
#include "ListaCliente.h"
using namespace std;

class ArchivoCliente {
public:
    ArchivoCliente();
    virtual ~ArchivoCliente();

    void guardar(ListaCliente* lista);
    void cargar(ListaCliente* lista);
};
