#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sched.h>

int main(int argc, char *argv[]) {
    int fd = open("./forking.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

    if (fd < 0) {
        perror("open");
        exit(1);
    }

    dup2(fd, STDOUT_FILENO);

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Niño: En un lugar de la Mancha, de cuyo nombre no quiero acordarme, no ha mucho tiempo que vivía un hidalgo de los de lanza en astillero, ");
        sched_yield(); // Child gives up CPU
        printf("adarga antigua, rocín flaco y galgo corredor, una olla de algo más vaca que carnero, ");
        sched_yield();
        printf("salpicón las más noches, duelos y quebrantos los sábados, lentejas los viernes, algún palomino de añadidura los domingos. ");
        exit(0);
    } else {
        printf("Parent: It was the best of times, it was the worst of times, it was the age of wisdom, ");
        sched_yield(); // Parent gives up CPU
        printf("it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity, ");
        sched_yield();
        printf("it was the season of Light, it was the season of Darkness, we had everything before us, we had nothing before us. ");
        wait(NULL);
    }

    close(fd);
    return 0;
}
