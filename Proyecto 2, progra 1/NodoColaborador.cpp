#include "NodoColaborador.h"

NodoColaborador::NodoColaborador() {
    dato = NULL;
    siguiente = NULL;
}

NodoColaborador::NodoColaborador(Colaborador* c) {
    dato = c;
    siguiente = NULL;
}

NodoColaborador::~NodoColaborador() {
    delete dato;
}

void NodoColaborador::agregarDato(Colaborador* c) {
    dato = c;
}

void NodoColaborador::setSiguiente(NodoColaborador* sig) {
    siguiente = sig;
}

NodoColaborador* NodoColaborador::getSiguiente() {
    return siguiente;
}
