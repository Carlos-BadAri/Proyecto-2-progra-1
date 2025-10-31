#pragma once
#include "Cliente.h"

class PersonaJuridica : public Cliente {
private:
    string actividadEconomica;
    double porcentajeDescuento;

public:
    PersonaJuridica();
    PersonaJuridica(string,string,string,string,double);
    ~PersonaJuridica();

    string getActividadEconomica();
    double getPorcentajeDescuento();

    void setActividadEconomica(string);
    void setPorcentajeDescuento(double);

    string toString() override;
};
