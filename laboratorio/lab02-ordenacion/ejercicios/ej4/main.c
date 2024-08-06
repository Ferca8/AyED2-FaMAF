/* First, the standard lib includes, alphabetically ordered. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered. */
#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* Maximum allowed length of the array. */
static const unsigned int MAX_SIZE = 100000u;

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
    int array[MAX_SIZE];

    /* Parse the file to fill the array and obtain the actual length. */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* Create a copy of the array. */
    int copy[MAX_SIZE];
    array_copy(copy, array, length);

    /* ---------------------- SELECTION SORT ---------------------- */

    /* Reset counters and set time. */
    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();

    /* Do selection_sort. */
    selection_sort(copy, length);

    /* Show statistics for selection_sort. */
    printf("Statistics for selection_sort\n");
    printf("| Time elapsed = %g   | Comparisons: %10u   | Swaps: %10u   |\n\n", calculate_elapsed_time(), comparisons_number(), swaps_number());


    /* ---------------------- INSERTION SORT ---------------------- */

	/* Append the copy of the original array. */
    array_copy(copy, array, length);
    
    /* Reset counters and set time. */
    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();

    /* Do insertion_sort. */
    insertion_sort(copy, length);

    /* Show statistics for insertion_sort. */
    printf("Statistics for insertion_sort\n");
    printf("| Time elapsed = %g   | Comparisons: %10u   | Swaps: %10u   |\n\n", calculate_elapsed_time(), comparisons_number(), swaps_number());


    /* ---------------------- QUICK SORT ---------------------- */

	/* Append the copy of the original array. */
    array_copy(copy, array, length);
    
    /* Reset counters and set time. */
    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();

    /* Do quick_sort. */
    quick_sort(copy, length);

    /* Show statistics for quick_sort. */
    printf("Statistics for quick_sort\n");
    printf("| Time elapsed = %g   | Comparisons: %10u   | Swaps: %10u   |\n\n", calculate_elapsed_time(), comparisons_number(), swaps_number());

    return EXIT_SUCCESS;
}
