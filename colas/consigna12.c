// La cantidad de elementos cuyo valor es igual a la suma entre el primer y último elemento ingresado en una cola.
#include<stdio.h>
#include<stdlib.h>

typedef struct cola {
    int dato;
    struct cola *siguiente;
} nodo;

nodo* crear_nodo(int);
void acolar(nodo**, nodo**, nodo*);
nodo desacolar(nodo**);
void mostrar(nodo);
int calcular(nodo**, nodo**);

int main() {
    nodo* p = NULL;
    nodo* u = NULL;
    int num;
    int contador;

    printf("Ingrese un numero (sale con 0): \n");
    scanf("%d", &num);

    while ( num != 0 ) {
        acolar(&p, &u, crear_nodo(num));
        printf("Ingrese otro numero (sale con 0): \n");
        scanf("%d", &num);
    }

    contador = calcular(&p, &u);

    printf("\nLa cantidad de nodos con la suma del primero y el ultimo es: %d", contador);

    return 0;
}

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

nodo desacolar(nodo** inicio) {
    nodo* aux;
    nodo datos;

    datos = **inicio;

    aux = *inicio;

    *inicio = (*inicio)->siguiente;
    free(aux);

    return datos;
}

void mostrar(nodo aux) {
    printf("%d \n", aux.dato);
}

int calcular(nodo **p, nodo **u) {
    int contador = 0;

    if ( *p == NULL ) {
        printf("La cola está vacía.");
        return 0;
    }

    int primero = (*p)->dato;
    int ultimo = (*p)->dato;

    int sumados = primero + ultimo;

    while ( *p != NULL ) {
        nodo aux = desacolar(p);
        if ( sumados == aux.dato ) {
            contador++;
        }
    }

    return contador;
}