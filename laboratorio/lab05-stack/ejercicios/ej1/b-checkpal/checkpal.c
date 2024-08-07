#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 20 /* 20 is the original value. Should I change it to 50 to consider the cases from the files? */

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.', '\n'};
    char *filtered=NULL;

    /* Read the user's input */
    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);
    fgets(user_input, MAX_LENGTH, stdin);

    /* 
        This call creates a new string 'filtered', which is a copy of the 'user_input' read by fgets.
        In other words, it makes a copy of the given string. Additionally, it ignores the first element of ignore_chars,
        which is the space. This means that after executing this instruction, the string will be formed without
        any spaces (with pal3.in, it would be displayed as 'larutanatural.').
    */ 
    filtered = string_filter(user_input, ignore_chars[0]);

    /* 
        A loop that does exactly the same as before: it copies the resulting string and searches for 
        unwanted characters to filter out. In the case of 'larutanatural.', when i = 5, the final point is removed,
        leaving 'larutanatural' ready to be checked for symmetry. As each unwanted element is found
        with the pointer p, memory is freed.
    */
    for (unsigned int i=0; i < SIZEOF_ARRAY(ignore_chars); i++) {
        char *p = filtered;
        filtered = string_filter(filtered, ignore_chars[i]);
        free(p);
    }

    /* Check if the resulting string is a palindrome and display the result. */
    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");

    /* Free memory. */
    free(filtered);
    
    return EXIT_SUCCESS;
}

