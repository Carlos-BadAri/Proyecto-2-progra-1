#include "ListaColaborador.h"

ListaColaborador::ListaColaborador() {
    ppio = NULL;
    actual = NULL;
}

ListaColaborador::~ListaColaborador() {
    NodoColaborador* aux;
    while (ppio != NULL) {
        aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux;
    }
}

void ListaColaborador::agregar(Colaborador* c) {
    NodoColaborador* nuevo = new NodoColaborador(c);
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

Colaborador* ListaColaborador::buscar(string id) {
    actual = ppio;
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
    NodoColaborador* aux = ppio;
    while (aux != NULL) {
        s << aux->getDato()->toString() << endl;
        aux = aux->getSiguiente();
    }
    return s.str();
}
