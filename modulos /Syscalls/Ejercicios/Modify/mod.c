#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // 1. Open the file in Read/Write mode
    // We assume "data.txt" already exists and is at least 51 bytes long.
    int fd = open("data.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // 2. Move the file pointer exactly to the 50th byte.
    // SEEK_SET tells lseek to count the offset from the very beginning of the file.
    off_t offset = lseek(fd, 50, SEEK_SET);
    if (offset == -1) {
        perror("Error seeking in file");
        close(fd);
        return 1;
    }

    // 3. Write the character 'X' at the new position
    char target_char = 'X';
    ssize_t bytes_written = write(fd, &target_char, 1);

    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    printf("Successfully wrote 'X' at byte offset 50.\n");

    // 4. Close the file descriptor
    close(fd);

    return 0;
}
