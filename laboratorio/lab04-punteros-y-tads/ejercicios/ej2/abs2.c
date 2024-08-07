#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if(x >= *y) {
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a = -10, res = 0;  // Don't modify this declaration
    // --- No new variables should be declared ---

    absolute(a, &res);

    printf("The absolute value of %d is %d.\n", a, res);

    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/* 
    Now the function does have the theoretical/practical functionality through the use of pointers.
    When executing absolute, the value no longer gets 'lost'; instead, it remains stored at a memory address
    and is later retrieved when printing the values, having changed the content of the res variable.
*/

/* 
    2.c) The parameter int *y of absolute() is of type in/out.
*/

