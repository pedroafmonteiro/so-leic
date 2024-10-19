#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 64

bool ifOccurs(char *str1, char *str2) {
    return strstr(str2, str1) != NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <string> <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *input1 = (char *)malloc(MAX_SIZE * sizeof(char));
    char *input2 = (char *)malloc(MAX_SIZE * sizeof(char));

    if (input1 == NULL || input2 == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    strncpy(input1, argv[1], MAX_SIZE - 1);
    strncpy(input2, argv[2], MAX_SIZE - 1);
    input1[MAX_SIZE - 1] = '\0';
    input2[MAX_SIZE - 1] = '\0';

    for (int i = 0; input1[i]; i++) {
        input1[i] = tolower(input1[i]);
    }
    for (int i = 0; input2[i]; i++) {
        input2[i] = tolower(input2[i]);
    }

    if (ifOccurs(input1, input2)) {
        printf("String '%s' occurs in '%s'\n", input1, input2);
    } else {
        printf("String '%s' does not occur in '%s'\n", input1, input2);
    }

    free(input1);
    free(input2);
    exit(EXIT_SUCCESS);
}