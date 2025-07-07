// Dada una lista de números enteros, insertar si el números es par, antes su doble y después su triple.
#include<stdio.h>
#include<stdlib.h>

typedef struct lista {
    int num;
    struct lista *sig;
} nodo;

void mostrar(nodo*);
void crear(nodo*);
nodo* insertarPares(nodo*);

int main() {
    nodo *prin;

    prin = (nodo*)malloc(sizeof(nodo));
    crear(prin);

    mostrar(prin);

    prin = eliminarIndices(prin);
    printf("\n\nLista operada: \n");
    mostrar(prin);

    return 0;
}

void mostrar(nodo *registro) {
    if ( registro->sig != NULL ) {
        printf("%d\n", registro->num);
        mostrar(registro->sig);
    }
    return;
}

void crear(nodo *registro) {
    printf("Ingrese un numero (sale con 0): \n");
    scanf("%d", &registro->num);

    if ( registro->num == 0) { // Esta es la condicion de salida o fin de creacion de lista.
        registro->sig = NULL;
    } else {
        registro->sig = (nodo*)malloc(sizeof(nodo));
        crear(registro->sig);
    }

    return;
}

nodo* insertarPares(nodo *p) {
    nodo *aux, *auxAntes;
    nodo *cabeza = p;

    if ( p->num % 2 == 0 ) {
        
        aux = (nodo*)malloc(sizeof(nodo));
        aux->num = p->num * 3;
        aux->sig = p->sig;
        p->sig = aux;

        auxAntes = (nodo*)malloc(sizeof(nodo));
        auxAntes->num = p->num * 2;
        aux->sig = p;
        p = auxAntes;
        cabeza = p;

        p = p->sig->sig;
    }

    while ( p->sig != NULL && p->sig->sig != NULL) {
        if ( p->sig->num % 2 == 0 ) {
            auxAntes = (nodo*)malloc(sizeof(nodo));
            auxAntes->num = p->sig->num * 2;
            auxAntes->sig = p->sig;

            aux = (nodo*)malloc(sizeof(nodo));
            aux->num = p->sig->num * 3;
            aux->sig = p->sig->sig;

            p->sig = auxAntes;
            p->sig->sig = aux;

            p = p->sig->sig;
        } else {
            p = p->sig;
        }
    }
}