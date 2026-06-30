#include <stdio.h>
#include <unistd.h>

// The parent process is executed first, then the child process is executed

int main() {

    pid_t pid = fork();
    if(pid == 0) {
        printf("Child process\n");
    } else {
        printf("Parent process\n");
    }
    return 0;
}
