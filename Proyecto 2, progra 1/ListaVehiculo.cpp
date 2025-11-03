#include "ListaVehiculo.h"
 
ListaVehiculo::ListaVehiculo() {
	ppio = NULL;
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
    NodoVehiculo* aux = ppio;
    while (aux != NULL) {
        cout << aux->getDato()->toString() << endl;
        aux = aux->getSiguiente();
    }
}