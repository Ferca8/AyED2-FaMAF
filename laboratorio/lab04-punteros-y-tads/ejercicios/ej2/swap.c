#include <stdlib.h>
#include <stdio.h>

void swap(int x, int y) {
    int aux = x;
    x = y;
    y = aux;
}

void swap2(int *x, int *y) {
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;
}

int main() {
    int x,y;
    x = 6;
    y = 4;

    printf("Los valores originales son (%d,%d).\n", x, y);

    swap(x,y);
    printf("Luego del swap sin punteros queda como (%d,%d).\n", x, y);

    x = 6;
    y = 4;

    swap2(&x,&y);
    printf("Luego del swap con punteros queda como (%d,%d).\n", x, y);

    return 0;
}
