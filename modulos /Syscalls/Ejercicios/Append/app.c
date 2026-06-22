#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_WRONLY | O_CREAT| O_APPEND, 0666);
    char *msg = "Log entry\n";
    write(fd, msg, strlen(msg));

    close(fd);

    printf("Succesfully appended loh entry to %s\n",argv[1]);

    return 0;
}
