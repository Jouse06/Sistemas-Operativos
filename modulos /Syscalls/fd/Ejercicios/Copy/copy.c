#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    int fd_dest = open(argv[2], O_WRONLY | O_CREAT, 0666);

    char buffer[1024];
    int bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(fd_dest, buffer, bytes_read);
    }
    close(fd);
    close(fd_dest);

    return 0;
}
