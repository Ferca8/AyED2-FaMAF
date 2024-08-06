#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#define RANDOM_CAPACITY 8    //Hago una capacidad aleatoria para poder trabajar la implementación

struct _s_stack {
    stack_elem* elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

// Manifiesto el invariante de representación
bool invrep(stack s) {
    bool invariant = (s->size <= s->capacity);  // El tamaño de la pila debe ser menor o igual que la capacidad del arreglo
    return invariant;
}

/**
* @brief Creates an empty stack
* @return An empty stack
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
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'elem' at the top
*/
stack stack_push(stack s, stack_elem e) {
    assert(invrep(s));

    if(stack_is_empty(s)) {
        s->elems = realloc(s->elems, s->capacity * sizeof(*s->elems));  // Aloco el nuevo elemento del arreglo
    }
    else if (!stack_is_empty(s)) {
        if(s->size == s->capacity) {
            s->elems = realloc(s->elems, s->capacity * sizeof(*s->elems));   // En caso de querer agregar un nuevo elemento cuando el tamaño del arreglo topa con su
            s->capacity = s->capacity * 2;                                             // capacidad máxima, entonces duplico la capacidad del mismo y aloco el elemento nuevo 
        }
    }

    s->elems[s->size] = e;  // Agrega el elemento en el arreglo
    s->size = s->size + 1;  // Incrementa el tamaño, manteniendo el invariante de representación

    assert(invrep(s));
    return s;
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/
stack stack_pop(stack s) {
    assert(!stack_is_empty(s));
    assert(invrep(s));

    s->elems[s->size-1] = 0;        // Hago 0 al último elemento del arreglo (lo "borro") y disminuyo el tamaño del
    s->size = s->size - 1;          // mismo en 1 (puesto que "borré" un elemento y tengo un arreglo con menos elementos ahora)

    assert(invrep(s));
    return s;
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
    assert(!stack_is_empty(s));
    assert(invrep(s));
    
    return (s->elems[s->size - 1]);   // El índice de un elemento de arreglo es menor inicia en 0, por eso a size (que siempre es mayor a 0 en este caso por la precondición) se le resta 1
}

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(stack s) {
    assert(invrep(s));

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
    assert(invrep(s));

    stack_elem* array = malloc(sizeof(*array) * stack_size(s));

    for (unsigned int i = 0; i < stack_size(s); i++) {
        array[i] = s->elems[i];
    }

    assert(invrep(s));
    return array;
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack stack_destroy(stack s) {
  assert(invrep(s));

  free(s->elems);
  s->elems = NULL;

  free(s);
  s = NULL;

  return s;
}