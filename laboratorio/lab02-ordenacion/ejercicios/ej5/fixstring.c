#include <stdbool.h>
#include <assert.h>
#include "fixstring.h"

/* Counts the number of characters that compose a given string. */
unsigned int fstring_length(fixstring s) {
    int counter = 0;

    for(int length = 0; s[length] != '\0'; length++) {
        counter = counter + 1;
    }
    return counter;
}

/* Verifies that two entered strings are equal. */
bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int s1_size, s2_size;
    bool is_sorted; 
    
    s1_size = fstring_length(s1);
    s2_size = fstring_length(s2);

    /* 
        If both strings have different lengths, they are clearly different from each other. 
        In the case where they have the same length, I iterate over both strings, checking that each character is equal in both. 
    */
    if(s1_size != s2_size) {
        is_sorted = false;
    }
    else {
        for (unsigned int i = 0; i < s1_size; i++) {
            if(s1[i] == s2[i]) {
                is_sorted = true;
            }
            else {
                is_sorted = false;
            }
        }
    }

    return is_sorted;
}

/* Determines whether a string goes before or after another in alphabetical order. */
bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int s1_size = fstring_length(s1);
    unsigned int s2_size = fstring_length(s2);

    for(unsigned int i = 0; i < s1_size; i++) {
        if(i >= s2_size) {
            return false;
        }
        if(s1[i] < s2[i]) {
            return true;
        }
        else if(s1[i] > s2[i]) {
            return false;
        }
    }
    return true;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

/* Swaps the contents of the strings s1 and s2. */
void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;

    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}