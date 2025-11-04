#include "NodoSucursal.h"

NodoSucursal::NodoSucursal() {
    dato = NULL;
    siguiente = NULL;
}

NodoSucursal::NodoSucursal(Sucursal* s) {
    dato = s;
    siguiente = NULL;
}

NodoSucursal::~NodoSucursal() {
    delete dato;
}

void NodoSucursal::agregarDato(Sucursal* s) {
    dato = s;
}

void NodoSucursal::setSiguiente(NodoSucursal* sig) {
    siguiente = sig;
}

NodoSucursal* NodoSucursal::getSiguiente() {
    return siguiente;
}

Sucursal* NodoSucursal::getDato() {
    return dato;
}

