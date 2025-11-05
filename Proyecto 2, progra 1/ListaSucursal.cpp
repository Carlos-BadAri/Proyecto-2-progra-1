#include "ListaSucursal.h"

ListaSucursal::ListaSucursal() {
    ppio = NULL;
    actual = NULL;
}

ListaSucursal::~ListaSucursal() {
    while (ppio != NULL) {
        NodoSucursal* aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux;
    }
}

void ListaSucursal::insertarInicio(NodoSucursal* n) {
    if (ppio != NULL) {
        n->setSiguiente(ppio);
    }
    ppio = n;
}

void ListaSucursal::insertarFinal(NodoSucursal* n) {
    if (ppio == NULL) {
        ppio = n;
    }
    else {
        NodoSucursal* aux = ppio;
        while (aux->getSiguiente() != NULL) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(n);
    }
}

bool ListaSucursal::insertarPosicion(NodoSucursal* n, int pos) {
    if (pos <= 1) {
        insertarInicio(n);
        return true;
    }

    NodoSucursal* aux = ppio;
    for (int i = 1; i < pos - 1 && aux != NULL; i++) {
        aux = aux->getSiguiente();
    }

    if (aux == NULL) return false;

    n->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(n);
    return true;
}

void ListaSucursal::eliminarInicio() {
    if (ppio != NULL) {
        NodoSucursal* aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux;
    }
}

void ListaSucursal::eliminarFinal() {
    if (ppio == NULL) return;

    if (ppio->getSiguiente() == NULL) {
        delete ppio;
        ppio = NULL;
        return;
    }

    NodoSucursal* aux = ppio;
    while (aux->getSiguiente()->getSiguiente() != NULL) {
        aux = aux->getSiguiente();
    }
    delete aux->getSiguiente();
    aux->setSiguiente(NULL);
}

bool ListaSucursal::eliminarPosicion(int pos) {
    if (pos <= 1) {
        eliminarInicio();
        return true;
    }

    NodoSucursal* aux = ppio;
    for (int i = 1; i < pos - 1 && aux != NULL; i++) {
        aux = aux->getSiguiente();
    }

    if (aux == NULL || aux->getSiguiente() == NULL) return false;

    NodoSucursal* temp = aux->getSiguiente();
    aux->setSiguiente(temp->getSiguiente());
    delete temp;
    return true;
}

string ListaSucursal::toString() {
    stringstream s;
    NodoSucursal* aux = ppio;
    while (aux != NULL) {
        s << aux->getDato()->toString() << endl;
        aux = aux->getSiguiente();
    }
    return s.str();
}
NodoSucursal* ListaSucursal::getPpio() {
    return ppio;
}

Sucursal* ListaSucursal::buscar(string codigo) {
    NodoSucursal* aux = ppio;
    while (aux != nullptr) {
        if (aux->getDato()->getCodigo() == codigo) {
            return aux->getDato();
        }
        aux = aux->getSiguiente();
    }
    return nullptr;
}

bool ListaSucursal::Eliminar(const string& codigo){
    if (ppio == NULL) return false;
    NodoSucursal* ant = NULL;
    NodoSucursal* act = ppio;

    while (act != NULL && act->getDato()->getCodigo() != codigo) {
        ant = act;
        act = act->getSiguiente();
    }
    if (act == NULL)
        return false;
    if (ant == NULL) {
        ppio = act->getSiguiente();
    }
    else {
        ant->setSiguiente(act->getSiguiente());
    }
    delete act->getDato();
    delete act;

    return true;
}