#include "NodoSolicitud.h"

NodoSolicitud::NodoSolicitud() {
    dato = NULL;
    siguiente = NULL;
}

NodoSolicitud::NodoSolicitud(SolicitudAlquiler* s) {
    dato = s;
    siguiente = NULL;
}

NodoSolicitud::~NodoSolicitud() {
    delete dato;
}

void NodoSolicitud::agregarDato(SolicitudAlquiler* s) {
    dato = s;
}

void NodoSolicitud::setSiguiente(NodoSolicitud* sig) {
    siguiente = sig;
}

NodoSolicitud* NodoSolicitud::getSiguiente() {
    return siguiente;
}
