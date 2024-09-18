#include "btest.h"
#include <limits.h>

info_struct info =
{
   /* Replace with your full name */
   
   "Abdullah Al Asif",
   /* Replace with your login ID */
   "2022521460130",
};

#if 0

#endif

int bitAnd(int x, int y) {
    /*create the AND gate using NOT and OR gate*/
    return ~((~x) | (~y));
}

int bitOr(int x, int y) {
    /*create the OR gate using NOT and AND*/
    return ~((~x) & (~y));
}

int isZero(int x) {
    /*exploite the OR gate to determine if a int is 0 or not*/

    return !(x | 0);  
}

