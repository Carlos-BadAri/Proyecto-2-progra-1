#include "ListaBitacora.h"

ListaBitacora::ListaBitacora() {
    ppio = NULL;
    actual = NULL;
}

ListaBitacora::~ListaBitacora() {
    NodoBitacora* aux;
    while (ppio != NULL) {
        aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux;
    }
}

void ListaBitacora::agregar(BitacoraEstado* b) {
    NodoBitacora* nuevo = new NodoBitacora(b);
    if (ppio == NULL) {
        ppio = nuevo;
    }
    else {
        actual = ppio;
        while (actual->getSiguiente() != NULL) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
    }
}

string ListaBitacora::toString() {
    stringstream s;
    actual = ppio;
    while (actual != NULL) {
        s << actual->getDato()->toString() << endl;
        actual = actual->getSiguiente();
    }
    return s.str();
}
