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

    printf("The original values are (%d,%d).\n", x, y);

    swap(x,y);
    printf("After the swap WITHOUT pointers, it becomes (%d,%d).\n", x, y);

    x = 6;
    y = 4;

    swap2(&x,&y);
    printf("After the swap WITH pointers, it becomes (%d,%d).\n", x, y);

    return 0;
}
