#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Declaraciones adelantadas para evitar dependencias
class Cliente;
class Vehiculo;
class Colaborador;

class ContratoAlquiler {
private:
    string idContrato;
    string fechaInicio;
    string fechaFin;
    double montoTotal;
    Cliente* cliente;
    Vehiculo* vehiculo;
    Colaborador* colaborador; // quien gestionó el contrato

public:
    ContratoAlquiler();
    ContratoAlquiler(string idContrato, string fechaInicio, string fechaFin, double montoTotal,
        Cliente* cliente, Vehiculo* vehiculo, Colaborador* colaborador);
    ~ContratoAlquiler();

    // Getters
    string getIdContrato();
    string getFechaInicio();
    string getFechaFin();
    double getMontoTotal();
    Cliente* getCliente();
    Vehiculo* getVehiculo();
    Colaborador* getColaborador();

    // Setters
    void setIdContrato(string idContrato);
    void setFechaInicio(string fechaInicio);
    void setFechaFin(string fechaFin);
    void setMontoTotal(double montoTotal);
    void setCliente(Cliente* cliente);
    void setVehiculo(Vehiculo* vehiculo);
    void setColaborador(Colaborador* colaborador);

    string toString();
};
