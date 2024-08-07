#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    // COMPLETE

    /* Initialization of the structure. */
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = 0;

    for(unsigned int i = 0; i < length; i++) {
        /* Check if the element is an upper bound. */
        res.is_upperbound = (value >= arr[i]) && res.is_upperbound;

        /* Check if the element is an lower bound. */
        res.is_lowerbound = (value <= arr[i]) && res.is_lowerbound;

        /* Check if the element belongs to the array. */
        if(value == arr[i]) {
            res.exists = true;
            res.where = i;
        }
    }

    // COMPLETE 
    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value;
    unsigned int size;
    // COMPLETE - Request input from the user .

    /* Ask the user for the size of the array they want. */
    printf("Enter the length of the array: ");
    scanf("%u", & size);
    printf("\n");

    /* Ask the user for each element of the array. */
    for(unsigned int i = 0; i < size; i++) {
        printf("Enter the value for position %d: ", i);
        scanf("%d", &a[i]);
    } 

    /* Print the array. */
    printf("\nThe entered array is: [");
    for (unsigned int i = 0; i < size-1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d]\n\n", a[size-1]);

    /* Ask the user for the value to compare. */
    printf("Enter the value to compare: ");
    scanf("%d", &value);
    printf("\n");

    // COMPLETE - Request input from the user.

    struct bound_data result = check_bound(value, a, size);

    // ALL: REPLACE THE FOLLOWING WITH THE OUTPUT REQUESTED BY THE EXERCISE.

    result.exists ? printf("The value %d exists in the array at position %d.\n", value, result.where) : printf("The value %d doesn't exist in the array.\n", value);
    result.is_upperbound ? printf("The value %d is an upper bound for all elements in the array.\n", value) : printf("The value isn't an upper bound.\n");
    result.is_lowerbound ? printf("The value %d is an lower bound for all elements in the array.\n", value) : printf("The value isn't an lower bound.\n");

    // ALL: REPLACE THE FOLLOWING WITH THE OUTPUT REQUESTED BY THE EXERCISE.

    return EXIT_SUCCESS;
}