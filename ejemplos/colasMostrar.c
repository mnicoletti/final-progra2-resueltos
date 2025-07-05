#include<stdio.h>
#include<stdlib.h>

typedef struct cola {
    int dato;
    struct cola *siguiente;
} nodo;

nodo desacolar(nodo** inicio) {
    nodo* aux;
    nodo datos;

    datos = **inicio;

    aux = *inicio;

    *inicio = (*inicio)->siguiente;
    free(aux);

    return datos;
}

void mostrar(nodo aux) {
    printf("%d \n", aux.dato);
}

int main() {
    nodo* p = NULL;
    nodo* u = NULL;
    int num;

    while ( p != NULL ) {
        mostrar(desacolar(&p));
    }

    return 0;
}