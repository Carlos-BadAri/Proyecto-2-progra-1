#include "Cliente.h"

Cliente::Cliente() {
    identificacion = "";
    nombre = "";
    paisResidencia = "";
}

Cliente::Cliente(string identificacion, string nombre, string paisResidencia) {
    this->identificacion = identificacion;
    this->nombre = nombre;
    this->paisResidencia = paisResidencia;
}

Cliente::~Cliente() {}

string Cliente::getId() {
    return identificacion; 
}
string Cliente::getNom() { 
    return nombre;
}
string Cliente::getPaisResidencia() {
    return paisResidencia;
}

void Cliente::setId(string identificacion) {
    this->identificacion = identificacion;
}
void Cliente::setNom(string nombre) { 
    this->nombre = nombre; 
}
void Cliente::setPaisResidencia(string paisResidencia) { 
    this->paisResidencia = paisResidencia; 
}

string Cliente::toString() {
    stringstream ss;
    ss << "ID: " << identificacion << endl;
    ss << "Nombre: " << nombre << endl;
    ss << "País: " << paisResidencia << endl;
    return ss.str();

}
