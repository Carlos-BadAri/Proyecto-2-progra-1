#include "ListaSucursal.h"
#include <iostream>

ListaSucursal::ListaSucursal() {
    ppio = NULL;
    actual = NULL;
}

ListaSucursal::~ListaSucursal() {
    while (ppio != NULL) {
        NodoSucursal* aux = ppio;
        ppio = ppio->getSiguiente();
        // Si tú eres dueño de Sucursal, descomenta la línea de abajo:
        // if (aux->getDato() != NULL) delete aux->getDato();
        delete aux;
    }
}

void ListaSucursal::insertarInicio(NodoSucursal* n) {
    if (n == NULL || n->getDato() == NULL) return;   // defensa
    n->setSiguiente(ppio);
    ppio = n;
}

void ListaSucursal::insertarFinal(NodoSucursal* n) {
    if (n == NULL || n->getDato() == NULL) return;   // defensa
    n->setSiguiente(NULL);                           // por si venía sucio
    if (ppio == NULL) { ppio = n; return; }
    NodoSucursal* aux = ppio;
    while (aux->getSiguiente() != NULL) aux = aux->getSiguiente();
    aux->setSiguiente(n);
}

bool ListaSucursal::insertarPosicion(NodoSucursal* n, int pos) {
    if (n == NULL || n->getDato() == NULL) return false;
    if (pos <= 1) { insertarInicio(n); return true; }

    NodoSucursal* aux = ppio;
    for (int i = 1; i < pos - 1 && aux != NULL; i++) aux = aux->getSiguiente();
    if (aux == NULL) return false;

    n->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(n);
    return true;
}

void ListaSucursal::eliminarInicio() {
    if (ppio != NULL) {
        NodoSucursal* aux = ppio;
        ppio = ppio->getSiguiente();
        // if (aux->getDato() != NULL) delete aux->getDato();
        delete aux;
    }
}

void ListaSucursal::eliminarFinal() {
    if (ppio == NULL) return;

    if (ppio->getSiguiente() == NULL) {
        // if (ppio->getDato() != NULL) delete ppio->getDato();
        delete ppio;
        ppio = NULL;
        return;
    }

    NodoSucursal* aux = ppio;
    while (aux->getSiguiente()->getSiguiente() != NULL)
        aux = aux->getSiguiente();

    NodoSucursal* ultimo = aux->getSiguiente();
    aux->setSiguiente(NULL);
    // if (ultimo->getDato() != NULL) delete ultimo->getDato();
    delete ultimo;
}

bool ListaSucursal::eliminarPosicion(int pos) {
    if (pos <= 1) { eliminarInicio(); return true; }

    NodoSucursal* aux = ppio;
    for (int i = 1; i < pos - 1 && aux != NULL; i++) aux = aux->getSiguiente();

    if (aux == NULL || aux->getSiguiente() == NULL) return false;

    NodoSucursal* temp = aux->getSiguiente();
    aux->setSiguiente(temp->getSiguiente());
    // if (temp->getDato() != NULL) delete temp->getDato();
    delete temp;
    return true;
}

string ListaSucursal::toString() {
    stringstream s;
    NodoSucursal* aux = ppio;
    while (aux != NULL) {
        if (aux->getDato() != NULL) s << aux->getDato()->toString() << endl;
        else                        s << "[Sucursal nula]" << endl; // defensa
        aux = aux->getSiguiente();
    }
    return s.str();
}

NodoSucursal* ListaSucursal::getPpio() {
    return ppio; // evita imprimir aquí (puede romper recorridos que esperan solo puntero)
}

Sucursal* ListaSucursal::buscar(string codigo) {
    for (NodoSucursal* aux = ppio; aux != NULL; aux = aux->getSiguiente()) {
        Sucursal* s = aux->getDato();
        if (s != NULL && s->getCodigo() == codigo) return s;
    }
    return NULL;
}

bool ListaSucursal::Eliminar(const string& codigo) {
    NodoSucursal* ant = NULL;
    NodoSucursal* act = ppio;

    while (act != NULL) {
        Sucursal* s = act->getDato();
        if (s != NULL && s->getCodigo() == codigo) break;
        ant = act;
        act = act->getSiguiente();
    }
    if (act == NULL) return false;

    if (ant == NULL) ppio = act->getSiguiente();
    else             ant->setSiguiente(act->getSiguiente());

    // if (act->getDato() != NULL) delete act->getDato();
    delete act;
    return true;
}
