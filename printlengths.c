#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b) {
    size_t x = *(const size_t *)a;
    size_t y = *(const size_t *)b;
    return (x > y) - (x < y);
}

int main(int argc, char *argv[]) {

    size_t arr[argc];
    size_t count = argc - 1;

    for (int i = 1; i < argc; i++) {
        size_t length = strlen(argv[i]);
        arr[i - 1] = length;
    }

    qsort(arr, count, sizeof(arr[0]), comp);

    for (size_t i = 0; i < count; i++) {
        printf("%zu\n", arr[i]);
    }
}
