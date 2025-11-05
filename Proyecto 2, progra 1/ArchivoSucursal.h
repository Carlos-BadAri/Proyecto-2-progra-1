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
    ArchivoSucursal(string);
    virtual ~ArchivoSucursal();

    void guardar(ListaSucursal*);
    void cargar(ListaSucursal*);
};