#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include "pstack.h"

struct s_pstack {
    /* COMPLETAR */
    struct s_node **array;               // Array es un puntero a un arreglo de punteros
    priority_t max_priority;             // Tamaño máximo del arreglo
    unsigned int size;                   // Cantidad de elementos en la pila
    /* COMPLETAR */
};

struct s_node {
    /* COMPLETAR */
    pstack_elem elem;                   // e1,e2,...,en
    struct s_node* next;                // next ó NULL
    /* COMPLETAR */
};

static struct s_node *create_node(pstack_elem e) {
    struct s_node *new_node = NULL;
    /* COMPLETAR */
    new_node = malloc(sizeof(*new_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    /* COMPLETAR */
    return new_node;
}

static struct s_node *destroy_node(struct s_node *node) {
    /* COMPLETAR */
    node->next = NULL;
    free(node);
    node = NULL;
    /* COMPLETAR */
    return node;
}


static bool invrep(pstack s) {
    return (s != NULL);
}

pstack pstack_empty(priority_t max_priority) {
    pstack s=NULL;
    /* COMPLETAR */
    s = malloc(sizeof(*s));                                             // Alloco memoria para el nuevo pstack
    
    s->size = 0u;                                                             // Como es vacío, no voy a tener elementos existentes
    s->max_priority = max_priority;                                           // Le doy la mayor prioridad posible del arreglo
    s->array = calloc(sizeof(s->array), s->max_priority+1);       // Inicializo todo el arreglo con NULL
    /* COMPLETAR */
    assert(invrep(s) && pstack_is_empty(s));
    return s;
}

pstack pstack_push(pstack s, pstack_elem e, priority_t priority) {
    assert(invrep(s));
    /* COMPLETAR */
    struct s_node *node = NULL;                     // Creo el nuevo nodo a pushear
    node = create_node(e);

    node->next = s->array[priority];                // Acomodo el nodo en pstack según la prioridad que se le da
    s->array[priority] = node;

    s->size++;                                      // Incremento el size del pstack por agregar un nuevo nodo
    /* COMPLETAR */
    assert(invrep(s) && !pstack_is_empty(s));
    return s;
}

bool pstack_is_empty(pstack s) {
    assert(invrep(s));
    /* COMPLETAR (cambiado el return) */
    return (s->size == 0u);
}

pstack_elem pstack_top(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    /* COMPLETAR */
    pstack_elem elem_high_priority = s->array[pstack_top_priority(s)]->elem;
    /* COMPLETAR (cambiado el return también) */
    return elem_high_priority;
}

priority_t pstack_top_priority(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    /* COMPLETAR */
    unsigned int high_priority = 0u;

    for(unsigned int i = 0u; i <= s->max_priority; i++) {               // Recorro todo el pstack buscando la mayor prioridad
        if(s->array[i] != NULL) {
            high_priority = i;
        }
    }
    /* COMPLETAR (cambiado el return también) */
    return high_priority;
}

size_t pstack_size(pstack s) {
    assert(invrep(s));
    /* COMPLETAR (cambiado el return) */
    return (s->size);
}

pstack pstack_pop(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    /* COMPLETAR */
    priority_t i = pstack_top_priority(s);
    struct s_node *node_pop = NULL;

    node_pop = s->array[i];
    s->array[i] = s->array[i]->next;
    destroy_node(node_pop);

    s->size = s->size - 1;
    /* COMPLETAR */
    assert(invrep(s));
    return s;
}

pstack pstack_destroy(pstack s) {
    assert(invrep(s));
    /* COMPLETAR */
    while(!pstack_is_empty(s)) {
        pstack_pop(s);
    }

    free(s->array);
    free(s);
    s = NULL;
    /* COMPLETAR */
    return s;
}
