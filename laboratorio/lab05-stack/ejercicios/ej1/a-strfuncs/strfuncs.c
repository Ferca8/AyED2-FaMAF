#include "strfuncs.h"
#include <stdbool.h>
#include <stdlib.h>

size_t string_length(const char *str) {
  size_t length = 0u;

  for (unsigned int i = 0; str[i] != '\0'; i++) {
    length++;
  }

  return length;
}

char *string_filter(const char *str, char c) {
  unsigned int i = 0u;
  unsigned int j = 0u;
  char *str_filtered = NULL;

  str_filtered = malloc(sizeof(char) * string_length(str) + 1);

  while (str[i] != '\0') {
    if (str[i] != c) {
      str_filtered[j] = str[i];
      j++;
    }
    i++;
  }

  str_filtered[j] = '\0';

  return str_filtered;
}

bool string_is_symmetric(const char *str) {
  unsigned int lft, rgt;
  bool symmetry = true;

  if (string_length(str) == 0 || string_length(str) == 1) {
    symmetry = true;
  } else {
    lft = 0;
    rgt = string_length(str) - 1;

    while (lft <= rgt) {
      if (str[lft] != str[rgt]) {
        symmetry = false;
      }
      lft++;
      rgt--;
    }
  }

  return symmetry;
}
