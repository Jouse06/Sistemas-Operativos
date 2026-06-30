#include <fcntl.h>
#include <unistd.h>

int main() {

    execl("./Lector", "Lector", NULL);
    return 0;
}
