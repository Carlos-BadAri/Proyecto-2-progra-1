#include "Sucursal.h"

Sucursal::Sucursal() {
    codigo = "";
    nombre = "";
    direccion = "";
    pais = "";
}

Sucursal::Sucursal(string codigo, string nombre, string direccion, string pais) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->direccion = direccion;
    this->pais = pais;
}

Sucursal::~Sucursal() {}

string Sucursal::getCodigo() {
    return codigo; 
}
string Sucursal::getNombre() {
    return nombre;
}
string Sucursal::getDireccion() {
    return direccion;
}
string Sucursal::getPais() {
    return pais;
}

void Sucursal::setCodigo(string codigo) {
    this->codigo = codigo; 
}
void Sucursal::setNombre(string nombre) {
    this->nombre = nombre; 
}
void Sucursal::setDireccion(string direccion) { 
    this->direccion = direccion; 
}
void Sucursal::setPais(string pais) {
    this->pais = pais;
}

string Sucursal::toString() {
    stringstream ss;
    ss << "[Sucursal] " << endl;
    ss << "Código: " << codigo << endl;
    ss << "Nombre: " << nombre << endl;
    ss << "Dirección: " << direccion << endl;
    ss << "País: " << pais << endl;
    return ss.str();

}
