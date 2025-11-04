#include "ListaContrato.h"

ListaContrato::ListaContrato() {
    ppio = NULL;
}

ListaContrato::~ListaContrato() {
    while (ppio != NULL) {
        NodoContrato* aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux;
    }
}

void ListaContrato::insertarInicio(NodoContrato* n) {
    if (ppio != NULL) n->setSiguiente(ppio);
    ppio = n;
}

void ListaContrato::insertarFinal(NodoContrato* n) {
    if (ppio == NULL) {
        ppio = n;
    }
    else {
        NodoContrato* aux = ppio;
        while (aux->getSiguiente() != NULL)
            aux = aux->getSiguiente();
        aux->setSiguiente(n);
    }
}

bool ListaContrato::insertarPosicion(NodoContrato* n, int pos) {
    if (pos <= 1) {
        insertarInicio(n);
        return true;
    }

    NodoContrato* aux = ppio;
    for (int i = 1; i < pos - 1 && aux != NULL; i++) {
        aux = aux->getSiguiente();
    }

    if (aux == NULL) return false;
    n->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(n);
    return true;
}

void ListaContrato::eliminarInicio() {
    if (ppio != NULL) {
        NodoContrato* aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux;
    }
}

void ListaContrato::eliminarFinal() {
    if (ppio == NULL) return;
    if (ppio->getSiguiente() == NULL) {
        delete ppio;
        ppio = NULL;
        return;
    }

    NodoContrato* aux = ppio;
    while (aux->getSiguiente()->getSiguiente() != NULL)
        aux = aux->getSiguiente();
    delete aux->getSiguiente();
    aux->setSiguiente(NULL);
}

bool ListaContrato::eliminarPosicion(int pos) {
    if (pos <= 1) {
        eliminarInicio();
        return true;
    }

    NodoContrato* aux = ppio;
    for (int i = 1; i < pos - 1 && aux != NULL; i++) {
        aux = aux->getSiguiente();
    }

    if (aux == NULL || aux->getSiguiente() == NULL) return false;

    NodoContrato* temp = aux->getSiguiente();
    aux->setSiguiente(temp->getSiguiente());
    delete temp;
    return true;
}

string ListaContrato::toString() {
    stringstream s;
    NodoContrato* aux = ppio;
    while (aux != NULL) {
        s << aux->getDato()->toString() << endl;
        aux = aux->getSiguiente();
    }
    return s.str();
}
