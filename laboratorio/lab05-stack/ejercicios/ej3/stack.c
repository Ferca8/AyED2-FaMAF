#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#define RANDOM_CAPACITY 8   /* I create a random capacity to work on the implementation. */

struct _s_stack {
    stack_elem* elems;      /* Array of elements. */
    unsigned int size;      /* Number of elements in the stack. */
    unsigned int capacity;  /* Current capacity of the elems array. */
};

/* Manifest the representation invariant. */
bool invrep(stack s) {
    bool invariant = (s->size <= s->capacity);  /* The size of the stack must be less than or equal to the capacity of the array. */
    return invariant;
}

/**
* @brief Creates an empty stack.
* @return An empty stack.
*/
stack stack_empty() {
    stack new_stack = malloc(sizeof(*new_stack));

    new_stack->elems = NULL;
    new_stack->size = 0;
    new_stack->capacity = RANDOM_CAPACITY;

    assert(invrep(new_stack));
    return new_stack;
}

/**
* @brief Inserts an element at the top of the stack.
* @param s A stack.
* @param e An element to push into the stack.
* @return The new stack with 'elem' at the top.
*/
stack stack_push(stack s, stack_elem e) {
    assert(invrep(s));

    if(stack_is_empty(s)) {
        s->elems = realloc(s->elems, s->capacity * sizeof(*s->elems));  /* Allocate the new element in the array. */
    }
    else if (!stack_is_empty(s)) {
        if(s->size == s->capacity) {
            s->elems = realloc(s->elems, s->capacity * sizeof(*s->elems));   /* If a new element is to be added when the array size reaches its maximum capacity, then double the capacity and allocate the new element. */
            s->capacity = s->capacity * 2;                                            
        }
    }

    s->elems[s->size] = e;  /* Add the element to the array. */
    s->size = s->size + 1;  /* Increment the size, maintaining the representation invariant. */

    assert(invrep(s));
    return s;
}

/**
* @brief Removes the element at the top of the stack.
* @param s A stack.
* @return The new stack with the top element removed.
* @note Only applies to non-empty stacks.
*/
stack stack_pop(stack s) {
    assert(!stack_is_empty(s));
    assert(invrep(s));

    s->elems[s->size-1] = 0;    /* I set the last element of the array to 0 (delete it) and decrease its size by 1 (since I 'deleted' an element and now have an array with fewer elements). */
    s->size = s->size - 1;          

    assert(invrep(s));
    return s;
}

/**
* @brief Returns the size of the stack.
* @param s A stack.
* @return The size of the stack.
*/
unsigned int stack_size(stack s) {
    return (s->size);
}

/**
* @brief Returns the element at the top of the stacks.
* @param s A stacks.
* @return The element at the top of the stack.
* @note Only applies to non-empty stacks.
*/
stack_elem stack_top(stack s) {
    assert(!stack_is_empty(s));
    assert(invrep(s));
    
    return (s->elems[s->size - 1]);   /* The index of an array element starts at 0, which is why 1 is subtracted from size (which is always greater than 0 in this case due to the precondition). */
}

/**
* @brief Check if the given stack is empty.
* @param s A stack.
* @return true if the stack is empty, false otherwise.
*/
bool stack_is_empty(stack s) {
    assert(invrep(s));

    return (s->size == 0);
}

/**
* @brief Creates an array with all the elements of the stack.
* @param s A stack.
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'.
*/
stack_elem* stack_to_array(stack s) {
    assert(invrep(s));

    stack_elem* array = malloc(sizeof(*array) * stack_size(s));

    for (unsigned int i = 0; i < stack_size(s); i++) {
        array[i] = s->elems[i];
    }

    assert(invrep(s));
    return array;
}

/**
* @brief Destroys the stack.
* @param s A stack.
* @note All memory resources are freed.
*/
stack stack_destroy(stack s) {
  assert(invrep(s));

  free(s->elems);
  s->elems = NULL;

  free(s);
  s = NULL;

  return s;
}