#include <stdlib.h>  
#include <stdio.h>   
#include "pair.h"    

pair_t pair_new(int x, int y) {
    pair_t par;
    par.values[0] = x;
    par.values[1] = y;

    return par;
}
/*
 * DESC: Creates a new pair with components (x, y).
 *
 * p = pair_new(x, y);
 *
 * POS: {p --> (x, y)}
 */

int pair_first(pair_t p) {
    return p.values[0];
}
/*
 * DESC: Returns the first component of p.
 *
 * PRE: {p --> (x, y)}
 *
 *  fst = pair_first(p);
 *
 * POS: {fst == x}
 */

int pair_second(pair_t p) {
    return p.values[1];
}
/*
 * DESC: Returns the second component of p.
 *
 * PRE: {p --> (x, y)}
 *
 *  snd = pair_second(p);
 *
 * POS: {snd == y}
 */

pair_t pair_swapped(pair_t p) {
    pair_t par;
    par = pair_new(p.values[1], p.values[0]);

    return par;
}
/*
 * DESC: Return a NEW pair with the components of p reversed.
 *
 * PRE: {p --> (x, y)}
 *
 *  q = pair_swapped(p)
 *
 * POS: {pair_first(q) == pair_second(p) && pair_second(q) == pair_first(p)}
 *
 */

pair_t pair_destroy(pair_t p) {
    //skip
    return p;
}
/*
 * DESC: Free memory if its necesary.
 *
 */