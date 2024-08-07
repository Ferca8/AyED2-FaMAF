#include <stdio.h>
#include <stdlib.h>

#include "fixstring.h"

#define N_WORDS 4

int main(void) {
    fixstring words[N_WORDS]={"hola", "mundo", "auto","automovil"};

    printf("Testing fstring_length()\n"
           "-------------------------\n\n");

    for (int i=0; i < N_WORDS; i++) {
        printf("The length of '%s' is %u.\n",
                words[i],
                fstring_length(words[i]));
    }

    printf("\n"
           "Testing fstring_eq() and fstring_less_eq()\n"
           "-----------------------------------------\n\n");

    for (int i=0; i < N_WORDS; i++) {
        for (int j=0; j < N_WORDS; j++) {
            if (fstring_eq(words[i], words[j])) {
                printf("The strings '%s' and '%s' are identical.\n",
                        words[i], words[j]);
            }
            else {
                printf("The string '%s' comes %s '%s' alphabetically.\n", 
                   words[i],
                   fstring_less_eq(words[i], words[j]) ? "before": "after",
                   words[j]);
            }
            
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}