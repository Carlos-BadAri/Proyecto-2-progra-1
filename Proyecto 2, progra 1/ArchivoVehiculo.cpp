#include "ArchivoVehiculo.h"

ArchivoVehiculo::ArchivoVehiculo() {}

ArchivoVehiculo::~ArchivoVehiculo() {}

void ArchivoVehiculo::guardar(ListaVehiculo* lista) {
    ofstream archivo("vehiculos.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar." << endl;
        return;
    }

    archivo << lista->toString();
    archivo.close();
}

void ArchivoVehiculo::cargar(ListaVehiculo* lista) {
    ifstream archivo("vehiculos.txt");
    if (!archivo.is_open()) {
        cout << "Archivo no encontrado, se creará uno nuevo al guardar." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string placa, marca, modelo, color, estado;
        int anio;

        ss >> placa >> marca >> modelo >> color >> anio >> estado;

        if (!ss.fail()) {//Esto lo que hace es que solo crea el objeto Vehiculo si todo se leyó correctamente
            Vehiculo* v = new Vehiculo(placa, marca, modelo, color, anio, estado);
            NodoVehiculo* nodo = new NodoVehiculo(v);
            lista->insertarFinal(nodo);
        }
    }

    archivo.close();
}
