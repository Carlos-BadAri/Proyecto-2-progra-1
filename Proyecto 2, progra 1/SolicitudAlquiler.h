#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Declaraciones adelantadas para evitar dependencias circulares
class Cliente;
class Vehiculo;

class SolicitudAlquiler {
private:
    string idSolicitud;
    string fechaSolicitud;
    string estado; // "Pendiente", "Aprobada", "Rechazada"
    Cliente* cliente;
    Vehiculo* vehiculo;

public:
    SolicitudAlquiler();
    SolicitudAlquiler(string idSolicitud, string fechaSolicitud, string estado, Cliente* cliente, Vehiculo* vehiculo);
    ~SolicitudAlquiler();

    string getIdSolicitud();
    string getFechaSolicitud();
    string getEstado();
    Cliente* getCliente();
    Vehiculo* getVehiculo();

    void setIdSolicitud(string idSolicitud);
    void setFechaSolicitud(string fechaSolicitud);
    void setEstado(string estado);
    void setCliente(Cliente* cliente);
    void setVehiculo(Vehiculo* vehiculo);

    string toString();
};