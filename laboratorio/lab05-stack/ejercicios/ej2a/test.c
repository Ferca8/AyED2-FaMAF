#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main() {
    printf("- Does stack_pop() work well for size 1 stacks?\n");
    stack s = stack_empty();    // Create an stack.
    s = stack_push(s,6);     // Push an element on the stack, making an size 1 stack.
    s = stack_pop(s);          // Pop the only element of the stack.

    // Check if the stack is indeed null or not.
    if(s == NULL) {
        printf("The stack is empty, no problem.\n");
    } else {
        printf("Error: The stack is not empty when it should be.\n");
        exit(EXIT_FAILURE);
    }

    printf("\n- If the stack becomes empty, can I reinsert elements?\n");
    s = stack_push(s,9);    // Use the same stack and push a new element. In theory, s is NULL.

    // Check if the element was pushed or not.
    if(s != NULL) {
        printf("A new element was successfully pushed into the previously created empty stack without problems.\n");
    } else {
        printf("Error: The element wasn't pushed.\n");
        exit(EXIT_FAILURE);
    }

    stack_destroy(s);
    
    printf("\n- Does the stack_to_array() function return NULL for an empty stack?\n");
    stack q = stack_empty();    // Use the same stack and push a new element. In theory, s is NULL.
    stack_elem* array = stack_to_array(q);

    // Check if the element was pushed or not.
    if(array == NULL) {
        printf("Yes, stack_to_array() return NULL for an empty stack.\n");
    } else {
        printf("Error: An empty stack doesn't return NULL with stack_to_array().\n");
        exit(EXIT_FAILURE);
    }

    printf("\n- Does it return the elements in the correct order?\n");
    q = stack_push(q, 1);
    q = stack_push(q, 2);
    q = stack_push(q, 3);
    array = stack_to_array(q);
    if(array[0] == 1 && array[1] == 2 && array[2] == 3) {
        printf("Yes, the order is correct.\n");
    } else {
        printf("Error: Stack order is not respected.\n");
        exit(EXIT_FAILURE);
    }
    
    free(array);
    stack_destroy(q);
}