#include "ListaColaborador.h"

ListaColaborador::ListaColaborador() {
    primero = NULL;
    actual = NULL;
}

ListaColaborador::~ListaColaborador() {
    NodoColaborador* aux;
    while (primero != NULL) {
        aux = primero;
        primero = primero->getSiguiente();
        delete aux;
    }
}

void ListaColaborador::agregar(Colaborador* c) {
    NodoColaborador* nuevo = new NodoColaborador(c);
    if (primero == NULL) {
        primero = nuevo;
    }
    else {
        actual = primero;
        while (actual->getSiguiente() != NULL) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
    }
}

Colaborador* ListaColaborador::buscar(string id) {
    actual = primero;
    while (actual != NULL) {
        if (actual->getDato()->getId() == id) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return NULL;
}

string ListaColaborador::toString() {
    stringstream s;
    actual = primero;
    while (actual != NULL) {
        s << actual->getDato()->toString() << endl;
        actual = actual->getSiguiente();
    }
    return s.str();
}
