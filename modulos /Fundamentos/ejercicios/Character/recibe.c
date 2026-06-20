#include <stdio.h>

int main() {
    char c;
    printf("Ingrese un caracter: ");
    c = getchar();
    printf("El caracter ingresado es: %c\n", c);
    putchar(c);
    return 0;
}
