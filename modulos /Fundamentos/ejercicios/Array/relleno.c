#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main() {
    int arr[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        arr[i] = (rand() % 900000) +100000;
    }

    printf("Array value in reverse order:\n");

    for (int i = 9; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
