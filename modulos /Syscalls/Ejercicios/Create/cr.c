#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int fd = creat(argv[1], 0666);
    if (fd == -1) {
        perror("Error al crear el archivo");
        return 1;
    }

    printf("Archivo creado exitosamente: %i\n", fd);
    close(fd);

    return 0;
}
