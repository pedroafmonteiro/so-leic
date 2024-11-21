#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct stat info;
    if (argc < 2)
    {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int total_size = 0;
    int total_blocks = 0;
    for (int i = 1; i < argc; i++)
    {
        int retv = stat(argv[i], &info);
        if (retv == -1)
        {
            fprintf(stderr, "fsize: Can’t stat %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        total_size += info.st_size;
        total_blocks += info.st_blocks;
        printf("%s stats:\n", argv[i]);
        printf("    - Size: %ld bytes\n", info.st_size);
        printf("    - Blocks: %ld\n", info.st_blocks);
        printf("    - Last modification: %s", ctime(&info.st_mtime));
        printf("    - Owner UID: %d\n", info.st_uid);   
    }
    printf("Total size: %d bytes\n", total_size);
    printf("Total blocks: %d\n", total_blocks);
    exit(EXIT_SUCCESS);
}