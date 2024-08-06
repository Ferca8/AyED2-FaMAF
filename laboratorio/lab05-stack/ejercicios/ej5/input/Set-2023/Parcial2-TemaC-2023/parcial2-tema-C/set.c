#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include "set.h"

struct s_node {
    set_elem elem;
    struct s_node *next;
};

typedef struct s_node * node_t;

struct s_set {
    unsigned int size;
    node_t first;
};

static bool invrep(set s) {
    /* COMPLETAR */
    bool b = false;

    if (s != NULL) {
        b = true;

        if (s->first != NULL && s->size != 0) {
            node_t p = s->first;

            while (b && p->next != NULL) {
                b = b && p->elem < p->next->elem;
                p = p->next;
            }
        } 
    }

    /* COMPLETAR */
    return b;
}

static struct s_node *create_node(set_elem e) {
    /* COMPLETAR */
    node_t new_node = NULL;
    new_node = malloc(sizeof(*new_node));

    new_node->elem = e;
    new_node->next = NULL; 

    return new_node;
    /* COMPLETAR */
}

static struct s_node *destroy_node(struct s_node *node) {
    /* COMPLETAR */
    node->next = NULL;
    free(node);
    node = NULL;

    return node;
    /* COMPLETAR */
}

/* CONSTRUCTORS */

set set_empty(void) {
    /* COMPLETAR */
    set new_set = NULL;
    new_set = malloc(sizeof(*new_set));

    new_set->size = 0u;
    new_set->first = NULL;

    assert(invrep(new_set));
    assert(set_is_empty(new_set));

    return new_set;
    /* COMPLETAR */
}

set set_add(set s, set_elem e) {
    /* COMPLETAR */
    assert(invrep(s));
    node_t previous_node = NULL; // puntero al nodo #"x-1"
    node_t node = s->first; // Puntero al nodo #"x" (Donde x va hasta s->size)

  // Caso 0:
  // Si el set esta vacio es trivial agregar el nuevo nodo
    if (set_is_empty(s)) {
        s->first = create_node(e);
        s->size++;
    } else {
    // Caso 0.1:
    // Si e ya pertenece al set, no hay que agregarlo
        if (set_member(e, s)) {
        // skip
        }
        if (!set_member(e, s)) {
        // Avanzamos hasta llegar al nodo con el primer elemento de mayor valor
        // O hasta el final del set
            while (node->next != NULL && (node->elem < e)) {
                previous_node = node;
                node = node->next;
            } // node -> elem > e

      // Caso 1: No hay nodo previo
            if (previous_node == NULL) {

                // [2] meto el 4
                // Caso 1.1:
                // 'e' es mayor que el elemento del set
                if (node->next == NULL && (node->elem < e)) {
                    s->first->next = create_node(e);
                    s->size++;
                }

                // [2] meto el 1
                // [1, 2] meto el 1
                // Caso 1.2:
                // Hay un elemento mayor que 'e'
                if (!(node->elem < e)) {
                    node_t new_node = create_node(e);
                    new_node->next = s->first;
                    s->first = new_node;
                    s->size++;
                }
            }

            else {
                // [2,3] 4
                // [2,3,4] 4
                // Caso 2: Hay nodo previo
                // Caso 2.1:
                // 'e' es mayor al elemento que estamos mirando
                if (node->elem < e) {
                    node_t new_node = create_node(e);
                    new_node->next = node->next;
                    node->next = new_node;
                    s->size++;
                }

                else if (!(node->elem < e)) {
                    // [2,3,   5,6] 4
                    //    prev p
                    // Caso 2.2:
                    // 'e' es menor al elemento que estamos mirando actualmente
                    node_t new_node = create_node(e);
                    new_node->next = node;
                    previous_node->next = new_node;
                    s->size++;
                }
            }
        }
    }
  /*
   a b c d f g meto la e
   node_t node = create_node(e);
   while (p -> elem < e){
      prev = p;
      p = p -> next
   } // p->elem >= e
   a b c d    f g meto la e
         prev p
   node -> next = p;
   previous -> next = node;
   a b c d  f g
         |  ^
         |->e
   a b c d e f g
   */
  //

    return s;
    /* COMPLETAR */
}

/* OPERATIONS   */
unsigned int set_cardinal(set s) {
    /* COMPLETAR */
    assert(invrep(s));
    return s->size;
    assert((s->size == 0) == set_is_empty(s));
    /* COMPLETAR */
}

bool set_is_empty(set s) {
    /* COMPLETAR */
    assert(invrep(s));
    return s->size == 0;
    /* COMPLETAR */
}

bool set_member(set_elem e, set s) {
    assert(invrep(s));
    node_t node=s->first;

    while (node!=NULL && node->elem < e) {
        node = node->next;
    }

    return node!=NULL && node->elem==e;
}


set set_elim(set s, set_elem e) {
    /* COMPLETAR */
    assert(invrep(s));

    if (!set_member(e, s)) {
    // skip
    } else if (set_member(e, s)) {
        node_t p = s->first;

        if (p->elem == e) {
            s->first = s->first->next;
            destroy_node(p);
        } else if (p->elem != e) {
            while (p->next->elem != e) {
                p = p->next;
            } // p -> next -> elem == e

            node_t killme = p->next;
            p->next = p->next->next;
            destroy_node(killme);
        }
    }

    s->size--;

    return s;
    /* COMPLETAR */
}

set_elem set_get(set s) {
    assert(invrep(s) && !set_is_empty(s));
    return s->first->elem;
}

set_elem* set_to_array(set s) {
    /* COMPLETAR */
    assert(invrep(s));
    set_elem *array = malloc(sizeof(*array) * set_cardinal(s));
    node_t p = s->first;

    for (unsigned int i = 0u; i < set_cardinal(s); i++) {
        array[i] = p->elem;
        p = p->next;
    }

    assert(set_is_empty(s) || (!set_is_empty(s) && array != NULL));
    return array;
    /* COMPLETAR */
}

set set_destroy(set s) {
    /* COMPLETAR */
    assert(invrep(s));
    while (!set_is_empty(s)) {
        s = set_elim(s, set_get(s));
    }

    free(s);
    s = NULL;
    assert(s == NULL);
    return s;
    /* COMPLETAR */
}

