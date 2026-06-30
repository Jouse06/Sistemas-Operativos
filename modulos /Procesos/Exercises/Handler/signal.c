#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

# define Vueltas 10000000

void Handler(int sig) {
    switch (sig) {
        case SIGINT:
            printf("SIGINT received\n");
            exit(0);
            break;
    }

}

int main() {

    signal(SIGINT, Handler);

    for(int i = 0; i < Vueltas; i++) {
        printf("Loop iteration %d\n", i);
    }

    return 0;
}
