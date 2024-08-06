/* Whenever creating a .h library, it is recommended to use ifndef and define to avoid the issue of double definition of certain types. */
#ifndef ARRAY_HELPERS_H  
#define ARRAY_HELPERS_H

/* Use my own library. */
#include "mybool.h" 

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath); 

void array_dump(int a[], unsigned int length);

mybool array_is_sorted(int a[], unsigned int length);

#endif
