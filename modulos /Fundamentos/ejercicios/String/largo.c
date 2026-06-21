#include <stdio.h>

int custom_strlen(const char *str) {
    const char *ptr = str;

    while (*ptr != '\0') {
        ptr++;
    }

    return ptr - str;

}

int main() {
    char str[] = "Hello, World!";
    
    int len = custom_strlen(str);

    printf("The string is: \"%s\"\n",str);
    printf("La longitud de la cadena es: %d\n", len);
    
    return 0;
}
