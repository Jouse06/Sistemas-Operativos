#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int fd = open("Error.md", O_WRONLY | O_CREAT | O_APPEND, 0666);

    dup2(fd,2);

    int fd2 = open(argv[1], O_RDONLY );

    char buffer[1024];
    int bytes_read;
    while((bytes_read = read(fd2, &buffer, sizeof(buffer))) > 0){
        write(1, &buffer, bytes_read);
    }

    if(fd2 == -1){
        perror("No existe tu vaina mi loco\n");
    }

    return 0;


}
