#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fdLog = open("output.log", O_WRONLY | O_CREAT|O_TRUNC, 0666);

    dup2(fdLog, 1);

    printf("Tu mama en 4\n");

    close(fdLog);

    return 1;


}
