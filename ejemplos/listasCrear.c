#include<stdio.h>
#include<stdlib.h>

typedef struct lista {
    int num;
    struct lista *sig;
} nodo;

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

int main() {
    nodo *prin;

    prin = (nodo*)malloc(sizeof(nodo));

    crear(prin);

    return 0;
}