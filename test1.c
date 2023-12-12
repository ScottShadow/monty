#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>





int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter a line of text: ");
    read = getline(&line, &len, stdin);

    if (read != -1) {
        printf("Line read: %s", line);
    } else {
        printf("Error reading the line\n");
    }

    free(line); // Free the allocated memory

    return 0;
}