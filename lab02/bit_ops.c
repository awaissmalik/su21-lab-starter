#include <stdio.h>
#include "bit_ops.h"
/* Returns the Nth bit of X. Assumes 0 <= N <= 31. */
unsigned get_bit(unsigned x, unsigned n) {
    // Create bit with the Nth bit set to 1
    unsigned bit = 1 << n;
    // Use bit AND to check if the Nth bit is set
    unsigned result = (x & bit) >> n;
    return result;
}

/* Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1 */
void set_bit(unsigned *x, unsigned n, unsigned v) {
	unsigned bit = ( v << n ) ;
	*x = ( *x & (~(1 << n ))) | bit;

}

/* Flips the Nth bit in X. Assumes 0 <= N <= 31.*/
void flip_bit(unsigned *x, unsigned n) {
    // Create a bit with only the Nth bit set to 1
    unsigned bit = 1 << n;   
    // Use bit XOR to flip the Nth bit (0 to 1 or 1 to 0)
    *x = (*x) ^ bit;
}
