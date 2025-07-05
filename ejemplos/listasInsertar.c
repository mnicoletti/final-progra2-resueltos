#include<stdio.h>
#include<stdlib.h>

typedef struct lista {
    int num;
    struct lista *sig;
} nodo;

nodo* insertarPorCabeza(nodo *p) {
    nodo *aux;

    if ( p->sig != NULL ) { // Esta es la condicion por la cual se va a insertar, revisar todos los ejemplos de la catedra.
        aux = (nodo*)malloc(sizeof(nodo));

        aux->num = 0; // Valores a insertar
        aux->sig = p;
        p = aux;
    }

    return p;
}

void insertar(nodo *p) {
    nodo *aux;

    while ( p->sig != NULL ) {
        if ( p->sig != NULL ) { // condicion de insercion, revisar todos los ejemplos de la catedra.
            aux = (nodo*)malloc(sizeof(nodo));
            
            aux->num = 0;
            aux->sig = p->sig;
            p->sig = aux;
        }

        p = p->sig;
    }
}

int main() {
    nodo *prin;

    prin = (nodo*)malloc(sizeof(nodo));

    prin = insertarPorCabeza(prin);
    insertar(prin);

    return 0;
}