#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* Application of the quick sort algorithm seen in the theoretical class with slight modifications to adapt it to C. 
In this case, a substantial difference from the theoretical class is the way it sorts partition: here it uses, as in previous exercises, the goes_before function to establish the order. */
static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int i,j,pivot;
    pivot = izq;
    i = izq+1;
    j = der;

    while(i <= j) {
        if(goes_before(a[i], a[pivot])){
            i = i+1;
        }
        else if(goes_before(a[pivot], a[j])) {
            j = j-1;
        }
        else if(goes_before(a[pivot], a[i]) && goes_before(a[pivot], a[i])) {
            swap(a,i,j);
            i = i+1;
            j = j-1;
        }
    }

    swap(a,j,pivot);
    pivot = j;

    return pivot;
}

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
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}