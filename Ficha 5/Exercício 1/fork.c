#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
    pid_t pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid1 > 0) {
        printf("Parent process: %d ", (int)getpid());
        exit(EXIT_SUCCESS);
    } else if (pid1 == 0) {
        printf("Child process: %d ", (int)getpid());
        exit(EXIT_SUCCESS);
    }
    fork();
    fork();
    exit(EXIT_SUCCESS);
}