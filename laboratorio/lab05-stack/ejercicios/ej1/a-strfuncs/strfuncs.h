#ifndef _STRFUNCS_H_
#define _STRFUNCS_H_
#include <stdbool.h>
#include <stdlib.h>

size_t string_length(const char *str);
/*
    Calculate the length of the string pointed to by str.
*/

char *string_filter(const char *str, char c);
/*
    Returns a new dynamically allocated string that consists of the characters from str 
    that are different from the character c.
*/

bool string_is_symmetric(const char *str);
/*
    Indicate if the string pointed to by str is symmetrical in the sense that the first character matches the
    last, the second matches the second-to-last, and so on.
*/

#endif