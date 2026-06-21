#include <stdio.h>
#include <stdlib.h>


int main() {
    int N;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int *arr = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);


    return 0;
}
