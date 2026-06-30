#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;

    printf("Main Parent process started. PID: %d\n", getpid());

    // --- FIRST CHILD ---
    pid1 = fork();
    if (pid1 == 0) {
        printf("Child process 1, my PID is %d and my parent is %d\n", getpid(), getppid());
        exit(EXIT_SUCCESS); // CRITICAL: stops Child 1 from continuing down the file
    }

    // --- SECOND CHILD ---
    pid2 = fork();
    if (pid2 == 0) {
        printf("Child process 2, my PID is %d and my parent is %d\n", getpid(), getppid());
        exit(EXIT_SUCCESS);
    }

    // --- THIRD CHILD ---
    pid3 = fork();
    if (pid3 == 0) {
        printf("Child process 3, my PID is %d and my parent is %d\n", getpid(), getppid());
        exit(EXIT_SUCCESS);
    }

    // --- PARENT CLEANUP ---
    // The parent process bypasses all the (pid == 0) blocks and ends up here.
    // It must wait for all three children to finish to prevent zombie processes.
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("All children terminated. Parent exiting.\n");
    return 0;
}
