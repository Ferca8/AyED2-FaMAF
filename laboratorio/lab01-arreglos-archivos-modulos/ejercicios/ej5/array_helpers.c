#include "array_helpers.h"
#include "mybool.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

unsigned int array_from_file(int array[],
                             unsigned int array_size,
                             const char *filepath) {
                          
    /* Variable declarations. */
    array_size = array_size;
    int number_read_from_scanf, counter = 0;
    int length;
    
    /* Creation of the file pointer and opening of this file. Also checks whether the file address exists or not. */
    FILE *registry;
    registry = fopen(filepath, "r");
    
    if(filepath == NULL){
    	printf("Error: The file does not exist.\n");
    	exit(EXIT_FAILURE);
    }
    
    /* Reading the size of the array, where also it verifies that such size is less than MAX_SIZE = 100000. */
    fscanf(registry,"%d", &length);
	
    if(length > MAX_SIZE){
    	printf("Error: The array exceeds the possible element limit, which is %d. Enter a smaller value.\n", MAX_SIZE);
    	exit(EXIT_FAILURE);
    }
    
    /* This loop reads elements until it reaches the end of the file or until the previously read length is reached, and stores them in an array. */
    while(fscanf(registry, "%d", &number_read_from_scanf) != EOF && counter < length){
        array[counter] = number_read_from_scanf;
        counter++;
    }
    
    /* Verifies that the size of the array and its quantity of elements are equal. */ 
    if(length != counter){
    	printf("Error: The length of the array (%d) does not match the number of elements entered (%d).\n", length, counter);
    	exit(EXIT_FAILURE);
    }
    
    /* Closing the file. */
    fclose(registry);
    
    return length;	
}

void array_dump(int a[], unsigned int length) {
    printf("[");
    
    for(unsigned int i = 0; i < length; i++){
        printf("%d, ", a[i]);
    }
    
    if(length > 0){
        printf("\b\b]\n");
    } 
    else{
        printf("]\n");
    }
}

mybool array_is_sorted(int a[], unsigned int length) {
    mybool sorted = true;
    
    if(length == 0) {
    	return sorted;
    }
    else {
    	for(unsigned int position = 0; position < (length-1); position++) {
    	    sorted = a[position] <= a[(position + 1)] && sorted;
    	}
    	return sorted;
    }
}
