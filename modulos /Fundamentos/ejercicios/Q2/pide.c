#include <stdio.h>
#include <unistd.h>


int pide_numero(int num) {
    while(num > 0) {
        num -= 1;
        printf("El numero que queda es %d\n", num);
        sleep(1);
    }
    return num;
}



int main() {
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    pide_numero(num);
    return 0;
}
