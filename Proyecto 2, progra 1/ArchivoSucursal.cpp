#include "ArchivoSucursal.h"

ArchivoSucursal::ArchivoSucursal(string nombreArchivo) {
    this->nombreArchivo = nombreArchivo;
}

ArchivoSucursal::~ArchivoSucursal() {}

void ArchivoSucursal::guardar(ListaSucursal* lista) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar." << endl;
        return;
    }

    NodoSucursal* actual = lista->getPpio();
    while (actual != nullptr) {
        Sucursal* s = actual->getDato();
        archivo << s->getCodigo() << ","
            << s->getNombre() << ","
            << s->getDireccion() << ","
            << s->getPais() << endl;
        actual = actual->getSiguiente();
    }

    archivo.close();
}

void ArchivoSucursal::cargar(ListaSucursal* lista) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Archivo no encontrado, se creará uno nuevo al guardar." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string codigo, nombre, direccion, pais;

        getline(ss, codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, direccion, ',');
        getline(ss, pais, ',');

        if (!codigo.empty()) {
            Sucursal* s = new Sucursal(codigo, nombre, direccion, pais);
            NodoSucursal* nodo = new NodoSucursal(s);
            lista->insertarFinal(nodo);
        }
    }

    archivo.close();
}
