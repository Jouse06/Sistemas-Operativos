#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int main() {

    pid_t hijo = fork();
    if (hijo == 0) {

        printf("Mi pid es %d, y mi padre es %d\n", getpid(), getppid());

        pid_t nieto = fork();
        if (nieto == 0) {
            printf("Mi pid es %d, y mi padre es %d\n", getpid(), getppid());
            exit(0);
        }
        exit(0);
    }

    printf("Mi pid es %d, y mi padre es %d\n", getpid(), getppid());

    while(wait(NULL) > 0);

    return 0;
}
