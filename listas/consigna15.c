/*Dada una lista con números enteros, solicitar al usuario el ingreso de dos números. Luego, eliminar aquellos nodos que se encuentren entre las posiciones (índices) indicados por el usuario. Tomar como primer índice el valor 0.

**Ejemplo**: 5 32 41 8 37 45 8 9 15 28
Se ingresan 0 y 4.

**Respuesta**: 45 8 9 15 28.*/
#include<stdio.h>
#include<stdlib.h>

typedef struct lista {
    int num;
    struct lista *sig;
} nodo;

void mostrar(nodo*);
void crear(nodo*);
nodo* eliminarIndices(nodo*);

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

nodo* eliminarIndices(nodo* p) {
    int menorIndex = 0;
    int mayorIndex = 0;
    int indice = 0;
    nodo *aux;
    nodo *cabeza = p;

    printf("Ingrese un numero de indice: \n");
    scanf("%d", &menorIndex);
    printf("Ingrese un numero de indice mayor al anterior: \n");
    scanf("%d", &mayorIndex);

    while ( indice >= menorIndex && indice <= mayorIndex ) {
        aux = p->sig;
        free(p);
        p = aux;
        cabeza = p;

        indice++;
    }

    indice++; // Tengo que calcular que la cabecera cuenta como 1.
    
    while ( p->sig != NULL && p->sig->sig != NULL ) {
        if ( indice >= menorIndex && indice <= mayorIndex ) {
            aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        } else {
            p = p->sig;
        }

        indice++;
    }

    return cabeza;
}