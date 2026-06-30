#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main() {

    int fd = open("Ejemplo.txt", O_RDONLY);
    char buffer[1024];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read > 0) {
        printf("%s\n", buffer);
    }
    close(fd);
    return 0;
}
