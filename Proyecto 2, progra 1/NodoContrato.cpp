#include "NodoContrato.h"

NodoContrato::NodoContrato() {
    dato = NULL;
    siguiente = NULL;
}

NodoContrato::NodoContrato(ContratoAlquiler* c) {
    dato = c;
    siguiente = NULL;
}

NodoContrato::~NodoContrato() {
    delete dato;
}

void NodoContrato::agregarDato(ContratoAlquiler* c) {
    dato = c;
}

void NodoContrato::setSiguiente(NodoContrato* sig) {
    siguiente = sig;
}

NodoContrato* NodoContrato::getSiguiente() {
    return siguiente;
}

ContratoAlquiler* NodoContrato::getDato() {
    return dato;
}
