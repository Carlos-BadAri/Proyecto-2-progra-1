#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ListaPlantel.h"
using namespace std;

class ArchivoPlantel {
private:
    string nombreArchivo;

public:
    ArchivoPlantel(string nombreArchivo = "planteles.txt");
    ~ArchivoPlantel();

    void guardar(ListaPlantel*);
    void cargar(ListaPlantel*);
};
