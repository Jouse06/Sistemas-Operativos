#include <stdio.h>

int main() {
    int num;
    char nombre[50];
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    printf("El numero ingresado es: %d\n", num);
    printf("El nombre ingresado es: %s\n", nombre);
        return 0;
    }
