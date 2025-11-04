#include "ArchivoColaborador.h"

ArchivoColaborador::ArchivoColaborador(string nombreArchivo) {
    this->nombreArchivo = nombreArchivo;
}

ArchivoColaborador::~ArchivoColaborador() {}

void ArchivoColaborador::guardar(ListaColaborador* lista) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar colaboradores." << endl;
        return;
    }

    string contenido = lista->toString();
    archivo << contenido;

    archivo.close();
}

void ArchivoColaborador::cargar(ListaColaborador* lista) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Archivo de colaboradores no encontrado, se creará uno nuevo al guardar." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (linea.find("[Colaborador]") != string::npos) {
            string id, nombre, puesto, sucursal;
            getline(archivo, linea); id = linea.substr(linea.find(":") + 2);
            getline(archivo, linea); nombre = linea.substr(linea.find(":") + 2);
            getline(archivo, linea); puesto = linea.substr(linea.find(":") + 2);
            getline(archivo, linea); sucursal = linea.substr(linea.find(":") + 2);

            Colaborador* c = new Colaborador(id, nombre, puesto, sucursal);
            lista->agregar(c);
        }
    }

    archivo.close();
}
