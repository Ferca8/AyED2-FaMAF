#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include "tape.h"

struct _s_node {
    tape_elem elem;
    struct _s_node *next;
};


typedef struct _s_node * node_t;


struct _s_tape {
    unsigned int size;
    node_t cursor;  // Puntero al elemento actual
    node_t start;   // Puntero al primer nodo de la cinta
};


static bool invrep(tape_t tape) {
    /* COMPLETAR */
    bool basic_invariant = (tape != NULL);

    unsigned int counter = 0u;
    node_t pointer = NULL;
    pointer = tape->start;

    while(pointer != NULL) {
        counter++;
        pointer = pointer->next;
    }
    
    return basic_invariant && (counter == tape->size);
    /* COMPLETAR */
}


static node_t create_node(tape_elem e) {
    /* COMPLETAR */
    node_t new_node = NULL;
    new_node = malloc(sizeof(*new_node));

    new_node->elem = e;
    new_node->next = NULL;
    
    return new_node;
    /* COMPLETAR */
}


static node_t destroy_node(node_t node) {
    /* COMPLETAR */
    node->next = NULL;
    free(node);
    node = NULL;

    return node;
    /* COMPLETAR */
}


tape_t tape_create(void) {
    tape_t tape=NULL;
    /* COMPLETAR */
    tape = malloc(sizeof(*tape));

    tape->size = 0u;
    tape->cursor = NULL;
    tape->start = NULL;
    /* COMPLETAR */
    assert(invrep(tape) && tape_is_empty(tape) && tape_at_start(tape));
    return tape;
}


tape_t tape_rewind(tape_t tape) {
    /* COMPLETAR */
    assert(invrep(tape));

    tape->cursor = tape->start;

    assert(invrep(tape));
    assert(tape_at_start(tape));

    return tape;
    /* COMPLETAR */
}


bool tape_at_start(tape_t tape) {
    /* COMPLETAR */
    assert(invrep(tape));

    return (tape->cursor == tape->start);
    /* COMPLETAR */
}

bool tape_at_stop(tape_t tape) {
    /* COMPLETAR */
    assert(invrep(tape));

    return (tape->cursor == NULL);
    /* COMPLETAR */
}

bool tape_is_empty(tape_t tape) {
    /* COMPLETAR */
    assert(invrep(tape));

    return (tape->size == 0u);
    /* COMPLETAR */
}

unsigned int tape_length(tape_t tape) {
    /* COMPLETAR */
    assert(invrep(tape));

    return (tape->size);
    /* COMPLETAR */
}

tape_t tape_step(tape_t tape) {
    /* COMPLETAR */
    assert(invrep(tape));

    tape->cursor = tape->cursor->next;

    return tape;
    /* COMPLETAR */
}

tape_t tape_insertl(tape_t tape, tape_elem e) {
    /* COMPLETAR */
    assert(invrep(tape));

    node_t new_node = NULL;
    new_node = create_node(e);
    if(tape->cursor == tape->start) {
        new_node->next = tape->start;
        tape->start = new_node; 
    }
    else {
        node_t p = NULL;
        p = tape->start;
        while(p->next != tape->cursor) {
            p = p->next;
        }
        p->next = new_node;
        new_node->next = tape->cursor;
    }
    tape->cursor = new_node;
    tape->size++;

    assert(invrep(tape));
    assert(!tape_is_empty(tape));
    assert(!tape_at_stop(tape));

    return tape;
    /* COMPLETAR */
}

tape_t tape_insertr(tape_t tape, tape_elem e) {
    assert(invrep(tape) && (!tape_at_stop(tape) || tape_is_empty(tape)));
    node_t new_node=create_node(e);
    if (tape->start!= NULL) {
        new_node->next = tape->cursor->next;
        tape->cursor->next = new_node;
        tape->cursor = new_node;
    } else {
        tape->start = new_node;
        tape->cursor = new_node;
    }
    tape->size++;
    assert(invrep(tape) && !tape_is_empty(tape) && !tape_at_stop(tape) && e == tape_read(tape));
    return tape;
}

tape_t tape_erase(tape_t tape) {
    /* COMPLETAR */
    assert(invrep(tape));
    assert(!tape_is_empty(tape));
    assert(!tape_at_stop(tape));

    node_t p = NULL;
    p = tape->start;

    if(tape_at_start(tape)){
        tape->start = tape->start->next;
        tape->cursor = tape->cursor->next;

        destroy_node(p);
    } else {
        while(p->next != tape->cursor) {
            p = p->next;
        }
        p->next = tape->cursor->next;
        destroy_node(tape->cursor);
        tape->cursor = p->next;
    }

    tape->size = tape->size - 1;

    assert(invrep(tape));

    return tape;
    /* COMPLETAR */
}

tape_elem tape_read(tape_t tape) {
    /* COMPLETAR */
    assert(invrep(tape));
    assert(!tape_is_empty(tape));
    assert(!tape_at_stop(tape));

    return (tape->cursor->elem);
    /* COMPLETAR */
}

void tape_dump(tape_t tape) {
    assert(invrep(tape));
    node_t node=tape->start;
    printf("#");
    while (node != NULL) {
        if (node != tape->cursor) {
            printf("-%c-", node->elem);
        } else {
            printf("-[%c]-", node->elem);
        }
        node = node->next;
    }
    if (tape->cursor==NULL) {
        printf("-[]-");
    }
    printf("#\n");
}

tape_t tape_copy(tape_t tape) {
    /* COMPLETAR */
    assert(invrep(tape));

    tape_t copy = NULL;
    copy = tape_create();
    node_t original_position_cursor = tape->cursor;      // Guardo la posición del cursor en la cinta original para más tarde acomodarlo en el mismo lugar pero en la cinta copia.
                                                           
    tape = tape_rewind(tape);       // Rebobino la cinta original al comienzo

    while(!tape_at_stop(tape)) {                                  // Copio los elementos de la cinta original en la copia
        tape_insertr(copy, tape->cursor->elem);
        tape = tape_step(tape);
    }
                                 // Una vez puestos los elementos, ahora también debo dejar al cursor en su posición original
    copy = tape_rewind(copy);     // Rebobino la cinta copiada al comienzo 
    tape = tape_rewind(tape);          // Rebobino nuevamente la cinta original al comienzo

    while(tape->cursor != original_position_cursor) {
        copy = tape_step(copy);                                // Voy moviendo el cursor en ambas cintas hasta llegar a la posición original que tenía este
        tape = tape_step(tape);                                
    }

    assert(invrep(copy));
    assert(copy != tape);
    assert(tape_length(tape) == tape_length(copy));

    return copy;
    /* COMPLETAR */
}

tape_t tape_destroy(tape_t tape) {
    /* COMPLETAR */
    assert(invrep(tape));

    node_t node = tape->start;

    while (node != NULL) {
        node_t next = node->next;
        destroy_node(node);
        node = next;
    }

    free(tape);
    tape = NULL;

    return tape;
    /* COMPLETAR */
}
