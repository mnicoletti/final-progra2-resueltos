#include<stdio.h>
#include<stdlib.h>

#define CANT 5

typedef struct tiponodo {
	int dato;
    struct tiponodo *siguiente;
} nodo;

void mostrar(nodo aux) {
    printf("%d\n", aux.dato);
}

nodo desapilar(nodo** p) {
    nodo* aux;
    nodo datos;

    datos = **p;
    aux = *p;
    
    *p = (*p)->siguiente;

    free(aux);

    return datos;
}

int main() {
    nodo* p = NULL;

    while(p != NULL) {
        mostrar(desapilar(&p));
    }

    return 0;
}