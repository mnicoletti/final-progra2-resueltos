// Ingresar un texto caracter a caracter terminado en punto y calcular en cuantas palabras aparece la primera vocal ingresada en la primer palabra.
#include<stdio.h>
#include<stdlib.h>

void contarPalabras();

int main() {
    contarPalabras();
    return 0;
}

void contarPalabras() {
    int c, vocal=0, cont_palabras=0, contada=0;

    printf("Ingrese una frase terminada en '.': \n");
    c = getchar();

    while(c != '.') {
        if ( c != ' ' ) {
            if ( vocal == 0) {
                if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) {
                    vocal = c;
                    contada = 1;
                }
            }

            if ( c == vocal && contada == 0) {
                cont_palabras++;
                contada=1;
            }
        } else {
            contada = 0;
        }

        if ( c != '.' ) {
            c=getchar();
        }
    }

    printf("Cantidad de palabras con la primera vocal %c: %d", vocal, cont_palabras);
}