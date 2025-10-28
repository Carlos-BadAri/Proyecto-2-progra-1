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

string Cliente::getIdentificacion() { return identificacion; }
string Cliente::getNombre() { return nombre; }
string Cliente::getPaisResidencia() { return paisResidencia; }

void Cliente::setIdentificacion(string identificacion) { this->identificacion = identificacion; }
void Cliente::setNombre(string nombre) { this->nombre = nombre; }
void Cliente::setPaisResidencia(string paisResidencia) { this->paisResidencia = paisResidencia; }

string Cliente::toString() {
    stringstream ss;
    ss << "ID: " << identificacion;
    ss << "Nombre: " << nombre;
    ss << "País: " << paisResidencia;
    cout << ss.str() << endl;
}
