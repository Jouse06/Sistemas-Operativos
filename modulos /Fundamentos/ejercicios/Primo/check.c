#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num>\n", argv[0]);
        return 1;
    }
    int num = atoi(argv[1]);
    int is_prime = 1;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            is_prime = 0;
            break;
        }
    }
    if (is_prime) {
        printf("%d es primo\n", num);
    } else {
        printf("%d no es primo\n", num);
    }

    return 0;
}
