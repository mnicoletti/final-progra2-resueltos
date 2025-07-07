// Ingresar un texto caracter a caracter terminado en punto y calcular cuántas palabras empiezan con la última letra ingresada de la primer palabra.
#include<stdio.h>
#include<stdlib.h>

void contarPalabras();

int main() {
    contarPalabras();
    return 0;
}

void contarPalabras() {
    int c, ultima, prev, cont_palabras=0, primera_palabra=1;

    printf("Ingrese una frase terminada en '.': \n");
    c = getchar();

    while ( c != '.' ) {
        while ( c != ' ' && c != '.' && primera_palabra == 1) {
            ultima = c;
            c=getchar();
        }

        primera_palabra = 0;

        prev = ' ';

        while ( c != ' ' && c != '.') {
            if (prev == ' ' && c != ' ') {
                if ( c == ultima) {
                    cont_palabras++;
                }
            }

            prev = c;
            c = getchar();
        }

        if ( c != '.' ) {
            c=getchar();
        }
    }

    printf("\nLa cantidad de palabras que empiezan con la letra %c es %d\n", ultima, cont_palabras);
}