#include "ArchivoBitacora.h"

ArchivoBitacora::ArchivoBitacora(string nombreArchivo) {
    this->nombreArchivo = nombreArchivo;
}

ArchivoBitacora::~ArchivoBitacora() {}

void ArchivoBitacora::guardar(ListaBitacora* lista) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar." << endl;
        return;
    }

    archivo << lista->toString();
    archivo.close();
}

void ArchivoBitacora::cargar(ListaBitacora* lista) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "Archivo no encontrado, se creará uno nuevo al guardar." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string fecha, entrada, salida, desc;

        getline(ss, fecha, ',');
        getline(ss, entrada, ',');
        getline(ss, salida, ',');
        getline(ss, desc);

        BitacoraEstado* b = new BitacoraEstado(fecha, entrada, salida, desc);
        lista->agregar(b);
    }

    archivo.close();
}
