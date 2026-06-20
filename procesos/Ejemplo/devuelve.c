#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t hijo = fork();
    if (hijo == 0) {
        printf("Soy el hijo con el pid %d y el pid del padre es %d\n", getpid(), getppid());
    } else {
        printf("Soy el padre con el pid %d y el pid del hijo es %d\n", getpid(), hijo);
    }

    while(wait(NULL)>0);

    return 0;
}
