#pragma once
#include <sstream>
#include <string>
#include "Cliente.h"
using namespace std;

class NodoCliente {
private:
    Cliente* dato;
    NodoCliente* siguiente;
public:
    NodoCliente();
    NodoCliente(Cliente*);
    virtual ~NodoCliente();
    void agregarDato(Cliente*);
    void setSiguiente(NodoCliente*);
    Cliente* getDato();
    NodoCliente* getSiguiente();
};
