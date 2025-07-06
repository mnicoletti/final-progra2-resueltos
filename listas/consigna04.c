// Dada una lista de números enteros eliminar el nodo anterior y posterior de un nodo cuyo número es par.
#include<stdio.h>
#include<stdlib.h>

typedef struct lista {
    int num;
    struct lista *sig;
} nodo;

void mostrar(nodo*);
void crear(nodo*);
nodo* eliminarPorPares(nodo*);

int main() {
    nodo *prin;

    prin = (nodo*)malloc(sizeof(nodo));
    crear(prin);

    mostrar(prin);

    prin = eliminarPorPares(prin);

    printf("\nLista calculada: \n");
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

nodo* eliminarPorPares(nodo *p) {
    nodo *cabeza = p;
    nodo *aux;

    if ( p->sig != NULL && p->sig->sig != NULL ) {
        // Si la cabeza es par, tengo que borrar el siguiente.
        if (p->num % 2 == 0) {
            aux = p->sig;
            p->sig = p->sig->sig;
            free(aux);
        }
        
        // Si el segundo valor es par, elimino la cabeza y el que sigue.
        if ( p->sig->num % 2 == 0) {
            aux = p->sig;
            free(p);
            p = aux;

            cabeza = p;

            // Pero tambien tengo que borrar el que seguia:
            aux = p->sig;
            free(p->sig);
            p->sig = aux->sig;
        }
    }

    return cabeza;
}