/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {
    int* p = NULL;
    char* q = NULL;
    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    /* Completar aquí:
       Al finalizar la ejecución las variables deben tener los siguientes valores
       x = 9
       m = (100, F)
       a[1] = 42

       Las restricciones son:
       - No usar las variables 'x', 'm' y 'a' en la parte izquierda de alguna asignación.
       - Se pueden agregar líneas de código, pero no modificar las que ya existen.
       - Se pueden declarar hasta 2 punteros.
       AYUDA: podes usar GDB para consultares valores de variables y la dirección de memoria donde estan alojadas.
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
      Otra forma de hacerlo, haciendo un puntero de tipo person_t en vez de otro puntero de tipo char solo para ver el género.
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

