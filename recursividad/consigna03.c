// Dada una matriz de N*N, determinar en forma recursiva si en la diagonal principal el producto de todos los valores es 15.
#include<stdio.h>
#include<stdlib.h>

#define N 3
void calcularDiagonal(int[3][3], int, int, int);

int main() {
    // Caso 1: N = 3, diagonal = {1, 3, 5} → 1*3*5 = 15 → esperado: true (1)
    int matriz1[3][3] = {
        { 1,  2,  3},
        { 4,  3,  6},
        { 7,  8,  5}
    };

    printf("Caso Matriz 1: Diagonal {1,3,5} = 15\n");
    calcularDiagonal(matriz1, N, 0, 1);
    
    // Caso 2: N = 3, diagonal = {1, 0, 5} → 1*0*5 = 0  → esperado: false (0)
    int matriz2[3][3] = {
        { 1,  9, 10},
        {11,  0, 12},
        {13, 14,  5}
    };

    printf("Caso Matriz 2: Diagonal {1,0,5} = 0\n");
    calcularDiagonal(matriz2, N, 0, 1);

    return 0;
}

void calcularDiagonal(int matriz[3][3], int n, int index, int cuenta) {
    // Caso base: index == n con n siendo el valor máximo de indices de la matriz
    if (n == index) {
        if (cuenta == 15) {
            printf("El valor del producto de la diagonal es 15.\n\n");
        } else {
            printf("El valor del producto de la diagonal no es 15: %d\n\n", cuenta);
        }

        return;
    }

    return calcularDiagonal(matriz, n, index+1, cuenta * matriz[index][index]);
}