#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* Application of the quick sort algorithm seen in the theoretical class with slight modifications to adapt it to C. */
static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int pivot;
    
    if(der > izq) {
        pivot = partition(a, izq, der);

        /* Since the pivot type is unsigned int, I cannot define pivot-1 as in the theoretical case, because if pivot=0, then pivot-1 would be -1, which goes out of the array. */
        quick_sort_rec(a, izq, (pivot == 0u) ? 0u : pivot - 1u);
        quick_sort_rec(a, pivot+1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}