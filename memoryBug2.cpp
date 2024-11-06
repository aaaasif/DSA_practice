#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* return 1 if str is "1", 0 otherwise */
int checkIf1(char *str) {
    char *newstr = (char *)malloc(strlen(str) + 1);
    if (newstr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strcpy(newstr, str); /* set newstr to str */
    if (strcmp(newstr, "1") == 0) { /* newstr is "1" */
        free(newstr); // Free memory before returning
        return 1;
    }
    free(newstr); // Free memory here if condition is not met
    return 0;
}

int main() {
    char str[10];
    printf("Enter a string: ");
    scanf("%9s", str); // Limit input to avoid buffer overflow

    if (checkIf1(str)) {
        printf("The string is '1'\n");
    } else {
        printf("The string is not '1'\n");
    }

    return 0; // Add the missing closing brace for main
}