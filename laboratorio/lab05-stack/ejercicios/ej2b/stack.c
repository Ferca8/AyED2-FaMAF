#include <stdlib.h>
#include <assert.h>
#include "stack.h"

typedef struct _s_stack {
    stack_elem elem;
    struct _s_stack* next;
    size_t size;                        // Este es el invariante de representacion, el cual evita que
} node;                                 // el tamaño del array sea menor a 0

bool check_invariant(stack s) {               // Función para chequear el invariante
    return (s->size == stack_size(s));
}

/**
* @brief Creates an empty stack
* @return An empty stack
*/
stack stack_empty() {
    node* s = NULL;
    s = malloc(sizeof(*s));

    s->size = 0;
    s->next = NULL;
    
    check_invariant(s);
    return s;
}

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'e' at the top
*/
stack stack_push(stack s, stack_elem e) {
    assert(check_invariant(s));
    node* p = NULL;

    p = malloc(sizeof(*p));
    p->elem = e;
    p->next = s;
    p->size = s->size + 1;

    assert(check_invariant(p));
    return p;
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/
stack stack_pop(stack s) {
    assert(check_invariant(s));
    assert(!stack_is_empty(s)); // PRE: not stack_is_empty(s)

    stack p = s;
    stack q = p->next;
    q->size = s->size-1;
    free(p);
    p = NULL;

    assert(check_invariant(q));
    return q;
}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack s) {
    return (s->size);
}

/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem stack_top(stack s) {
    assert(check_invariant(s));
    assert(!stack_is_empty(s));   // PRE: not stack_is_empty(s)

    return (s->elem);
}

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(stack s) {
    assert(check_invariant(s));

    return (s->size == 0);
}

/**
* @brief Creates an array with all the elements of the stack
* @param s A stack
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'
*/
stack_elem* stack_to_array(stack s) {
    assert(check_invariant(s));
    stack_elem* array = NULL;

    if(!stack_is_empty(s)) {
        array = calloc(stack_size(s), sizeof(*array));
        node* p = NULL;
        p = s;

        for(unsigned int i = stack_size(s); i > 0u; i--) {
            array[i-1] = p->elem;
            p = p->next;
        }
    }

    assert(check_invariant(s));
    return array;
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack stack_destroy(stack s) {
    assert(check_invariant(s));

    stack p = NULL;
    p = s;

    while(!stack_is_empty(p)) {
        p = stack_pop(p);
    }

    assert(check_invariant(p));
    free(p);
    p = NULL;

    return p;
}