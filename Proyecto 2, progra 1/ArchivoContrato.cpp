#include "ArchivoContrato.h"
#include "Cliente.h"
#include "Vehiculo.h"
#include "SolicitudAlquiler.h"
#include <iostream>

ArchivoContrato::ArchivoContrato(string nombreArchivo) {
    this->nombreArchivo = nombreArchivo;
}

ArchivoContrato::~ArchivoContrato() {}

void ArchivoContrato::guardar(ListaContrato* lista) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar contratos." << endl;
        return;
    }

    NodoContrato* actual = lista->getPpio();

    while (actual != nullptr) {
        ContratoAlquiler* c = actual->getDato();

        archivo << c->getIdContrato() << ","
            << c->getFechaInicio() << ","
            << c->getFechaFin() << ","
            << c->getMontoTotal() << ",";

        if (c->getCliente() != nullptr)
            archivo << c->getCliente()->getId() << ",";
        else
            archivo << "NULL,";

        if (c->getVehiculo() != nullptr)
            archivo << c->getVehiculo()->getPlaca() << ",";
        else
            archivo << "NULL,";

        if (c->getSolicitud() != nullptr)
            archivo << c->getSolicitud()->getIdSolicitud();
        else
            archivo << "NULL";

        archivo << endl;
        actual = actual->getSiguiente();
    }

    archivo.close();
}

void ArchivoContrato::cargar(ListaContrato* lista) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Archivo de contratos no encontrado, se creará uno nuevo al guardar." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string id, fechaInicio, fechaFin, montoStr;
        string idCliente, placaVehiculo, idSolicitud;
        double monto = 0.0;

        getline(ss, id, ',');
        getline(ss, fechaInicio, ',');
        getline(ss, fechaFin, ',');
        getline(ss, montoStr, ',');
        getline(ss, idCliente, ',');
        getline(ss, placaVehiculo, ',');
        getline(ss, idSolicitud, ',');

        if (!montoStr.empty())
            monto = stod(montoStr);

        ContratoAlquiler* c = new ContratoAlquiler(id, fechaInicio, fechaFin, monto, nullptr, nullptr, nullptr);
        NodoContrato* nodo = new NodoContrato(c);
        lista->insertarFinal(nodo);
    }

    archivo.close();
}
