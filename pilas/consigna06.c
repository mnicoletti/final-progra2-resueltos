// La cantidad de números múltiplos del último número ingresado en una Pila de números enteros.
#include<stdio.h>
#include<stdlib.h>

typedef struct tiponodo {
	int dato;
    struct tiponodo *siguiente;
} nodo;

nodo* crear_nodo(int);
void apilar(nodo**, nodo*);
void mostrar(nodo);
nodo desapilar(nodo**);
// Hay que recordar que para el caso de las pilas, son una estructura LIFO,
// es decir que el ultimo elemento ingresado esta en la cabecera
// de la estructura.
// Traduccion: Quedate con el valor de p, que es el ultimo dato.
// En cambio, si te piden el primero, tenes que pensar en quedartelo cuando la lista
// todavia esta vacia.
void calcular(nodo**);

int main() {
    int ultimo, num, cantidad = 0;
    nodo* p = NULL;

    printf("Ingrese un numero (sale con 0): \n");
    scanf("%d", &num);

    while ( num != 0 ) {
        apilar(&p, crear_nodo(num));
        printf("Ingrese otro numero: \n");
        scanf("%d", &num);
    }
    
    calcular(&p);
    return 0;
}

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

void calcular(nodo **p) {
    int contador = 0, ultimo;

    if (*p == NULL) {
        printf("Pila vacia.\n");
        return;
    }

    ultimo = (*p)->dato;

    while(*p != NULL) {
        nodo aux = desapilar(p);
        if (aux.dato % ultimo == 0) {
            contador++;
        }
    }

    printf("\nLa cantidad de multiplos de %d es: %d\n", ultimo, contador);
}