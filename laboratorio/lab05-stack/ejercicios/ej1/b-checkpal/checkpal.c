#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 20 //20 es el valor original, ¿lo cambio por 50 para tomar a los casos de los archivos?

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.', '\n'};
    char *filtered=NULL;

    // Lee la entrada del usuario
    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);
    fgets(user_input, MAX_LENGTH, stdin);

    /* Esta llamada crea una nueva cadena 'filtered' que es una copia del 'user_input' leído por fgets.
    O sea, crea una copia de la cadena entregada. Aparte de ello ignora el primer elemento de ignore_chars,
    es decir, el espacio. Quiere decir que luego de la ejecución de esta instrucción se formará la cadena sin
    ningún espacio (con pal3.in se visualizaría "larutanatural.") */ 
    filtered = string_filter(user_input, ignore_chars[0]);

    /* Ciclo que hace exactamente lo mismo que la anterior: Copia la cadena resultante y busca caracteres
    no deseados para filtrar. En el caso de "larutanatural.", cuando i = 5 se borra el punto final que tiene
    quedando formada "larutanatural" y estando lista para ver su simetría. A medida que se busca un elemento
    con el puntero p se va liberando memoria. */
    for (unsigned int i=0; i < SIZEOF_ARRAY(ignore_chars); i++) {
        char *p = filtered;
        filtered = string_filter(filtered, ignore_chars[i]);
        free(p);
    }

    // Verificar si la cadena resultante es un palíndromo y mostrar el resultado
    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");

    // Liberar memoria
    free(filtered);
    
    return EXIT_SUCCESS;
}

