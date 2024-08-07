#include <stdlib.h>
#include <assert.h>
#include "stack.h"

/**
* @brief Stack type definition.
*/
typedef struct _s_stack {
    stack_elem elem;
    struct _s_stack* next;
} node;

/**
* @brief Creates an empty stack.
* @return An empty stack.
*/
stack stack_empty() {
    stack s = NULL;
    return s;
}

/**
* @brief Inserts an element at the top of the stack.
* @param s A stack.
* @param e An element to push into the stack.
* @return The new stack with 'e' at the top.
*/
stack stack_push(stack s, stack_elem e) {
    node* p = NULL;

    p = malloc(sizeof(struct _s_stack));
    p->elem = e;
    p->next = s;

    return p;
}
 
/**
* @brief Removes the element at the top of the stack.
* @param s A stack.
* @return The new stack with the top element removed.
* @note Only applies to non-empty stacks.
*/
stack stack_pop(stack s) {
    assert(!stack_is_empty(s));    /* PRE: not stack_is_empty(s) */
    
    stack t = s;
    s = s->next;
    free(t);

    return s;
}

/**
* @brief Returns the size of the stack.
* @param s A stack.
* @return The size of the stack.
*/
unsigned int stack_size(stack s) {
    unsigned int size = 0u;
    stack p = NULL;

    if(!stack_is_empty(s)) {
        p = s;

        while(p != NULL) {
            size++;
            p = p->next;
        }
    }

    return size;
}

/**
* @brief Returns the element at the top of the stacks.
* @param s A stacks.
* @return The element at the top of the stack.
* @note Only applies to non-empty stacks.
*/
stack_elem stack_top(stack s) {
    assert(!stack_is_empty(s));    /* PRE: not stack_is_empty(s) */

    return (s->elem);
}

/**
* @brief Check if the given stack is empty.
* @param s A stack.
* @return true if the stack is empty, false otherwise.
*/
bool stack_is_empty(stack s) {
    return (s == NULL);
}

/**
* @brief Creates an array with all the elements of the stack.
* @param s A stack.
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'.
*/
stack_elem* stack_to_array(stack s) {
    stack_elem* array = NULL;

    if(!stack_is_empty(s)) {
        node* p = NULL;
        array = calloc(stack_size(s), sizeof(*p));

        p = s;
        for(unsigned int i = stack_size(s); i > 0u; i--) {
            array[i-1] = p->elem;
            p = p->next;
        }
    }

    return array;
}

/**
* @brief Destroys the stack.
* @param s A stack.
* @note All memory resources are freed.
*/
stack stack_destroy(stack s) {
    while(!stack_is_empty(s)) {
        s = stack_pop(s);
    }
    return s;
}