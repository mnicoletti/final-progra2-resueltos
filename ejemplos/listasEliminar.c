#include<stdio.h>
#include<stdlib.h>

typedef struct lista {
    int num;
    struct lista *sig;
} nodo;

nodo* eliminarPorCabeza(nodo* p) {
    nodo *aux;

    while ( p->sig != NULL ) { // Aca va la condicion de eliminacion que corresponde, revisar bien los ejemplos de la catedra.
        aux = p->sig;
        free(p);
        p = aux;
    }

    return p;
}

void eliminar(nodo* p) {
    nodo *aux;

    while ( p->sig != NULL && p->sig->sig != NULL ) {
        if ( p->sig != NULL ) { // Aca va la condicion de eliminacion que corresponde, revisar bien los ejemplos de la catedra.
            aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        } else {
            p = p->sig;
        }
    }
}

int main() {
    nodo *prin;

    prin = (nodo*)malloc(sizeof(nodo));

    prin = eliminarPorCabeza(prin);
    eliminar(prin);

    return 0;
}