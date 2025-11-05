#include "ListaPlantel.h"

ListaPlantel::ListaPlantel() {
    ppio = NULL;
    actual = NULL;
}

ListaPlantel::~ListaPlantel() {
    while (ppio != NULL) {
        NodoPlantel* aux = ppio;
        ppio = ppio->getSiguiente();
        delete aux;
    }
}

void ListaPlantel::insertarFinal(NodoPlantel* n) {
    if (ppio == NULL)
        ppio = n;
    else {
        NodoPlantel* aux = ppio;
        while (aux->getSiguiente() != NULL)
            aux = aux->getSiguiente();
        aux->setSiguiente(n);
    }
}

string ListaPlantel::toString() {
    stringstream s;
    NodoPlantel* aux = ppio;
    while (aux != NULL) {
        s << aux->getDato()->toString() << endl;
        aux = aux->getSiguiente();
    }
    return s.str();
}

NodoPlantel* ListaPlantel::getPpio() {
    return ppio;
}
