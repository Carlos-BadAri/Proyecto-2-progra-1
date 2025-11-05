#pragma once
#include <sstream>
#include <string>
#include "ContratoAlquiler.h"
using namespace std;

class NodoContrato {
private:
    ContratoAlquiler* dato;
    NodoContrato* siguiente;
public:
    NodoContrato();
    NodoContrato(ContratoAlquiler*);
    virtual ~NodoContrato();
    void agregarDato(ContratoAlquiler*);
    void setSiguiente(NodoContrato*);
    NodoContrato* getSiguiente();
    ContratoAlquiler* getDato();
};
