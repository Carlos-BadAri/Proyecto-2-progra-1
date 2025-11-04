#include "ListaVehiculo.h"
 
ListaVehiculo::ListaVehiculo() {
	ppio = NULL;
    actual = NULL;
}
ListaVehiculo::~ListaVehiculo() {
    while (ppio != NULL) {
        NodoVehiculo* aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux;
    }
}
void ListaVehiculo::insertarFinal(NodoVehiculo* n) {
    if (ppio == NULL) {
        ppio = n;
    }
    else {
        NodoVehiculo* aux = ppio;
        while (aux->getSiguiente() != NULL)
            aux = aux->getSiguiente();
        aux->setSiguiente(n);
    }
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