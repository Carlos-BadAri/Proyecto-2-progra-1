#pragma once
#include <sstream>
#include <string>
#include "NodoCliente.h"
using namespace std;

class ListaCliente {
private:
    NodoCliente* ppio;
    NodoCliente* actual;

public:
    ListaCliente();
    virtual ~ListaCliente();
    void agregar(Cliente*);
    Cliente* buscar(string);
    string toString();
};
