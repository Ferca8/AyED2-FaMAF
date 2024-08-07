#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NAME: %s\n"
           "AGE  : %d years\n"
           "HEIGHT: %d cm\n\n",
           d.name, d.age, d.height);
}

void print_data2(data_t *d) {
    printf("NAME: %s\n    Address: %p\n    Size: %lu\n"
           "AGE  : %d years\n    Address: %p\n    Size: %lu\n"
           "HEIGHT: %d cm\n    Address: %p\n    Size: %lu\n",
           d->name, (void *) &d->name, sizeof(d->name), 
           d->age, (void *) &d->age, sizeof(d->age),
           d->height, (void *) &d->height , sizeof(d->height));
    printf("The sum of the sizes of name, age, and height is %lu\n", sizeof(d->name)+sizeof(d->age)+sizeof(d->height));
    printf("Total size of the structure: %lu\n", sizeof(data_t));
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    print_data2(&messi);
    return EXIT_SUCCESS;
}

