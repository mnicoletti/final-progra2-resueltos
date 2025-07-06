// Dado un texto carácter a caracter, contar cuantas palabras de 4 letras tiene el texto y mostrar dicho texto con 6 blancos de separación entre palabras.
#include<stdio.h>
#include<stdlib.h>

void mostrarCaracteres();

int main() {
    mostrarCaracteres();
    return 0;
}

void mostrarCaracteres() {
    int c, aux, cont_letra=0, cont_palabras=0, i=0;

    printf("Ingrese una frase terminada en '.': \n");
    c=getchar();

    while( c != '.' ) {
        if ( c != ' ' ) {
            putchar(c);
            cont_letra++;
        } else {
            if ( cont_letra == 4 ) {
                cont_palabras++;
            }

            for(i=0; i<6; i++) {
                putchar(' ');
            }

            cont_letra = 0;
        }

        if ( c != '.' ) {
            c=getchar();
        }
    }

    printf("Cantidad de palabras de 4 letras: %d", cont_palabras);
}