#include "Colaborador.h"

Colaborador::Colaborador() {
    idColaborador = "";
    nombre = "";
    puesto = "";
    sucursalAsignada = "";
}

Colaborador::Colaborador(string idColaborador, string nombre, string puesto, string sucursalAsignada) {
    this->idColaborador = idColaborador;
    this->nombre = nombre;
    this->puesto = puesto;
    this->sucursalAsignada = sucursalAsignada;
}

Colaborador::~Colaborador() {}

string Colaborador::getId() { 
    return idColaborador; 
}
string Colaborador::getNom() {
    return nombre; 
}
string Colaborador::getPuesto() {
    return puesto; 
}
string Colaborador::getSucursalAsignada() {
    return sucursalAsignada;
}

void Colaborador::setIdColaborador(string idColaborador) {
    this->idColaborador = idColaborador; 
}
void Colaborador::setNombre(string nombre) {
    this->nombre = nombre;
}
void Colaborador::setPuesto(string puesto) {
    this->puesto = puesto; 
}
void Colaborador::setSucursalAsignada(string sucursalAsignada) {
    this->sucursalAsignada = sucursalAsignada;
}

string Colaborador::toString() {
    stringstream ss;
    ss << "[Colaborador] " << endl;
    ss << "ID: " << idColaborador << endl;
    ss << "Nombre: " << nombre << endl;
    ss << "Puesto: " << puesto << endl;
    ss << "Sucursal: " << sucursalAsignada << endl;
    return ss.str();
}
