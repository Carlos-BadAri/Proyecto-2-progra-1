#pragma once
#include "nodoPlantel.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class ListaPlantel {
private:
    NodoPlantel* ppio;
public:
    ListaPlantel();
    virtual ~ListaPlantel();

    void insertarFinal(NodoPlantel* n);
    string toString();
};
