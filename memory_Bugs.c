#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    int *ilist;
    int i, size1, size2;

    printf("Number of letters in word: ");
    scanf("%d", &size1); /* user inputs an integer */
    printf("Number of integers: ");
    scanf("%d", &size2); /* user inputs an integer */

    // Allocate memory with the fixes
    str = (char *) malloc(size1 + 1); // +1 for null terminator
    ilist = (int *) malloc(size2 * sizeof(int)); // sizeof(int) * size2 for integer array

    if (str == NULL || ilist == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    printf("Word: ");
    scanf("%s", str); /* user inputs a string */

    for (i = 0; i < size2; i++) {
        printf("Number %d of %d: ", i + 1, size2);
        scanf("%d", ilist + i); /* user inputs an integer */
    }

    // Free allocated memory
    free(str);
    free(ilist);

    return 0;
}
