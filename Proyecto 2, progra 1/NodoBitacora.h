#pragma once
#include <sstream>
#include <string>
#include "BitacoraEstado.h"
using namespace std;

class NodoBitacora {
private:
    BitacoraEstado* dato;
    NodoBitacora* siguiente;
public:
    NodoBitacora();
    NodoBitacora(BitacoraEstado*);
    virtual ~NodoBitacora();
    void agregarDato(BitacoraEstado*);
    void setSiguiente(NodoBitacora*);
    BitacoraEstado* getDato();
    NodoBitacora* getSiguiente();
};
