#include "ContratoAlquiler.h"

ContratoAlquiler::ContratoAlquiler() {
    idContrato = "";
    fechaInicio = "";
    fechaFin = "";
    montoTotal = 0.0;
    cliente = nullptr;
    vehiculo = nullptr;
    colaborador = nullptr;
}

ContratoAlquiler::ContratoAlquiler(string idContrato, string fechaInicio, string fechaFin, double montoTotal, Cliente* cliente, Vehiculo* vehiculo, Colaborador* colaborador) {
    this->idContrato = idContrato;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
    this->montoTotal = montoTotal;
    this->cliente = cliente;
    this->vehiculo = vehiculo;
    this->colaborador = colaborador;
}

ContratoAlquiler::~ContratoAlquiler() {
    // No se van a eliminar cliente,vehiculo ni colborador porque no son propiedad directa del contrato
}

string ContratoAlquiler::getIdContrato() {
    return idContrato;
}
string ContratoAlquiler::getFechaInicio() {
    return fechaInicio;
}
string ContratoAlquiler::getFechaFin() {
    return fechaFin; 
}
double ContratoAlquiler::getMontoTotal() {
    return montoTotal; 
}
Cliente* ContratoAlquiler::getCliente() {
    return cliente;
}
Vehiculo* ContratoAlquiler::getVehiculo() {
    return vehiculo; 
}
Colaborador* ContratoAlquiler::getColaborador() { 
    return colaborador; 
}

void ContratoAlquiler::setIdContrato(string idContrato) { 
    this->idContrato = idContrato;
}
void ContratoAlquiler::setFechaInicio(string fechaInicio) { 
    this->fechaInicio = fechaInicio;
}
void ContratoAlquiler::setFechaFin(string fechaFin) { 
    this->fechaFin = fechaFin; 
}
void ContratoAlquiler::setMontoTotal(double montoTotal) {
    this->montoTotal = montoTotal; 
}
void ContratoAlquiler::setCliente(Cliente* cliente) {
    this->cliente = cliente; 
}
void ContratoAlquiler::setVehiculo(Vehiculo* vehiculo) {
    this->vehiculo = vehiculo;
}
void ContratoAlquiler::setColaborador(Colaborador* colaborador) {
    this->colaborador = colaborador; 
}

string ContratoAlquiler::toString() {
    stringstream ss;
    ss << "Contrato de Alquiler" << endl;
    ss << "ID Contrato: " << idContrato << endl;
    ss << "Fecha Inicio: " << fechaInicio << endl;
    ss << "Fecha Fin: " << fechaFin << endl;
    ss << "Monto Total: " << montoTotal << endl;
    ss << "Cliente: " << (cliente ? "[Asignado]" : "NULL") << endl;
    ss << "Vehiculo: " << (vehiculo ? "[Asignado]" : "NULL") << endl;
    ss << "Colaborador: " << (colaborador ? "[Asignado]" : "NULL") << endl;
    return ss.str();
}
void ContratoAlquiler::setSolicitud(SolicitudAlquiler* solicitud) {
    this->solicitud = solicitud;
}
SolicitudAlquiler* ContratoAlquiler::getSolicitud() {
    return solicitud;
}