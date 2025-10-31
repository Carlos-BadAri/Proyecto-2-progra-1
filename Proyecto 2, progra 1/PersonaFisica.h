#pragma once
#include "CLiente.h"

class PersonaFisica : public Cliente {
public:
    PersonaFisica();
    PersonaFisica(string, string, string);
    ~PersonaFisica();

    string toString() override;
};
