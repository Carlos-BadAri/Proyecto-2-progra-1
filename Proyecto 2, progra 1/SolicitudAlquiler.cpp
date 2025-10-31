#include "SolicitudAlquiler.h"

SolicitudAlquiler::SolicitudAlquiler() {
    idSolicitud = "";
    fechaSolicitud = "";
    estado = "Pendiente";
    cliente = nullptr;
    vehiculo = nullptr;
}

SolicitudAlquiler::SolicitudAlquiler(string idSolicitud, string fechaSolicitud, string estado, Cliente* cliente, Vehiculo* vehiculo) {
    this->idSolicitud = idSolicitud;
    this->fechaSolicitud = fechaSolicitud;
    this->estado = estado;
    this->cliente = cliente;
    this->vehiculo = vehiculo;
}

SolicitudAlquiler::~SolicitudAlquiler() {
    // No destruye cliente ni vehiculo, ya que no son propiedad de la solicitud.
}

string SolicitudAlquiler::getIdSolicitud() {
    return idSolicitud;
}
string SolicitudAlquiler::getFechaSolicitud() {
    return fechaSolicitud; 
}
string SolicitudAlquiler::getEstado() {
    return estado;
}
Cliente* SolicitudAlquiler::getCliente() { 
    return cliente;
}
Vehiculo* SolicitudAlquiler::getVehiculo() { 
    return vehiculo;
}

void SolicitudAlquiler::setIdSolicitud(string idSolicitud) {
    this->idSolicitud = idSolicitud; 
}
void SolicitudAlquiler::setFechaSolicitud(string fechaSolicitud) {
    this->fechaSolicitud = fechaSolicitud;
}
void SolicitudAlquiler::setEstado(string estado) { 
    this->estado = estado; 
}
void SolicitudAlquiler::setCliente(Cliente* cliente) {
    this->cliente = cliente;
}
void SolicitudAlquiler::setVehiculo(Vehiculo* vehiculo) {
    this->vehiculo = vehiculo;
}

string SolicitudAlquiler::toString() {
    stringstream ss;
    ss << "Solicitud ID: " << idSolicitud << endl;
    ss << "Fecha: " << fechaSolicitud << endl;
    ss << "Estado: " << estado << endl;
    return ss.str();
}
