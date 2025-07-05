#include<stdio.h>
#include<stdlib.h>

#define CANT 5

typedef struct tiponodo {
	int dato;
    struct tiponodo *siguiente;
} nodo;

nodo* crear_nodo(int dato) {
    nodo* u;
    u = (nodo*)malloc(sizeof(nodo));
    u->dato = dato;

    u->siguiente = NULL;

    return u;
}

void apilar(nodo** p, nodo* u) {
    u->siguiente = *p;
    *p = u;
}

int main() {
    int i, num;
    nodo* p = NULL;

    for( i=0; i<CANT; i++ ) {
        printf("Ingrese un numero: \n");
        scanf("%d", &num);
        apilar(&p, crear_nodo(num));
    }

    // Otra forma de crear una pila podría ser mediante una condicion explicita, 
    // como por ejemplo si el numero que se ingresa es 0.
    printf("Ingrese un numero (sale con 0): \n");
    scanf("%d", &num);

    while ( num != 0 ) {
        apilar(&p, crear_nodo(num));
        printf("Ingrese otro numero: \n");
        scanf("%d", &num);
    }

    return 0;
}