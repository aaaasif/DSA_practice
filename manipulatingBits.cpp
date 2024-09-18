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

int minusOne(void) {
    /*return not 0 because in 2nd compliment not 0 is (1 sign bit)111 which is -1*/
    return ~0;
}

int tmax(void) {
    /* /*we take the number 1 and shift it to the left 31 positions
     which results in a bit string that is 11111...1111*/
    return (unsigned int)~(1 << 31);

}

int bitXor(int x, int y) {
    /*uses simple logic gate computation to detemine XOR gate with NOT OR and AND*/
    return ((x & ~y) | (~x & y));
}

int getByte(int x, int n) {
    /* shifts by 8 times the number given then extracts the bytes by anding them with ff which is 1111
    1111 */

    return (x & (0xff << (8 * n)));
}
