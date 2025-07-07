// La cantidad de nodos internos del árbol. Es decir, aquellos que no son ni la raiz, ni los nodos hojas.
#include<stdio.h>
#include<stdlib.h>

typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void crear(treenode**);
void insertar(treenode**, int);
void mostrarPreOrden(treenode*);
void mostrarInOrden(treenode*);
void mostrarPosOrden(treenode*);

void calcularInternos(treenode*, int*, int);

int main() {
    int cuenta = 0, raiz;
    treenode* arbol = NULL;

    crear(&arbol);
    if ( arbol != NULL ) {
        printf("\n## Recorrer el arbol In Order:\n ");
        mostrarInOrden(arbol);
        printf("\n## Recorrer el arbol Pre Order:\n");
        mostrarPreOrden(arbol);
        printf("\n## Mostrar Pos Orden:\n");
        mostrarPosOrden(arbol);

        raiz = arbol->dato; // Necesito la raiz para calcular cosas.

        calcularInternos(arbol, &cuenta, raiz);

        printf("\nLa cantidad de multiplos impares de la raiz en los nodos hoja es: %d", cuenta);
    }
    return 0;
}

void mostrarPreOrden(treenode *arbol) {
    if ( arbol != NULL ) {
        printf("%d\t", arbol->dato);
        mostrarPreOrden(arbol->izq);
        mostrarPreOrden(arbol->der);
    }
}

void mostrarInOrden(treenode *arbol) {
    if ( arbol != NULL ) {
        mostrarInOrden(arbol->izq);
        printf("%d\t", arbol->dato);
        mostrarInOrden(arbol->der);
    }
}

void mostrarPosOrden(treenode *arbol) {
    if ( arbol != NULL ) {
        mostrarPosOrden(arbol->izq);
        mostrarPosOrden(arbol->der);
        printf("%d\t", arbol->dato);
    }
}

void crear(treenode **hoja) {
    int numero;

    printf("Ingrese un numero (sale con -1): \n");
    scanf("%d", &numero);
    while ( numero != -1) {
        insertar(&(*hoja), numero);
        printf("Ingrese un numero (sale con -1): \n");
        scanf("%d", &numero);
    }
}

void insertar(treenode **hoja, int elemento) {
    int numero = elemento;

    if ( elemento == -1 ) {
        return;
    }

    if ( *hoja == NULL ) {
        (*hoja) = (treenode*)malloc(sizeof(treenode));
        (*hoja)->dato = elemento;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    } else {
        if ( numero > (*hoja)->dato ) {
            insertar(&(*hoja)->der, elemento);
        } else {
            insertar(&(*hoja)->izq, elemento);
        }
    }

    return;
}

void calcularInternos(treenode *arbol, int *contador, int raiz) {
    if ( arbol != NULL ) {
        calcularInternos(arbol->izq, contador, raiz);
        if ( raiz != arbol->dato && ( arbol->izq != NULL && arbol->der != NULL ) ) {
            *contador = *contador + 1;
        }
        calcularInternos(arbol->der, contador, raiz);
    }
}