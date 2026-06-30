#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int main() {

    pid_t hijo = fork();
    if (hijo == 0) {


        pid_t nieto = fork();
        if (nieto == 0) {
            execl("/bin/ps", "ps", NULL);
            exit(0);
        }

        wait(NULL);
        execl("/bin/ls", "ls", NULL);
        exit(0);
    }


    while(wait(NULL) > 0);

    printf("Hijo terminado");

    return 0;
}
