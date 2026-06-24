#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer;
    int bytes_read;
    while((bytes_read = read(fd, &buffer, 1)) > 0) {
        write(1, &buffer, bytes_read);
        sleep(1);
    }

    close(fd);

    return 0;
}
