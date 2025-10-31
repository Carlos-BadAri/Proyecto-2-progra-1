#pragma once
#include <sstream>
#include <string>
#include "Colaborador.h"
using namespace std;

class NodoColaborador {
private:
    Colaborador* dato;
    NodoColaborador* siguiente;
public:
    NodoColaborador();
    NodoColaborador(Colaborador*);
    virtual ~NodoColaborador();

    void agregarDato(Colaborador*);
    void setSiguiente(NodoColaborador*);
    NodoColaborador* getSiguiente();
};
