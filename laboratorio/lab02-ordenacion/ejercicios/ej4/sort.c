#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* -------------------------------- SELECTION SORT -------------------------------- */
/* Application of the selection sort algorithm seen in the theoretical class with slight modifications to adapt it to C. 
It uses the goes_before function as the sorting criterion, arranging the elements from smallest to largest based on their absolute value. */
static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}

/* -------------------------------- INSERTION SORT -------------------------------- */
/* Application of the insertion sort algorithm seen in the theoretical class with slight modifications to adapt it to C. 
It uses the goes_before function as the sorting criterion, arranging the elements from smallest to largest based on their absolute value. */
static void insert(int a[], unsigned int i) {
    unsigned int j = i;

    while(j > 0 && goes_before(a[j], a[j-1])) {
        swap(a,j-1,j);
        j = j-1;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a,i));
        insert(a, i);
    }
}

/* -------------------------------- QUICK SORT -------------------------------- */
/* Application of the quick sort algorithm seen in the theoretical class with slight modifications to adapt it to C. 
It uses the goes_before function as the sorting criterion, arranging the elements from smallest to largest based on their absolute value. */
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
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}