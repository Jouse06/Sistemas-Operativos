#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


int main() {

    int fd = open("lol.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        printf("%s\n", strerror(errno));
        return 1;
    }

    close(fd);
}
