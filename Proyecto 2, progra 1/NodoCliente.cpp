#include "NodoCliente.h"

NodoCliente::NodoCliente() {
    dato = NULL;
    siguiente = NULL;
}

NodoCliente::NodoCliente(Cliente* c) {
    dato = c;
    siguiente = NULL;
}

NodoCliente::~NodoCliente() {
    delete dato;
}

void NodoCliente::agregarDato(Cliente* c) {
    dato = c;
}

void NodoCliente::setSiguiente(NodoCliente* sig) {
    siguiente = sig;
}

Cliente* NodoCliente::getDato()
{
    return dato;
}

NodoCliente* NodoCliente::getSiguiente() {
    return siguiente;
}
