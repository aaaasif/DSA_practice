#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* return 1 if str is "1", 0 otherwise */
int checkIf1(char *str) {
    char *newstr = malloc(strlen(str) + 1);
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
    char *strArr[4] = {"1", "2", "3", "4"};
    int i;
    for (i = 0; i < 4; i++) {
        printf("%d\n", checkIf1(strArr[i]));
    }
    return 0;
}
