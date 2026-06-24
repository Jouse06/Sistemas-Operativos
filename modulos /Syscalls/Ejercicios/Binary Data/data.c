#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // 1. Define the array of 5 integers
    int numbers[5] = {10, 255, 1024, -50, 42};

    // 2. Open a file for writing.
    // O_WRONLY: Write only
    // O_CREAT: Create the file if it doesn't exist
    // O_TRUNC: Empty the file if it already exists
    // 0644: Permissions (rw-r--r--)
    int fd = open("data.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // 3. Write the array to the file as raw binary data
    // The pointer to the array 'numbers' is passed directly.
    // The number of bytes to write is calculated using sizeof(numbers)
    // (which is typically 5 * 4 bytes = 20 bytes).
    ssize_t bytes_written = write(fd, numbers, sizeof(numbers));

    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    printf("Successfully wrote %zd bytes to data.bin\n", bytes_written);

    // 4. Close the file descriptor
    close(fd);

    return 0;
}
