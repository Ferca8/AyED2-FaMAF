/* First, the standard lib includes, alphabetically ordered. */
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

unsigned int array_from_file(int array[],
                             unsigned int array_size) {
                          
    /* Variable declarations. */
    array_size = array_size;
    int number_read_from_scanf, counter = 0;
    int length;
    
    /* Creation of the file pointer. Instead of opening a file, my file handler is stdin. */
    FILE *registry;
    registry = stdin;
    
    /* Requests the array size from the user, verifying that the value is positive and less than MAX_SIZE. */
    printf("Enter the size of the array (make sure to enter a positive value): ");
    fscanf(registry,"%d", &length);
	
    if(length > MAX_SIZE) {
    	printf("Error: The array exceeds the possible element limit, which is %d. Enter a smaller value.\n", MAX_SIZE);
    	exit(EXIT_FAILURE);
    }
    if(length < 0) {
    	printf("Error: The array cannot have a 'negative size'. Enter a positive value.\n");
    	exit(EXIT_FAILURE);
    }
    
    /* If 0 < length <= MAX_SIZE, it prompts the user for each element of the array. The loop reads the given integers until the specified maximum length is reached, and stores them in an array. If length == 0, it simply returns an empty list without prompting for any elements. */
    if(length == 0) {
    	return 0;
    }
    else {
    	printf("Enter each of the elements that make up the array:\n");
    	while(counter < length) {
    	    fscanf(registry, "%d", &number_read_from_scanf);
            array[counter] = number_read_from_scanf;
            counter++;
        }
    }
    
    /* Closing the file. */
    fclose(registry);
    
    return length;	
}

void array_dump(int a[], unsigned int length) {
    printf("[");
    
    for(unsigned int i = 0; i < length; i++) {
        printf("%d, ", a[i]);
    }
    
    if(length > 0) {
        printf("\b\b]\n");
    } 
    else {
        printf("]\n");
    }
}


int main() {
    /* Create an array of MAX_SIZE elements. */
    int array[MAX_SIZE];
    
    /* Parse the file to fill the array and obtain the actual length. */
    unsigned int length = array_from_file(array, MAX_SIZE);
    
    /* Dumping the array. */
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
