#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 0;

    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process\n");
        x++;
        printf("x = %d\n", x);

    } else {
        printf("Parent process\n");
        printf("x = %d\n", x);
    }
}
