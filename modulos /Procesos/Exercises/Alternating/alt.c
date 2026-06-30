#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int p2c[2];
    int c2p[2];

    if (pipe(p2c) == -1 || pipe(c2p) == -1) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        char token;

        for (int i = 0; i < 10; i++) {
            read(p2c[0], &token, 1);

            write(fd, "1", 1);

            write(c2p[1], "T", 1);
        }

        close(p2c[0]); close(p2c[1]);
        close(c2p[0]); close(c2p[1]);
        close(fd);
        exit(EXIT_SUCCESS);
    }
    else {
        char token;

        for (int i = 0; i < 10; i++) {
            write(fd, "2", 1);

            write(p2c[1], "T", 1);

            read(c2p[0], &token, 1);
        }

        wait(NULL);
        close(p2c[0]); close(p2c[1]);
        close(c2p[0]); close(c2p[1]);
        close(fd);
    }

    printf("File 'output.txt' successfully written with alternating characters.\n");
    return 0;
}
