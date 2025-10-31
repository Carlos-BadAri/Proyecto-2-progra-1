#include "PersonaJuridica.h"

PersonaJuridica::PersonaJuridica() : Cliente() {
    actividadEconomica = "";
    porcentajeDescuento = 0.0;
}

PersonaJuridica::PersonaJuridica(string identificacion, string nombre, string paisResidencia,string actividadEconomica, double porcentajeDescuento): Cliente(identificacion, nombre, paisResidencia) {
    this->actividadEconomica = actividadEconomica;
    this->porcentajeDescuento = porcentajeDescuento;
}

PersonaJuridica::~PersonaJuridica() {
}

string PersonaJuridica::getActividadEconomica() {
    return actividadEconomica; 
}
double PersonaJuridica::getPorcentajeDescuento() {
    return porcentajeDescuento;
}

void PersonaJuridica::setActividadEconomica(string actividadEconomica) {
    this->actividadEconomica = actividadEconomica;
}

void PersonaJuridica::setPorcentajeDescuento(double porcentajeDescuento) {
    this->porcentajeDescuento = porcentajeDescuento;
}

string PersonaJuridica::toString() {
    stringstream ss;
    ss << "[Persona Jurídica] " << endl;
    ss << "ID: " << identificacion << endl;
    ss << "Nombre: " << nombre << endl;
    ss << "País: " << paisResidencia << endl;
    ss << "Actividad: " << actividadEconomica << endl;
    ss << "Descuento: " << porcentajeDescuento << endl;
    return ss.str();
}
