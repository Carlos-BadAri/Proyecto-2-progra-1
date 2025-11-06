#pragma once
#include <sstream>
#include <string>
#include "NodoColaborador.h"
using namespace std;

class ListaColaborador {
private:
    NodoColaborador* ppio;
    NodoColaborador* actual;

public:
    ListaColaborador();
    virtual ~ListaColaborador();
    void agregar(Colaborador*);
    Colaborador* buscar(string);
    string toString();
    bool eliminar(string);

};
