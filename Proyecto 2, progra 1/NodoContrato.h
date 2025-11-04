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
    NodoContrato(ContratoAlquiler* c);
    virtual ~NodoContrato();
    void agregarDato(ContratoAlquiler* c);
    void setSiguiente(NodoContrato* sig);
    NodoContrato* getSiguiente();
    ContratoAlquiler* getDato();
};
