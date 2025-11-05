#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include "ListaSolicitud.h"
#include "Cliente.h"
#include "Vehiculo.h"
using namespace std;

class ArchivoSolicitud {
private:
    string nombreArchivo;

public:
    ArchivoSolicitud(string nombreArchivo = "solicitudes.txt");
    virtual ~ArchivoSolicitud();

    void guardar(ListaSolicitud*);
    void cargar(ListaSolicitud*);
};
