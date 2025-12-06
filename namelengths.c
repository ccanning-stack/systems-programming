#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b) {
    const char *const *sa = a;
    const char *const *sb = b;
    size_t x = strlen(*sa);
    size_t y = strlen(*sb);
    return (x > y) - (x < y);
}

int main(int argc, char *argv[]) {

    if (argc <= 1)
        return 0;

    size_t count = argc - 1;
    char **arr = argv + 1;

    qsort(arr, count, sizeof(arr[0]), comp);

    for (size_t i = 0; arr[i] != NULL; i++)
        printf("%s\n", arr[i]);

    return 0;
}
