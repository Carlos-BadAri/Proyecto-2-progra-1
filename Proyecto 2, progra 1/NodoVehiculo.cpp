#include "NodoVehiculo.h"

NodoVehiculo::NodoVehiculo() {
    dato = NULL;
    siguiente = NULL;
}

NodoVehiculo::NodoVehiculo(Vehiculo* v) {
    dato = v;
    siguiente = NULL;
}

NodoVehiculo::~NodoVehiculo() {
    delete dato;
}

void NodoVehiculo::agregarDato(Vehiculo* v) {
    dato = v;
}

void NodoVehiculo::setSiguiente(NodoVehiculo* sig) {
    siguiente = sig;
}

NodoVehiculo* NodoVehiculo::getSiguiente() {
    return siguiente;
}
