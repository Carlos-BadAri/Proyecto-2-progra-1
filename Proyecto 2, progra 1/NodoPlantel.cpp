#include "NodoPlantel.h"

NodoPlantel::NodoPlantel() {
    dato = NULL;
    siguiente = NULL;
}

NodoPlantel::NodoPlantel(Plantel* p) {
    dato = p;
    siguiente = NULL;
}

NodoPlantel::~NodoPlantel() {
    delete dato;
}

void NodoPlantel::agregarDato(Plantel* p) {
    dato = p;
}

void NodoPlantel::setSiguiente(NodoPlantel* sig) {
    siguiente = sig;
}

NodoPlantel* NodoPlantel::getSiguiente() {
    return siguiente;
}
Plantel* NodoPlantel::getDato() {
    return dato;
}