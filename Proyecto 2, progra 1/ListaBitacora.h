#pragma once
#include <sstream>
#include <string>
#include "NodoBitacora.h"
using namespace std;

class ListaBitacora {
private:
    NodoBitacora* ppio;
    NodoBitacora* actual;

public:
    ListaBitacora();
    virtual ~ListaBitacora();
    void agregar(BitacoraEstado*);
    string toString();
};
