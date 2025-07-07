// Dado N, calcular el factorial de N en forma recursiva.
#include<stdio.h>
#include<stdlib.h>

int calcularFactorial(int);

int main() {
    int factorial;
    int n;

    printf("Ingrese un n: \n");
    scanf("%d", &n);
    factorial = calcularFactorial(n);

    printf("El factorial de %d es: %d", n, factorial);

    return 0;
}

int calcularFactorial(int n) {
    if (n == 0 )
        return 1;

    return n * calcularFactorial(n-1);
}