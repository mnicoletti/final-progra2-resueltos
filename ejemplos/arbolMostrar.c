#include <stdio.h>
#include <stdlib.h>

typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

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

int main() {
    treenode* arbol = NULL;

    printf("Mostrar preorden: \n");
    mostrarPreOrden(arbol);
    printf("Mostrar en orden: \n");
    mostrarInOrden(arbol);
    printf("Mostrar posorden: \n");
    mostrarPosOrden(arbol);
    
    return 0;
}