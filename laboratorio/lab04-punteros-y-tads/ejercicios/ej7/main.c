/* First, the standard lib includes, alphabetically ordered. */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered. */
#include "array_helpers.h"
#include "list.h"

/* Maximum allowed length of the array. */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Compute average for the list of numbers in file.\n"
           "\n",
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

    return (result);
}


float average(list l) {
    int size = length(l);
    float elem = 0, r = 0;
    list laux = copy_list(l);

    while(!is_empty_list(laux)) {
        elem = head(laux);
        r += elem;
        laux = tail(laux);
    }
    destroy_list(laux);
    r = r / size;
    return r;
}

list array_to_list(int array[], unsigned int length) {
    /* Initialize the list. */
    list l = empty_list();

    for (unsigned int i = 0u; i < length; ++i) {
        /* Add element to the list. */
        l = addr(l,array[i]);
    }
    /* Return list. */
    return l;
}


int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* Parse the filepath given in command line arguments. */
    filepath = parse_filepath(argc, argv);

    /* Create an array of MAX_SIZE elements. */
    int array[MAX_SIZE];

    /* Parse the file to fill the array and obtain the actual length. */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* Show the array in the screen. */
    array_dump(array, length);

    /* Transform from array to our list type. */
    list l = array_to_list(array, length);

    /* Show the list in the screen. */
    list_dump(l);

    /* Call the average function. */
    printf("\nThe average is: %.2f \n", average(l));

    return (EXIT_SUCCESS);
}