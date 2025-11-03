#pragma once
#include <sstream>
#include <string>
#include "NodoColaborador.h"
using namespace std;

class ListaColaborador {
private:
    NodoColaborador* primero;
    NodoColaborador* actual;

public:
    ListaColaborador();
    virtual ~ListaColaborador();
    void agregar(Colaborador* c);
    Colaborador* buscar(string id);
    string toString();
};
