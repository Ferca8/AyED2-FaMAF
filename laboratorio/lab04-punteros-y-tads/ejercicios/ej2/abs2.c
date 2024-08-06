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
    int a = -10, res = 0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---

    absolute(a, &res);

    printf("El valor absoluto de %d es %d.\n", a, res);

    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/* 
    Ahora la función sí tiene la funcionalidad del teórico/práctico mediante la utilización de punteros.
    Al ejecutar absolute ya el valor no se "pierde", si no que queda alojado en una dirección de memoria para
    luego ser traído al momento de printear los valores, habiendo cambiado el contenido de la variable res.
*/

/* 
    2.c) El parámetro int *y de absolute() es de tipo in/out.
*/

