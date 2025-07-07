// Dado N, calcular el producto de los números pares hasta N en forma recursiva.
#include<stdio.h>
#include<stdlib.h>

int calcularProductos(int, int);

int main() {
    int n;
    int producto;

    printf("Ingrese un n: \n");
    scanf("%d", &n);
    producto = calcularProductos(n, 1);

    printf("El producto de todos los numeros pares hasta n = %d es: %d\n", n, producto);
}

int calcularProductos(int n, int tope) {
    if (tope > n) {
        return 1;
    }
    if (tope % 2 == 0) {
        return tope * calcularProductos(n, tope+1);
    } else {
        return 1 * calcularProductos(n, tope+1);
    }
}