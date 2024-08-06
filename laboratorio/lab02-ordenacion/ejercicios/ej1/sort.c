#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* Application of the insertion sort algorithm seen in the theoretical class with slight modifications to adapt it to C. */
static void insert(int a[], unsigned int i) {
    unsigned int j = i;

    while(j > 0 && goes_before(a[j], a[j-1])) {
        swap(a,j-1,j);
        j = j-1;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a, i));
        insert(a, i);
    } 
}