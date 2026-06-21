#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int result = unlink(argv[1]);
    if (result == -1) {
        perror("unlink");
        return 1;
    }

    printf("Removed: %s\n", argv[1]);

    return 0;
}
