#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
    int fd_info = open("info.log", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (fd_info == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    int fd_debug = open("debug.log", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (fd_debug == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    dup2(fd_info,1);
    dup2(fd_debug,2);

    close(fd_info);
    close(fd_debug);

    printf("Log started\n");

    int fd_fake = open("whatever.txt", O_RDONLY);

    if (fd_fake == -1) {
        perror("This goes to the debug log\n");
    }


    return 0;
}
