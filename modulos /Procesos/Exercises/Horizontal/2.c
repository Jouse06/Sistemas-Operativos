#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t padre, pid1, pid2, pid3;

    padre = fork();

    if(padre == 0){
        pid1 = fork();
        pid2 = fork();
        pid3 = fork();

        if(pid1 == 0){
            printf("Child process 1, pid is %d and my parent is %d\n", getpid(), getppid());
        } else if(pid2 == 0){
            printf("Child process 2, pid is %d and my parent is %d\n", getpid(), getppid());
        } else if(pid3 == 0){
            printf("Child process 3, pid is %d and my parent is %d\n", getpid(), getppid());
        }


    }

    return 0;
}
