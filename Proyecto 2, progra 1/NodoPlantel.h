#pragma once
#include <sstream>
#include <string>
#include "Plantel.h"
using namespace std;

class NodoPlantel {
private:
    Plantel* dato;
    NodoPlantel* siguiente;
public:
    NodoPlantel();
    NodoPlantel(Plantel*);
    virtual ~NodoPlantel();
    void agregarDato(Plantel*);
    void setSiguiente(NodoPlantel*);
    NodoPlantel* getSiguiente();
    Plantel* getDato();
};
