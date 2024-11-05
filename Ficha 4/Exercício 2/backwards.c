#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

void reverse_buffer(char *buffer, int length) {
    for (int i = 0; i < length / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[length - i - 1];
        buffer[length - i - 1] = temp;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("usage: backwards filename\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < argc; i++)
    {
        int fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            printf("error: cannot open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        off_t file_size = lseek(fd, 0, SEEK_END);
        if (file_size == -1)
        {
            printf("error: cannot seek %s\n", argv[i]);
            close(fd);
            exit(EXIT_FAILURE);
        }

        char buffer[BUFFER_SIZE];
        off_t offset = file_size;
        while (offset > 0)
        {
            int to_read = (offset >= BUFFER_SIZE) ? BUFFER_SIZE : offset;
            offset -= to_read;
            lseek(fd, offset, SEEK_SET);
            int nbytes = read(fd, buffer, to_read);
            if (nbytes == -1)
            {
                printf("error: cannot read %s\n", argv[i]);
                close(fd);
                exit(EXIT_FAILURE);
            }
            reverse_buffer(buffer, nbytes);
            write(STDOUT_FILENO, buffer, nbytes);
        }
        close(fd);
    }
    exit(EXIT_SUCCESS);
}