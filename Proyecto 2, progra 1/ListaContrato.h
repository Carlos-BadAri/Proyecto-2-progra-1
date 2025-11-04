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
    void insertarInicio(NodoContrato* n);
    void insertarFinal(NodoContrato* n);
    bool insertarPosicion(NodoContrato* n, int pos);
    void eliminarInicio();
    void eliminarFinal();
    bool eliminarPosicion(int pos);
    string toString();
};
