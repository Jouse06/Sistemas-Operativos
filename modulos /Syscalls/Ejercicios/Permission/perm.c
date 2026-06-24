#include <stdio.h>
#include <sys/stat.h> // Required for chmod and permission macros

int main() {
    const char *filepath = "document.txt";

    // 0444 sets read-only permission for User (owner), Group, and Others.
    // Alternatively, using POSIX macros: S_IRUSR | S_IRGRP | S_IROTH
    if (chmod(filepath, 0444) == -1) {
        perror("Error changing file permissions");
        return 1;
    }

    printf("Successfully made '%s' read-only.\n", filepath);

    return 0;
}
