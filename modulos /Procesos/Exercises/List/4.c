#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

    pid_t pid = fork();

    if(pid == 0) {
        printf("Child process is running.\n");
        execl("/bin/ls", "ls", NULL);
        exit(0);
    }

    wait(NULL);

    printf("Child process has finished.\n");

    return 0;
}
