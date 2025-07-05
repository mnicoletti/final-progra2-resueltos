#include<stdio.h>
#include<stdlib.h>

typedef struct lista {
    int num;
    struct lista *sig;
} nodo;

void mostrar(nodo *registro) {
    if ( registro->sig != NULL ) {
        printf("%d\n", registro->num);
        mostrar(registro->sig);
    }

    return;
}

int main() {
    nodo *prin;

    prin = (nodo*)malloc(sizeof(nodo));

    mostrar(prin);

    return 0;
}