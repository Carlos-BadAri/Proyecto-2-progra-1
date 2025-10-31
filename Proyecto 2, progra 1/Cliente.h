#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Cliente {
protected:
    string identificacion;
    string nombre;
    string paisResidencia;

public:
    Cliente();
    Cliente(string , string, string);
    virtual ~Cliente();

    string getId();
    string getNom();
    string getPaisResidencia();

    void setId(string);
    void setNom(string);
    void setPaisResidencia(string);

    virtual string toString();
};
