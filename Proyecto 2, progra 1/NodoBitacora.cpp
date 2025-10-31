#include "NodoBitacora.h"

NodoBitacora::NodoBitacora() {
    dato = NULL;
    siguiente = NULL;
}

NodoBitacora::NodoBitacora(BitacoraEstado* b) {
    dato = b;
    siguiente = NULL;
}

NodoBitacora::~NodoBitacora() {
    delete dato;
}

void NodoBitacora::agregarDato(BitacoraEstado* b) {
    dato = b;
}

void NodoBitacora::setSiguiente(NodoBitacora* sig) {
    siguiente = sig;
}

NodoBitacora* NodoBitacora::getSiguiente() {
    return siguiente;
}

BitacoraEstado* NodoBitacora::getDato() {
    return dato;
}
