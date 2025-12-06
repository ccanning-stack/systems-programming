#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char name[4];
    size_t len = 3;
    int returnValue;

    returnValue = gethostname(name, len);
    if (returnValue == -1) {
        perror("gethostname");
    } else {
        printf("%s\n", name);
    }
}
