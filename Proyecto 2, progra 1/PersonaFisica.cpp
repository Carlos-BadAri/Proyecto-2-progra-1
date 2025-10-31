#include "PersonaFisica.h"

PersonaFisica::PersonaFisica() : Cliente() {
}

PersonaFisica::PersonaFisica(string identificacion, string nombre, string paisResidencia): Cliente(identificacion, nombre, paisResidencia) {
}

PersonaFisica::~PersonaFisica() {}

string PersonaFisica::toString() {
    stringstream ss;
    ss << "[Persona Física] " << endl;
    ss << "ID: " << identificacion << endl;
    ss << "Nombre: " << nombre << endl;
    ss << "País: " << paisResidencia << endl;
    return ss.str();
}
