#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


// Given a for loop that runs 3 times calling fork(), if there are no if (pid==0) break conditions, how many total processes are created?

int main() {

    for(int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if(pid == 0) {
                printf("Process %d created\n", i + 1);
            break;
        }
        waitpid(pid, NULL, 0);

    }

    return 0;
}

// Total processes: 3
