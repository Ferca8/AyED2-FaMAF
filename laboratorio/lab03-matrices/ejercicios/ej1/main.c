#include <stdlib.h>
#include <stdio.h>
#include "aux_funcs.h"

#define MAX_SIZE 1000

/* Function responsible for dumping or displaying the array. */
static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
    filepath = parse_filepath(argc, argv);

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = 0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    length = data_from_file(filepath, indexes, letters, MAX_SIZE);

    sort(letters, indexes, sorted, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

