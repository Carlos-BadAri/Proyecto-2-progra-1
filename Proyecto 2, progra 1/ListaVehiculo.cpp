#include "ListaVehiculo.h"
 
ListaVehiculo::ListaVehiculo() {
	ppio = NULL;
    actual = NULL;
}
ListaVehiculo::~ListaVehiculo() {
    NodoVehiculo* aux;
    while (ppio != NULL) {
        aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux->getDato();
        delete aux;
    }
}

void ListaVehiculo::insertarFinal(NodoVehiculo* nuevo) {
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

Vehiculo* ListaVehiculo::buscar(string placa) {
    actual = ppio;
    while (actual != NULL) {
        if (actual->getDato()->getPlaca() == placa) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return NULL; 
}

bool ListaVehiculo::eliminar(string placa) {
    if (ppio == NULL) return false;

    NodoVehiculo* act = ppio;
    NodoVehiculo* ant = NULL;

    while (act != NULL && act->getDato()->getPlaca() != placa) {
        ant = act;
        act = act->getSiguiente();
    }

    if (act == NULL) return false;

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
string ListaVehiculo::toString() {
    stringstream s;
    NodoVehiculo* aux = ppio;
    while (aux != NULL) {
        s << aux->getDato()->toString() << endl;
        aux = aux->getSiguiente();
    }
    return s.str();
}
