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
    NodoCliente* aux = ppio;
    while (aux != NULL) {
        s << aux->getDato()->toString() << endl;
        aux = aux->getSiguiente();
    }
    return s.str();
}

NodoCliente* ListaCliente::getPpio() {
    return ppio;
}
bool ListaCliente::eliminar(string id) {
    if (ppio == NULL) return false;

    NodoCliente* ant = NULL;
    NodoCliente* act = ppio;

    while (act != NULL && act->getDato()->getId() != id) {
        ant = act;
        act = act->getSiguiente();
    }

    if (act == NULL) return false;

    if (ant == NULL) ppio = act->getSiguiente();
    else ant->setSiguiente(act->getSiguiente());

    delete act->getDato();
    delete act;

    return true;
}
