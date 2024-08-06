/* Added the function array_reverse, which includes the function array_swap, to reverse the elements of the array. */
#include "array_helpers.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array. */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
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
    /* Program takes exactly two arguments (the program's name itself and the input-filepath) */
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
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

    /* Reversing the array. */
    array_reverse(array, length);

    /* Dumping the array. */
    array_dump(array, length);
    
    /* Printing if the array is sorted or not. */
    if(array_is_sorted(array, length) == 1) {
    	printf("The array is sorted.\n");
    }
    else {
    	printf("The array is not sorted.\n");
    }
    
    return EXIT_SUCCESS;
}
