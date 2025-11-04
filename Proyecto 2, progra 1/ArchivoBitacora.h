#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ListaBitacora.h"
using namespace std;

class ArchivoBitacora {
private:
    string nombreArchivo;

public:
    ArchivoBitacora(string);
    virtual ~ArchivoBitacora();

    void guardar(ListaBitacora*);
    void cargar(ListaBitacora*);
};
