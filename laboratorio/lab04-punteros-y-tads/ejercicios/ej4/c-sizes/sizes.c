#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

void print_data2(data_t *d) {
    printf("NOMBRE: %s\n    Dirección: %p\n    Tamaño: %lu\n"
           "EDAD  : %d años\n    Dirección: %p\n    Tamaño: %lu\n"
           "ALTURA: %d cm\n    Dirección: %p\n    Tamaño: %lu\n",
           d->name, (void *) &d->name, sizeof(d->name), 
           d->age, (void *) &d->age, sizeof(d->age),
           d->height, (void *) &d->height , sizeof(d->height));
    printf("La suma de los tamaños de nombre, edad y altura son %lu\n", sizeof(d->name)+sizeof(d->age)+sizeof(d->height));
    printf("Tamaño total de la estructura: %lu\n", sizeof(data_t));
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    print_data2(&messi);
    return EXIT_SUCCESS;
}

