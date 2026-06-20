#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

    int result = access(argv[1], F_OK);

    if (result == 0) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}
