#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("[Child] My PID is %d. I am terminating now to become a zombie.\n", getpid());
        exit(EXIT_SUCCESS);
    }
    else {
        printf("[Parent] My PID is %d. I spawned child %d.\n", getpid(), pid);
        printf("[Parent] I am entering an infinite loop without calling wait().\n");
        printf("[Parent] Open a new terminal tab and use 'ps' to find the zombie!\n");
        printf("[Parent] Press Ctrl+C to kill me and clean up the zombie.\n\n");

        while (1) {
            sleep(1);
        }
    }

    return 0;
}
