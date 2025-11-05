#pragma once
#include "NodoContrato.h"
#include <sstream>
#include <string>
using namespace std;

class ListaContrato {
private:
    NodoContrato* ppio;
public:
    ListaContrato();
    virtual ~ListaContrato();
    void insertarInicio(NodoContrato*);
    void insertarFinal(NodoContrato*);
    bool insertarPosicion(NodoContrato*, int);
    void eliminarInicio();
    void eliminarFinal();
    bool eliminarPosicion(int);
    string toString();
    NodoContrato* getPpio();
};
