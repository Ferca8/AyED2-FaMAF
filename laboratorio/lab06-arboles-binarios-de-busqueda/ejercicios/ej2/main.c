#include "string.h"
#include <stdio.h>

int main(){
    string str1 = string_create("hola");
    string str2 = string_create("mundo");

    bool less = string_less(str1,str2); 
    bool equal = string_eq(str1,str2);

    string_dump(str1,stdout);
    printf("\n");
    string_dump(str2,stdout);
    printf("\n");

    (less) ? printf("str1 es menor que str2.\n") : printf("str2 es menor que str1.\n");
    (equal) ? printf("str1 es igual a str2.\n") : printf("Los strings son diferentes.\n");

    str1 = string_destroy(str1);
    str2 = string_destroy(str2);

    return 0;
}