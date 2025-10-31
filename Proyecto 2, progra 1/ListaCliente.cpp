#include "ListaCliente.h"

ListaCliente::ListaCliente() {
    ppio = NULL;
    actual = NULL;
}

ListaCliente::~ListaCliente() {
    NodoCliente* aux;
    while (ppio != NULL) {
        aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux;
    }
}

void ListaCliente::agregar(Cliente* c) {
    NodoCliente* nuevo = new NodoCliente(c);
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

Cliente* ListaCliente::buscar(string id) {
    actual = ppio;
    while (actual != NULL) {
        if (actual->getDato()->getId() == id) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return NULL;
}

string ListaCliente::toString() {
    stringstream s;
    actual = ppio;
    while (actual != NULL) {
        s << actual->getDato()->toString() << endl;
        actual = actual->getSiguiente();
    }
    return s.str();
}
