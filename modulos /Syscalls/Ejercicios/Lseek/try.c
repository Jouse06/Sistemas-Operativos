#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main() {
    int fd = open("file.txt", O_RDWR|O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char message[] = "HELLO!\n";

    write(fd, message, strlen(message));

    lseek(fd, 0, SEEK_SET);

    char buffer[1024];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[bytes_read] = '\0';
    printf("Read from file: %s", buffer);

    close(fd);

    return 0;
}
