#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    placa = "";
    marca = "";
    modelo = "";
    color = "";
    anio = 0;
    bitacora = nullptr;
    estado = "";
}

Vehiculo::Vehiculo(string placa, string marca, string modelo, string color, int anio, string estado) {
    this->placa = placa;
    this->marca = marca;
    this->modelo = modelo;
    this->color = color;
    this->anio = anio;
    this->estado = estado;
    bitacora = nullptr;
}

Vehiculo::~Vehiculo() {
    if (bitacora != nullptr) {
        delete bitacora;
        bitacora = nullptr;
    }
}

string Vehiculo::getPlaca() {
    return placa;
}
string Vehiculo::getMarca() {
    return marca;
}
string Vehiculo::getModelo() {
    return modelo; 
}
string Vehiculo::getColor() {
    return color; 
}
int Vehiculo::getAnio() {
    return anio; 
}
BitacoraEstado* Vehiculo::getBitacora() { 
    return bitacora; 
}
string Vehiculo::getEstado(){
    return estado;
}

void Vehiculo::setPlaca(string placa) { 
    this->placa = placa; 
}
void Vehiculo::setMarca(string marca) { 
    this->marca = marca;
}
void Vehiculo::setModelo(string modelo) { 
    this->modelo = modelo;
}
void Vehiculo::setColor(string color) {
    this->color = color;
}
void Vehiculo::setAnio(int anio) {
    this->anio = anio;
}
void Vehiculo::setBitacora(BitacoraEstado* bitacora) { 
    this->bitacora = bitacora; 
}
void Vehiculo::setEstado(string e) {
    estado = e;
}

string Vehiculo::toString() {
    stringstream ss;
    ss << "Placa: " << placa << endl;
    ss << "Marca: " << marca << endl;
    ss << "Modelo: " << modelo << endl;
    ss << "Color: " << color << endl;
    ss << "Año: " << anio << endl;
    return ss.str();
}

void Vehiculo::registrarCambioEstado(string anterior,string nuevo,string fecha,string idColab) {
    ifstream entrada("bitacora_vehiculos.txt");
    string contenido = "";
    string linea;

    while (getline(entrada, linea)) {
        contenido += linea + "\n";
    }
    entrada.close();

    contenido += placa + "|" + fecha + "|" + idColab + "|" + anterior + "->" + nuevo + "\n";

    ofstream salida("bitacora_vehiculos.txt");
    salida << contenido;
    salida.close();
}