#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

    int fd_in = open(argv[1], O_RDONLY);

    dup2(fd_in, 0);

    close(fd_in);

    char c;
    while (read(0, &c, 1) == 1) {
        write(1, &c, 1);
    }

    return 0;
}
