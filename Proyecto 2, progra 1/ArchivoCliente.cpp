#include "ArchivoCliente.h"

ArchivoCliente::ArchivoCliente() {
}

ArchivoCliente::~ArchivoCliente() {
}

void ArchivoCliente::guardar(ListaCliente* lista) {
    ofstream archivo("clientes.txt");
    if (!archivo.is_open()) return;
   archivo << lista->toString(); 
    archivo.close();
}

void ArchivoCliente::cargar(ListaCliente* lista) {
    ifstream archivo("clientes.txt");
    if (!archivo.is_open()) return;

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, cedula, telefono;
        ss >> nombre >> cedula >> telefono;
        Cliente* c = new Cliente(nombre, cedula, telefono);
        lista->agregar(c);
    }

    archivo.close();
}
