#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "counter.h"


struct _counter {
    unsigned int count;
};


counter counter_init(void) {
    counter c = NULL;
    c = malloc(sizeof(counter)); //sizeof(struct _counter)
    c->count = 0;
    return c;
}
/*
    Create a new counter with initial value. Allocates new memory.
    Being c the returned counter, counter_is_init(c) should be true.
*/


void counter_inc(counter c) {
    c->count = c->count+1;
}
/*
    Increments the counter c.
*/


bool counter_is_init(counter c) {
    return(c->count == 0); // return(c->count == 0 || c == NULL)
}
/*
    Return whether the counter c has the initial value.
*/


void counter_dec(counter c) {
    assert(!counter_is_init(c));

    c->count = c->count-1;
}
/*
    Decrements the counter c.
    PRECONDITION: !counter_is_init(c)
*/

counter counter_copy(counter c) {
    counter copy = NULL;
    copy = malloc(sizeof(counter)); //sizeof(struct _counter)
    
    copy->count = c->count;

    return copy;
}
/*
    Makes a copy of counter c. Allocates new memory.
*/


void counter_destroy(counter c) {
    free(c);
    c = NULL;
}
/*
   Frees memory for c.
*/