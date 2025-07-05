#include <stdio.h>
#include <stdlib.h>

typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void crear(treenode **hoja) {
    int numero;

    printf("Ingrese un numero: \n");
    scanf("%d", &numero);
    while(numero != -1) { // Condicion de salida.
        insertar(&(*hoja), numero);
        printf("Ingrese un numero: \n");
        scanf("%d", &numero);
    }
}

void insertar(treenode **hoja, int elem) {
    int numero = elem;
    if ( elem == -1 )
        return;
    
    if ( *hoja == NULL ) {
        (*hoja) = (treenode*)malloc(sizeof(treenode));
        (*hoja)->dato = elem;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    } else {
        if ( numero > (*hoja)->dato ) {
            insertar(&(*hoja)->der, elem);
        } else {
            insertar(&(*hoja)->izq, elem);
        }
    }

    return;
}

int main() {
    treenode* arbol = NULL;

    crear(&arbol);
    return 0;
}