#pragma once
#include <sstream>
#include <string>
#include "SolicitudAlquiler.h"
using namespace std;

class NodoSolicitud {
private:
    SolicitudAlquiler* dato;
    NodoSolicitud* siguiente;
public:
    NodoSolicitud();
    NodoSolicitud(SolicitudAlquiler*);
    virtual ~NodoSolicitud();
    void agregarDato(SolicitudAlquiler*);
    void setSiguiente(NodoSolicitud*);
    NodoSolicitud* getSiguiente();
};
