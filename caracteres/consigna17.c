// Dado un texto carácter a carácter, contar cuantas palabras empiezan en a y terminan en as, y mostrar dicho texto con 4 blancos de separación entre las palabras.
#include<stdio.h>
#include<stdlib.h>

void contarPalabras();

int main() {
    contarPalabras();
    return 0;
}

void contarPalabras() {
    int c, prev = ' ';
    int cont_palabras = 0;
    int cont_letra = 0;
    int first_char = 0;
    int prev1 = 0, prev2 = 0;
    int i;

    printf("Ingrese una frase terminada en '.':\n");
    c = getchar();

    while (c != '.') {
        if (c != ' ') {
            if (prev == ' ') {
                first_char = c;
                cont_letra = 1;
                prev1 = c;
                prev2 = 0;
            } else {
                cont_letra++;
                prev2 = prev1;
                prev1 = c;
            }
            putchar(c);
            prev = c;
        } else {
            if (cont_letra >= 2 && first_char == 'a' && prev2 == 'a' && prev1 == 's') {
                cont_palabras++;
            }

            for (i = 0; i < 4; i++)
                putchar(' ');

            cont_letra = 0;
            prev = ' ';
        }
        c = getchar();
    }

    if (cont_letra >= 2 && first_char == 'a' && prev2 == 'a' && prev1 == 's') {
        cont_palabras++;
    }

    if ( c != '.' ) {
        c = getchar();
    }

    printf("\nCantidad de palabras que empiezan en 'a' y terminan en \"as\": %d\n", cont_palabras);
}