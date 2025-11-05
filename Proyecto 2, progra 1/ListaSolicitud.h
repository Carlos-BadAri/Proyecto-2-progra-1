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
    void insertarInicio(NodoSolicitud*);
    void insertarFinal(NodoSolicitud*);
    bool insertarPosicion(NodoSolicitud*, int);
    void eliminarInicio();
    void eliminarFinal();
    bool eliminarPosicion(int);
    string toString();
    NodoSolicitud* getPpio();

};
