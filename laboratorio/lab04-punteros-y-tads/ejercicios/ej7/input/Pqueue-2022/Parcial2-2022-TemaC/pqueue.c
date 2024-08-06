#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    /* COMPLETAR */
    struct s_node **array;
    priority_t min_priority;
    size_t size;
    /* COMPLETAR */
};

struct s_node {
    /* COMPLETAR */
    pqueue_elem elem;
    struct s_node *next;
    /* COMPLETAR */
};

static struct s_node * create_node(pqueue_elem e) {
    struct s_node* new_node=NULL;
    /* COMPLETAR */
    new_node = malloc(sizeof(*new_node));
    assert(new_node!=NULL);

    new_node->elem = e;
    new_node->next = NULL;
    /* COMPLETAR */
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    /* COMPLETAR */
    node->next = NULL;
    free(node);
    node = NULL;
    /* COMPLETAR */
    return node;
}


static bool invrep(pqueue q) {
    return (q != NULL);
}

pqueue pqueue_empty(priority_t min_priority) {
    pqueue q=NULL;
    /* COMPLETAR */
    q = malloc(sizeof(*q));

    q->size = 0;
    q->min_priority = min_priority;
    q->array = calloc(sizeof(q->array),q->min_priority+1);
    /* COMPLETAR */
    assert(invrep(q) && pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, priority_t priority) {
    assert(invrep(q));
    /* COMPLETAR */
    struct s_node *new_node = NULL;
    new_node = create_node(e);

    if(q->array[priority] == NULL) {
        q->array[priority] = new_node;
    } else {
        struct s_node *p = NULL;
        p = q->array[priority];

        while(p->next != NULL) {
            p = p->next;
        }

        p->next = new_node;
    }

    q->size++;
    /* COMPLETAR */
    assert(invrep(q) && !pqueue_is_empty(q));
    return q;
}

bool pqueue_is_empty(pqueue q) {
    assert(invrep(q));
    return (q->size == 0); //BORRAR ESTA LINEA
}

pqueue_elem pqueue_peek(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    return (q->array[pqueue_peek_priority(q)]->elem); // BORRAR ESTA LINEA
}

priority_t pqueue_peek_priority(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    
    // comienzo desde el inicio del arreglo a contar todas
    // las posiciones en las que existe una queue
    unsigned int max_priority = 0u;

    for (unsigned int i = q->min_priority; i != 0; i--) {
    // <= porque si max_priority es 5 tengo prioridades 0,1,2,3,4,5, # = 6
        if (q->array[i] != NULL) {
        max_priority = i;
        }
    }

    assert(invrep(q));
    return max_priority; // BORRAR ESTA LINEA
}

size_t pqueue_size(pqueue q) {
    assert(invrep(q));
    return (q->size); // BORRAR ESTA LINEA
}

pqueue pqueue_dequeue(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    /* COMPLETAR */
    struct s_node *killme = NULL;
    killme = q->array[pqueue_peek_priority(q)];       // Puntero que apunta al elemento de mayor prioridad

    q->array[pqueue_peek_priority(q)] = q->array[pqueue_peek_priority(q)]->next;     // Convierto al segundo elemento con mayor prioridad en el primero
    destroy_node(killme);               // Desencolo el elemento de mayor prioridad

    q->size = q->size-1;
    /* COMPLETAR */
    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    /* COMPLETAR*/
    while(!pqueue_is_empty(q)) {
        q = pqueue_dequeue(q);
    }

    free(q->array);
    q->array = NULL;
    free(q);
    q = NULL;
    /* COMPLETAR */
    return q;
}

