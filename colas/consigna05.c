// Dada una cola con números enteros, mostrar la suma de todos los valores de la cola si la cantidad de datos en la cola es impar. De lo contrario mostrar su producto.
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
void calcular(nodo**, nodo**);

// Importante: Para este ejemplo se pueden hacer dos cosas:
//   1. Asumir que se cuenta la cantidad de elementos de la cola al crearla, y pasarla por parametro.
//   2. No saber la cantidad de elementos, asi que se debe hacer las dos operaciones al mismo tiempo que se lleva un contador.
// Como me gusta complicar las cosas, voy a optar por la segunda.

int main() {
    nodo* p = NULL;
    nodo* u = NULL;
    int num;
    int contador = 0;
    int producto = 1;
    int sumas = 0;

    printf("Ingrese un numero (sale con 0): \n");
    scanf("%d", &num);

    while ( num != 0 ) {
        acolar(&p, &u, crear_nodo(num));
        printf("Ingrese otro numero (sale con 0): \n");
        scanf("%d", &num);
    }

    calcular(&p, &u);

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

void calcular(nodo **p, nodo **u) {
    int producto = 1;
    int suma = 0;
    int contador = 0;

    if (*p == NULL) {
        printf("La cola esta vacia.");
        return;
    }

    while (*p != NULL) {
        nodo aux = desacolar(p);
        producto = producto * aux.dato;
        suma = suma + aux.dato;
        contador++;
    }

    if (contador % 2 == 0) {
        printf("El producto de los datos de la cola es: %d\n", producto);
    } else {
        printf("La suma de los valores de la cola es: %d\n", suma);
    }
}