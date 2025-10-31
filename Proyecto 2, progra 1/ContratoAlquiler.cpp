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

ContratoAlquiler::ContratoAlquiler(string idContrato, string fechaInicio, string fechaFin, double montoTotal,
    Cliente* cliente, Vehiculo* vehiculo, Colaborador* colaborador) {
    this->idContrato = idContrato;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
    this->montoTotal = montoTotal;
    this->cliente = cliente;
    this->vehiculo = vehiculo;
    this->colaborador = colaborador;
}

ContratoAlquiler::~ContratoAlquiler() {
    // No destruye cliente, vehiculo ni colaborador, ya que no son propiedad del contrato.
}

string ContratoAlquiler::getIdContrato() { return idContrato; }
string ContratoAlquiler::getFechaInicio() { return fechaInicio; }
string ContratoAlquiler::getFechaFin() { return fechaFin; }
double ContratoAlquiler::getMontoTotal() { return montoTotal; }
Cliente* ContratoAlquiler::getCliente() { return cliente; }
Vehiculo* ContratoAlquiler::getVehiculo() { return vehiculo; }
Colaborador* ContratoAlquiler::getColaborador() { return colaborador; }

void ContratoAlquiler::setIdContrato(string idContrato) { this->idContrato = idContrato; }
void ContratoAlquiler::setFechaInicio(string fechaInicio) { this->fechaInicio = fechaInicio; }
void ContratoAlquiler::setFechaFin(string fechaFin) { this->fechaFin = fechaFin; }
void ContratoAlquiler::setMontoTotal(double montoTotal) { this->montoTotal = montoTotal; }
void ContratoAlquiler::setCliente(Cliente* cliente) { this->cliente = cliente; }
void ContratoAlquiler::setVehiculo(Vehiculo* vehiculo) { this->vehiculo = vehiculo; }
void ContratoAlquiler::setColaborador(Colaborador* colaborador) { this->colaborador = colaborador; }

void ContratoAlquiler::mostrar() {
    stringstream ss;
    ss << "Contrato ID: " << idContrato
        << " | Fecha inicio: " << fechaInicio
        << " | Fecha fin: " << fechaFin
        << " | Monto total: " << montoTotal;
    cout << ss.str() << endl;
}
