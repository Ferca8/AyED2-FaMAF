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

    printf("The absolute value of %d is %d.\n", a, res);
    return EXIT_SUCCESS;
}
/* 
    It is shown that the absolute value of -10 is 0. This clearly does not match the theoretical language because, although it calls 
    the absolute function, it seems that it does not bring the values obtained from that function and only maintains the assignments located in main.

    The execution of abs1 occurs as follows:
        - Load 'main'
            - Assignments
            - 'absolute' function
                The absolute function is executed and falls within a case of the guard, but since it is void and does not return
                anything, the value is "lost," so to speak. I return to main. 
            - printf
            - return
        - End of 'main' execution

    Another way to explain the situation (in other words) is that absolute uses copies of the parameters x and y (not the originals).
*/