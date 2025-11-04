#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ListaSucursal.h"
using namespace std;

class ArchivoSucursal {
private:
    string nombreArchivo;

public:
    ArchivoSucursal(string nombreArchivo);
    virtual ~ArchivoSucursal();

    void guardar(ListaSucursal* lista);
    void cargar(ListaSucursal* lista);
};