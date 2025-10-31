#include "BitacoraEstado.h"

BitacoraEstado::BitacoraEstado() {
    fecha = "";
    horaEntrada = "";
    horaSalida = "";
    descripcion = "";
}

BitacoraEstado::BitacoraEstado(string fecha, string horaEntrada, string horaSalida, string descripcion) {
    this->fecha = fecha;
    this->horaEntrada = horaEntrada;
    this->horaSalida = horaSalida;
    this->descripcion = descripcion;
}

BitacoraEstado::~BitacoraEstado() {}

string BitacoraEstado::getFecha() {
    return fecha;
}
string BitacoraEstado::getHoraEntrada() {
    return horaEntrada; 
}
string BitacoraEstado::getHoraSalida() {
    return horaSalida; 
}
string BitacoraEstado::getDescripcion() {
    return descripcion;
}

void BitacoraEstado::setFecha(string fecha) { 
    this->fecha = fecha; 
}
void BitacoraEstado::setHoraEntrada(string horaEntrada) {
    this->horaEntrada = horaEntrada; 
}
void BitacoraEstado::setHoraSalida(string horaSalida) { 
    this->horaSalida = horaSalida; 
}
void BitacoraEstado::setDescripcion(string descripcion) { 
    this->descripcion = descripcion; 
}

string BitacoraEstado::toString() {
    stringstream ss;
    ss << "Fecha: " << fecha
        << " | Entrada: " << horaEntrada
        << " | Salida: " << horaSalida
        << " | Descripción: " << descripcion;
    return ss.str();
}
