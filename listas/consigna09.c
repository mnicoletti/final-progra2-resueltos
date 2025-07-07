/*Dada una lista con números enteros, eliminar aquellos nodos cuyos consecutivos sean iguales.

**Ejemplo**: 1 1 5 10 11 25 25 30 30 40 42 50 50

**Respuesta**: 5 10 11 40 42*/
#include<stdio.h>
#include<stdlib.h>

typedef struct lista {
    int num;
    struct lista *sig;
} nodo;

void mostrar(nodo*);
void crear(nodo*);
nodo* eliminarRepetidos(nodo*);

int main() {
    nodo *prin;

    prin = (nodo*)malloc(sizeof(nodo));
    crear(prin);

    mostrar(prin);

    prin = eliminarRepetidos(prin);
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

nodo* eliminarRepetidos(nodo* p) {
    nodo *aux;
    // Primer caso, la cabecera y el segundo nodo están repetidos.
    nodo *cabeza =p;

    while ( p->num == p->sig->num && ( p->sig != NULL && p->sig->sig != NULL ) ) {
        aux = p->sig->sig;
        free(p->sig); // Primero el siguiente, o pierdo la cabeza como Maria Antonieta.
        free(p);
        p = aux;
        cabeza = p;
    }

    while ( p->sig != NULL && p->sig->sig != NULL ) {
        if ( p->sig->num == p->sig->sig->num ) {
            aux = p->sig->sig->sig;
            free(p->sig->sig);
            free(p->sig);
            p->sig = aux;
        } else {
            p = p->sig;
        }
    }
    
    return cabeza;
}