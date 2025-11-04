#include "ListaSolicitud.h"

ListaSolicitud::ListaSolicitud() {
    ppio = NULL;
    actual = NULL;
}

ListaSolicitud::~ListaSolicitud() {
    while (ppio != NULL) {
        NodoSolicitud* aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux;
    }
}

void ListaSolicitud::insertarInicio(NodoSolicitud* n) {
    if (ppio != NULL) n->setSiguiente(ppio);
    ppio = n;
}

void ListaSolicitud::insertarFinal(NodoSolicitud* n) {
    if (ppio == NULL) {
        ppio = n;
    }
    else {
        NodoSolicitud* aux = ppio;
        while (aux->getSiguiente() != NULL) aux = aux->getSiguiente();
        aux->setSiguiente(n);
    }
}

bool ListaSolicitud::insertarPosicion(NodoSolicitud* n, int pos) {
    if (pos <= 1) {
        insertarInicio(n);
        return true;
    }

    NodoSolicitud* aux = ppio;
    for (int i = 1; i < pos - 1 && aux != NULL; i++) {
        aux = aux->getSiguiente();
    }

    if (aux == NULL) return false;
    n->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(n);
    return true;
}

void ListaSolicitud::eliminarInicio() {
    if (ppio != NULL) {
        NodoSolicitud* aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux;
    }
}

void ListaSolicitud::eliminarFinal() {
    if (ppio == NULL) return;
    if (ppio->getSiguiente() == NULL) {
        delete ppio;
        ppio = NULL;
        return;
    }

    NodoSolicitud* aux = ppio;
    while (aux->getSiguiente()->getSiguiente() != NULL)
        aux = aux->getSiguiente();
    delete aux->getSiguiente();
    aux->setSiguiente(NULL);
}

bool ListaSolicitud::eliminarPosicion(int pos) {
    if (pos <= 1) {
        eliminarInicio();
        return true;
    }

    NodoSolicitud* aux = ppio;
    for (int i = 1; i < pos - 1 && aux != NULL; i++) {
        aux = aux->getSiguiente();
    }

    if (aux == NULL || aux->getSiguiente() == NULL) return false;

    NodoSolicitud* temp = aux->getSiguiente();
    aux->setSiguiente(temp->getSiguiente());
    delete temp;
    return true;
}

string ListaSolicitud::toString() {
    stringstream s;
    NodoSolicitud* aux = ppio;
    while (aux != NULL) {
        s << aux->getDato()->toString() << endl;
        aux = aux->getSiguiente();
    }
    return s.str();
}
