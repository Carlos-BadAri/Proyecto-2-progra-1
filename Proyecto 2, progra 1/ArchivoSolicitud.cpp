#include "ArchivoSolicitud.h"

#include <iostream>

ArchivoSolicitud::ArchivoSolicitud(string nombreArchivo) {
    this->nombreArchivo = nombreArchivo;
}

ArchivoSolicitud::~ArchivoSolicitud() {}

void ArchivoSolicitud::guardar(ListaSolicitud* lista) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar solicitudes." << endl;
        return;
    }

    NodoSolicitud* actual = nullptr;
    actual = new NodoSolicitud();
    actual = lista->getPpio();
    while (actual != nullptr) {
        SolicitudAlquiler* s = actual->getDato();
       
        archivo << s->getIdSolicitud() << ","
            << s->getFechaSolicitud() << ","
            << s->getEstado() << ",";

        if (s->getCliente() != nullptr)
            archivo << s->getCliente()->getId() << ",";
        else
            archivo << "NULL,";

        if (s->getVehiculo() != nullptr)
            archivo << s->getVehiculo()->getPlaca();
        else
            archivo << "NULL";

        archivo << endl;
        actual = actual->getSiguiente();
    }

    archivo.close();
}

void ArchivoSolicitud::cargar(ListaSolicitud* lista) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Archivo de solicitudes no encontrado, se creará uno nuevo al guardar." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string id, fecha, estado, idCliente, placaVehiculo;

        getline(ss, id, ',');
        getline(ss, fecha, ',');
        getline(ss, estado, ',');
        getline(ss, idCliente, ',');
        getline(ss, placaVehiculo, ',');

        SolicitudAlquiler* s = new SolicitudAlquiler(id, fecha, estado, nullptr, nullptr);
        NodoSolicitud* nodo = new NodoSolicitud(s);
        lista->insertarFinal(nodo);
    }

    archivo.close();
}
