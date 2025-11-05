#pragma once
#include <sstream>
#include <string>
#include <fstream>
#include "ListaVehiculo.h"
using namespace std;

class ArchivoVehiculo {
public:
    ArchivoVehiculo();
    virtual ~ArchivoVehiculo();

    void guardar(ListaVehiculo*);
    void cargar(ListaVehiculo*);
};
