#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>

int main(int argc, char *argv[])
{
    if (access(argv[1], F_OK) == 0)
    {
        /* file exists - insert code to change last access date */
        utime(argv[1], NULL);
    }
    else
    {
        /* file does not exist - create it with given access permissions */
        mode_t perms = 644;
        int fd = open(argv[1], O_CREAT | O_WRONLY, perms);
        close(fd);
    }
    exit(EXIT_SUCCESS);
}