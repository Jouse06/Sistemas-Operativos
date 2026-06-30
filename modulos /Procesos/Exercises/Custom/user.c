#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void manejador(int sig){
    switch(sig){
        case SIGUSR1:
            printf("SIGUSR1 recibido\n");
            break;
    }
}


int main() {
    pid_t hijo = fork();
    if (hijo == 0) {
        printf("Hijo iniciado\n");
        signal(SIGUSR1, manejador);
        pause();
        exit(0);
    }

    sleep(1);

    kill(hijo, SIGUSR1);
    wait(NULL);
    printf("Hijo terminado\n");
    printf("Padre terminando\n");

    return 0;
}
