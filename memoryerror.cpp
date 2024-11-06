#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    char *str1, *str2;
};

/* returns two strings concatenated if they are not the same, NULL otherwise */
char *mergeSingleIfDifferent(char *s1, char *s2) {
    char *str = (char *) malloc(strlen(s1) + strlen(s2) + 1);
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    if (strcmp(s1, s2) == 0) { /* strings are equal */
        free(str); // Free the allocated memory before returning NULL
        return NULL;
    } else {
        strcpy(str, s1);
        strcat(str, s2);
    }
    return str;
}

/* copies merged strings (or NULL) into array of strings passed in (results) */
void mergeArrayIfDifferent(char *results[], char *strA1[], char *strA2[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        results[i] = mergeSingleIfDifferent(strA1[i], strA2[i]);
    }
}

void printAndFree(int c, char *str) {.,
    if (str != NULL) {
        printf("%d: %s\n", c, str);
        free(str); // Free memory after printing
    }
}

int main() {
    char *strArr1[8] = {"1", "2", "3", "4", "5", "6", "7", "8"};
    char *strArr2[8] = {"a", "2", "c", "4", "e", "6", "g", "8"};
    char *results[8];
    int i;

    mergeArrayIfDifferent(results, strArr1, strArr2, 8);

    for(i = 0; i < 8; i++) {
        printAndFree(i, results[i]);
    }

    return 0;
}


void Test(void)
{ 
    char *str = (char *)malloc(100); 
    strcpy(str, " hello"); 
    free(str); 
    if(str != NULL)
    { 
        strcpy(str, " world"); 
        printf(str);
    }
}

