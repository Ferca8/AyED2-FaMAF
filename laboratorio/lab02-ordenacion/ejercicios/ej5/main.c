/* First, the standard lib includes, alphabetically ordered. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered. */
#include "array_helpers.h"
#include "fixstring.h"
#include "sort_helpers.h"
#include "sort.h"

/* Maximum allowed length of the array. */
static const unsigned int MAX_SIZE = 1000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* Parse the filepath given in command line arguments. */
    filepath = parse_filepath(argc, argv);

    /* Create an array of MAX_SIZE elements. */
    fixstring array[MAX_SIZE];

    /* Parse the file to fill the array and obtain the actual length. */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* Create a copy of the array, to do some checks later. */
    fixstring copy[MAX_SIZE];
    array_copy(copy, array, length);

    /* 
        Implementation of the quick_sort_alphabetical function, which uses the goes_before_alphabetical function as the sorting criterion, a modification of goes_before from previous exercises. 
        It shows the sorted array and verifies that it is ordered alphabetically. 
    */
    printf("Array sorted alphabetically (quick_sort_alphabetical):\n");
    quick_sort_alphabetical(array, length);
    array_dump(array, length);
    assert(array_is_sorted_alphabetical(array, length));

    /* 
        Implementation of the quick_sort_bylength function, which uses the goes_before_bylength function as the sorting criterion, a modification of goes_before from previous exercises. 
        It shows the sorted array and verifies that it is ordered by length. 
    */
    printf("\nArray sorted by word length (quick_sort_bylength):\n");
    quick_sort_bylength(array, length);
    array_dump(array, length);
    assert(array_is_sorted_bylength(array, length));

    /* Check if it is a permutation of original. */
    assert(array_is_permutation_of(copy, array, length));
    return EXIT_SUCCESS;
}