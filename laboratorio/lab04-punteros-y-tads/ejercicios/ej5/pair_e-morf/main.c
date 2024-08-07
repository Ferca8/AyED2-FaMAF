#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", pair_first(p), pair_second(p));
}

int main(void) {
    pair_t p, q;
    /* New pair p. */
    p = pair_new(3, 4);
    /* The pair is displayed on the screen. */
    printf("p = ");
    show_pair(p);
    /* New pair q with elements of p swapped. */
    q = pair_swapped(p);
    /* q is displayed. */
    printf("q = ");
    show_pair(q);
    /* p and q are destroyed. */
    p = pair_destroy(p);
    q = pair_destroy(q);
    return EXIT_SUCCESS;
}

