// Dada una matriz de N*N elementos, determinar en forma recursiva si en la diagonal principal el producto de todos los valores es menor a 20.
#include<stdio.h>
#include<stdlib.h>

void calcularMatriz(int[][], int, int);

int main() {
    int matriz[3][3];

    calcularMatriz(matriz, 3, 0);
    return 0;
}

void calcularMatriz(int matriz[3][3], int n, int cuenta) {
    if ( n < 0 ) { 
        if ( cuenta < 20 ) {
            printf("La diagonal tiene un producto menor a 20.");
        } else {
            printf("La diagonal tiene un producto mayor a 20.");
        }

        return;
    }

    return calcularMatriz(matriz, n-1, cuenta * matriz[n][n]);
}