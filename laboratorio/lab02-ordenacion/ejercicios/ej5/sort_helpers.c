#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "fixstring.h"

void swap(fixstring a[], unsigned int i, unsigned int j) {
    fstring_swap(a[i], a[j]);
}

// ---------------------- GOES BEFORE ----------------------
/* Implementation of two goes_before functions, which will be used as sorting criteria in the code. 
goes_before_alphabetical checks whether a word goes before or after another alphabetically. 
goes_before_bylength checks whether a word is shorter or longer than another (based on the number of letters it contains).*/
bool goes_before_alphabetical(fixstring x, fixstring y) {
    bool goes_before;

    goes_before = fstring_less_eq(x,y);

    return goes_before;
}

bool goes_before_bylength(fixstring x, fixstring y) {
    bool goes_before;

    goes_before = fstring_length(x) <= fstring_length(y);

    return goes_before;
}

// ---------------------- ARRAY IS SORTED ----------------------
/* I create two functions that check if the array is sorted. 
One checks using goes_before_alphabetical as the sorting criterion and the other using goes_before_bylength. */
bool array_is_sorted_alphabetical(fixstring array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before_alphabetical(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}

bool array_is_sorted_bylength(fixstring array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before_bylength(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}