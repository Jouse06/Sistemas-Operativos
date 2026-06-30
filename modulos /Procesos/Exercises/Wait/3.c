#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2, pid3;


        pid1 = fork();
        pid2 = fork();
        pid3 = fork();

        if(pid1 == 0){
            printf("Child process 1, pid is %d and my parent is %d\n", getpid(), getppid());
            exit(0);
        } else if(pid2 == 0){
            printf("Child process 2, pid is %d and my parent is %d\n", getpid(), getppid());
            exit(0);
        } else if(pid3 == 0){
            printf("Child process 3, pid is %d and my parent is %d\n", getpid(), getppid());
            exit(0);
        }

        while(wait(NULL) > 0);

        printf("All child processes have finished\n");


    return 0;
}
