#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_SIZE 7

static void
print_array(int a[], size_t length) {
    assert(length > 0);
    printf("[ %d", a[0]);
    for (size_t i=1; i<length; i++) {
        printf(", %d", a[i]);
    }
    printf("]\n");
}

int main(void) {
    int arr[ARRAY_SIZE] = {7, 4, 1, 3, 9, 3, 5};
    int *p = NULL;
    printf("Before: ");
    print_array(arr, ARRAY_SIZE);
    /* ---------------------------- REWRITING ---------------------------- */
    //
    // You can add things before the for loop if necessary.
    //
    for (unsigned int i = 0u; i < ARRAY_SIZE; i++) {
        p = arr;        // FIXME: The operator & is used.
        p[i] = 0;       // FIXME: The operator * is used.
    }
    /* -------------------------------------------------------------------- */
    printf("After : ");
    print_array(arr, ARRAY_SIZE);

    return EXIT_SUCCESS;
}