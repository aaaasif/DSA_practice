//Determine the memory size of declaration and variable type
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void main() 
{
char c;
char s[512];
short i;
short n[64];
printf("%3d %3d\n", sizeof(c), sizeof(char));
printf("%3d %3d\n", sizeof(s), sizeof(char[512]));
printf("%3d %3d\n", sizeof(i), sizeof(short));
printf("%3d %3d\n", sizeof(n), sizeof(short[64]));
}

