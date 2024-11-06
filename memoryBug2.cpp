#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* return 1 if str is "1", 0 otherwise */
int checkIf1(const char *str) {
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
    const char *strArr[4] = {"1", "2", "3", "4"}; // Use const char* for string literals

    for (int i = 0; i < 4; i++) {
        if (checkIf1(strArr[i])) {
            printf("The string is '1'\n");
        } else {
            printf("The string is not '1'\n");
        }
    }

    return 0;
}
