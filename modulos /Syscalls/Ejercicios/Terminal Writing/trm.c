#include <unistd.h>

int main() {
    char *message = "Mensaje\n";
    write(1, message, 8);
    return 0;
}
