#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"

/* 
    Application of the quick sort algorithm seen in the theoretical class with slight modifications to adapt it to C. 
    It uses the goes_before function as the sorting criterion with a slight modification compared to previous exercises. 
    I make two different implementations: one for quick sort based on alphabetical order (goes_before_alphabetical) and another based on string length (goes_before_bylength). 
*/

// ---------------------------- QUICK SORT ALPHABETICAL ----------------------------
static unsigned int partition_alphabetical(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int i,j,pivot;
    pivot = izq;
    i = izq+1;
    j = der;

    while(i <= j) {
        if(goes_before_alphabetical(a[i], a[pivot])){
            i = i+1;
        }
        else if(goes_before_alphabetical(a[pivot], a[j])) {
            j = j-1;
        }
        else if(goes_before_alphabetical(a[pivot], a[i]) && goes_before_alphabetical(a[pivot], a[i])) {
            swap(a,i,j);
            i = i+1;
            j = j-1;
        }
    }

    swap(a,j,pivot);
    pivot = j;

    return pivot;
}

static void quick_sort_rec_alphabetical(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int pivot;
    
    if(der > izq) {
        pivot = partition_alphabetical(a, izq, der);

        /* Since the pivot type is unsigned int, I cannot define pivot-1 as in the theoretical case, because if pivot=0, then pivot-1 would be -1, which goes out of the array. */
        quick_sort_rec_alphabetical(a, izq, (pivot == 0u) ? 0u : pivot - 1u);
        quick_sort_rec_alphabetical(a, pivot+1, der);
    }
}

void quick_sort_alphabetical(fixstring a[], unsigned int length) {
    quick_sort_rec_alphabetical(a, 0, (length == 0) ? 0 : length - 1);
}

// ---------------------------- QUICK SORT BYLENGTH ----------------------------
static unsigned int partition_bylength(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int i,j,pivot;
    pivot = izq;
    i = izq+1;
    j = der;

    while(i <= j) {
        if(goes_before_bylength(a[i], a[pivot])){
            i = i+1;
        }
        else if(goes_before_bylength(a[pivot], a[j])) {
            j = j-1;
        }
        else if(goes_before_bylength(a[pivot], a[i]) && goes_before_bylength(a[pivot], a[i])) {
            swap(a,i,j);
            i = i+1;
            j = j-1;
        }
    }

    swap(a,j,pivot);
    pivot = j;

    return pivot;
}

static void quick_sort_rec_bylength(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int pivot;
    
    if(der > izq) {
        pivot = partition_bylength(a, izq, der);

        /* Since the pivot type is unsigned int, I cannot define pivot-1 as in the theoretical case, because if pivot=0, then pivot-1 would be -1, which goes out of the array. */
        quick_sort_rec_bylength(a, izq, (pivot == 0u) ? 0u : pivot - 1u);
        quick_sort_rec_bylength(a, pivot+1, der);
    }
}

void quick_sort_bylength(fixstring a[], unsigned int length) {
    quick_sort_rec_bylength(a, 0, (length == 0) ? 0 : length - 1);
}
