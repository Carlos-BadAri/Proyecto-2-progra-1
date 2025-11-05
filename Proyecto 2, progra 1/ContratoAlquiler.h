#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Declaraciones adelantadas para evitar dependencias
class Cliente;
class Vehiculo;
class Colaborador;
class SolicitudAlquiler;

class ContratoAlquiler {
private:
    string idContrato;
    string fechaInicio;
    string fechaFin;
    double montoTotal;
    Cliente* cliente;
    Vehiculo* vehiculo;
    Colaborador* colaborador;
    SolicitudAlquiler* solicitud;

public:
    ContratoAlquiler();
    ContratoAlquiler(string idContrato, string fechaInicio, string fechaFin, double montoTotal,
        Cliente* cliente, Vehiculo* vehiculo, Colaborador* colaborador);
    ~ContratoAlquiler();

    string getIdContrato();
    string getFechaInicio();
    string getFechaFin();
    double getMontoTotal();
    Cliente* getCliente();
    Vehiculo* getVehiculo();
    Colaborador* getColaborador();
    SolicitudAlquiler* getSolicitud();

    void setIdContrato(string);
    void setFechaInicio(string);
    void setFechaFin(string);
    void setMontoTotal(double);
    void setCliente(Cliente*);
    void setVehiculo(Vehiculo*);
    void setColaborador(Colaborador*);
    void setSolicitud(SolicitudAlquiler*);

    string toString();
};
