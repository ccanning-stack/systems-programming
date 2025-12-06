#define _POSIX_C_SOURCE 200809L
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int returnValue;
    char name[_POSIX_HOST_NAME_MAX + 1];

    returnValue = gethostname(name, sizeof name);
    if (returnValue == -1) {
        perror("gethostname");
    } else {
        printf("%s\n", name);
    }
}
