#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *parse_filepath(int argc, char *argv[]) {
    /* 
        Parse the filepath given by command line argument. 
        Brought from exercise 1 of lab 1 with slight modifications (without the print_help function). 
    */
    char *result = NULL;

    if (argc < 2) {
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int data_from_file(const char *path,
                             unsigned int indexes[],
                             char letters[],
                             unsigned int max_size) {
                          
    /* Variable declarations. */
    unsigned int length = 0u;
    
    /* Creation of the file pointer and opening of this file. Also checks whether the file address exists or not. */
    FILE *registry;
    registry = fopen(path, "r");
    
    if(path == NULL) {
    	printf("Error: File does not exist.\n");
    	exit(EXIT_FAILURE);
    }
    
    /* Reading the array until the end of its elements from the file (EOF). */
    while(length < max_size && !feof(registry)) {
        
        /* As the elements of the program are read, they are stored in two arrays: one for the indexes and another for the letters that make up the file (including spaces and punctuation marks). */
        fscanf(registry,"%u -> *%c*\n", &indexes[length], &letters[length]);

        /* The indexes are checked to ensure they do not exceed the maximum allowed size, in this case, 1000. If they do, the program stops. */
        if(indexes[length] > max_size)  {
            printf("Error: The array exceeds the maximum element limit.\n");
            exit(EXIT_FAILURE);
        }
        length++;
    }

    /* Closing the file. */
    fclose(registry);
    
    return length;	
}

void sort(char letters[], unsigned int indexes[], char sorted[], unsigned int lenght) {
    /* 
        Basically, 'sort' rearranges the letters in the letters[] array and places them in the sorted[] array according to the indices provided in the indexes[] array, going from index 0 to the end. 
        The values of letters[] array and indexes[] array were reading in 'data_from file' previously. 
    */
    for(unsigned int i = 0; i < lenght; i++) {
        sorted[indexes[i]] = letters[i];
    }
}
