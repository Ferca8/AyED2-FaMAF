#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if(x >= y) {
        y = x;
    } else {
        y = -x;
    }
}

int main(void) {
    int a = -10, res = 0;
    
    absolute(a, res);

    printf("El valor absoluto de %d es %d.\n", a, res);
    return EXIT_SUCCESS;
}
/* 
    Se muestra que el valor absoluto de -10 es 0. Esto claramente no coincide con el lenguaje del teórico pues
    si bien llama a la función absolute pareciera ser que no trae los valores obtenidos de dicha función y
    solamente mantiene las asignaciones alojadas en main.
    La ejecución de abs1 ocurre de la siguiente manera:
        - Carga de main
            - Asignaciones
            - Función absolute
                Se ejecuta la función absolute y cae dentro de un caso de la guarda, pero al ser void y no retornar
                nada, el valor se "pierde" por decirlo de una manera. Vuelvo a main. 
            - Printf
            - Return
        - Fin de ejecución de main

    Otra forma de explicar la situación (con otras palabras) es que en absolute se usan copias de los parámetros x e y (no los originales).
*/