#include "ArchivoPlantel.h"

ArchivoPlantel::ArchivoPlantel(string nombreArchivo) {
    this->nombreArchivo = nombreArchivo;
}

ArchivoPlantel::~ArchivoPlantel() {}

void ArchivoPlantel::guardar(ListaPlantel* lista) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar planteles." << endl;
        return;
    }

    NodoPlantel* actual = lista->getPpio();
    while (actual != nullptr) {
        Plantel* p = actual->getDato();
        archivo << p->getLetra() << ","<< p->getTipo() << ","<< p->getFilas() << ","<< p->getColumnas() << "," << p->getCapacidadMax() << endl;

        actual = actual->getSiguiente();
    }

    archivo.close();
}

void ArchivoPlantel::cargar(ListaPlantel* lista) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Archivo de planteles no encontrado, se creará uno nuevo al guardar." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        char letra;
        int tipo, filas, columnas, capacidad;

        char coma;
        ss >> letra >> coma >> tipo >> coma >> filas >> coma >> columnas >> coma >> capacidad;

        Plantel* p = new Plantel(letra, tipo, filas, columnas);
        NodoPlantel* nodo = new NodoPlantel(p);
        lista->insertarFinal(nodo);
    }

    archivo.close();
}
