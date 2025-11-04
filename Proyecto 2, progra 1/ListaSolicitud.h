#pragma once
#include "NodoSolicitud.h"
#include <sstream>
#include <string>
using namespace std;

class ListaSolicitud {
private:
    NodoSolicitud* ppio;
    NodoSolicitud* actual;
public:
    ListaSolicitud();
    virtual ~ListaSolicitud();
    void insertarInicio(NodoSolicitud* n);
    void insertarFinal(NodoSolicitud* n);
    bool insertarPosicion(NodoSolicitud* n, int pos);
    void eliminarInicio();
    void eliminarFinal();
    bool eliminarPosicion(int pos);
    string toString();
};
