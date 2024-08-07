/*
  @file main.c
  @brief Main program function implementation.
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person. */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function.
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise.
 */
int main(void) {
    int* p = NULL;
    char* q = NULL;
    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    /* 
        Complete here:
            At the end of execution, the variables must have the following values:
            x = 9
            m = (100, F)
            a[1] = 42

            The restrictions are:
            - Don't use the variables 'x', 'm', and 'a' on the left side of any assignment.
            - You can add lines of code, but do not modify the existing ones.
            - Up to 2 pointers can be declared.
            HELP: You can use GDB to check variable values and the memory addresses where they are stored.
    */
    p = &x;
    *p = 9;
    printf("x = %d\n", x);

    p = &m.age;
    *p = 100;
    q = &m.name_initial;
    *q = 'F';
    printf("m = (%d, %c)\n", m.age, m.name_initial);

    /*
        Another way to do it, using a pointer of type person_t instead of another pointer of type char just to see the gender.
            person_t* t = NULL;
            t = &m;
            (*t)->age = 100;
            (*t)->name_initial = 'F'
    */

    p = &a[1];
    *p = 42;
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

