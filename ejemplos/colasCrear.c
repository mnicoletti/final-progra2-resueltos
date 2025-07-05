#include<stdio.h>
#include<stdlib.h>

typedef struct cola {
    int dato;
    struct cola *siguiente;
} nodo;

nodo* crear_nodo(int dato) {
    nodo *u;
    u = (nodo*)malloc(sizeof(nodo));
    u->dato = dato;
    u->siguiente = NULL;
    return u;
}

void acolar(nodo** p, nodo** u, nodo *q) {
    if ( *p == NULL ) {
        *p = *u = q;
    } else {
        (*u)->siguiente = q;
        (*u) = q;
    }
}

int main() {
    nodo* p = NULL;
    nodo* u = NULL;
    int num;

    printf("Ingrese un numero (sale con 0): \n");
    scanf("%d", &num);

    while ( num != 0 ) {
        acolar(&p, &u, crear_nodo(num));
        printf("Ingrese otro numero (sale con 0): \n");
        scanf("%d", &num);
    }

    return 0;
}