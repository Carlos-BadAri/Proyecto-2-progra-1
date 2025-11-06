#include "Plantel.h"

Plantel::Plantel() {
    letra = 'A';
    tipo = 1;
    filas = 0;
    columnas = 0;
    capacidadMax = 0;
    matriz = nullptr;
}

Plantel::Plantel(char letra, int tipo, int filas, int columnas) {
    this->letra = letra;
    this->tipo = tipo;
    this->filas = filas;
    this->columnas = columnas;
    this->capacidadMax = filas * columnas;

    matriz = new EspacioEstacionamiento * [filas];
    int contador = 1;
    for (int i = 0; i < filas; i++) {
        matriz[i] = new EspacioEstacionamiento[columnas];
        for (int j = 0; j < columnas; j++) {
            string codigo = string(1, letra) + (contador < 10 ? "0" : "") + to_string(contador);
            matriz[i][j].setCodigo(codigo);
            contador++;
        }
    }
}

Plantel::~Plantel() {
    if (matriz != nullptr) {
        for (int i = 0; i < filas; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
        matriz = nullptr;
    }
}

void Plantel::mostrarMatriz() {
    cout << "-- - Plantel " << letra << " -- - " << endl;;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "[" << matriz[i][j].getCodigo() << " " << matriz[i][j].getEstado()[0] << "] ";
        }
        cout << endl;
    }
}

void Plantel::recomendarEspacios() {
    cout << "Espacios recomendados en el Plantel " << letra << " (simulado):" << endl;;
    for (int i = 0; i < filas && i < 3; i++) {
        cout << matriz[i][0].getCodigo() << endl;
    }
}

char Plantel::getLetra() {
    return letra;
}
int Plantel::getTipo() { 
    return tipo; 
}
int Plantel::getFilas() {
    return filas; 
}
int Plantel::getColumnas() {
    return columnas; 
}
int Plantel::getCapacidadMax() {
    return capacidadMax;
}
EspacioEstacionamiento** Plantel::getMatriz() {
    return matriz;
}

void Plantel::setLetra(char letra) {
    this->letra = letra;
}
void Plantel::setTipo(int tipo) { 
    this->tipo = tipo; 
}
void Plantel::setFilas(int filas) { 
    this->filas = filas; 
}
void Plantel::setColumnas(int columnas) { 
    this->columnas = columnas; 
}

string Plantel::toString() {
    stringstream ss;
    ss << "Plantel " << letra << endl;
    ss << "Tipo: " << tipo << endl;
    ss << "Filas: " << filas << endl;
    ss << "Columnas: " << columnas << endl;
    ss << "Capacidad Max: " << capacidadMax << endl;
    return ss.str();
}
