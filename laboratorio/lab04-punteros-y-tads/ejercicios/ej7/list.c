#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct node {
    elem elem;
    struct node *next;
} node;


list empty_list() {
    list l = NULL;
    return l;
}
/* 
    Create an empty list. 
*/

list addl(elem e, list l) {
    node *p = malloc(sizeof(node));
    p->elem = e;
    p->next = l;
    l = p;
    return l;
}
/* 
    Adds element e to the beginning of list l. 
*/

list destroy_list(list l) {
    while (l != NULL) {
        node *p = l;
        l = l->next;
        free(p);
    }
    return l;
}
/* 
    Free memory if necessary. 
*/

bool is_empty_list(list l) { 
    return (l == NULL); 
}
/* 
    Returns True if l is empty. 
*/

elem head(list l) {
    assert(!is_empty_list(l));

    return(l->elem);
}
/* 
    Returns the first element of the list l.
    PRE: not is_empty_list(l)
*/

list tail(list l) {
    assert(!is_empty_list(l));

    node *p;
    p = l->next;
    free(l);
    return p;
}
/* 
    Delete the first element of the list l.
    PRE: not is_empty_list(l)
*/

list addr(list l, elem e) {
    node *p = malloc(sizeof(node));
	p->elem = e;
	p->next = NULL;
	if(!is_empty_list(l)) {	
		list q = l;
		while(q->next != NULL) { 
            q = q->next; 
        }
		q->next = p;
	} else {
        l = p; 
    }
	return l;
}
/* 
    Adds element e to the end of list l. 
*/

unsigned int length(list l) {
    node *p; 
    unsigned int n = 0;
    p = l;
    while(p != NULL) {
        p = p->next;
        n++;
    }
    return n;
}
/* 
    Returns the number of elements in the list l. 
*/

list concat(list l1, list l2) {
    node *p = l1;
    while(p->next != NULL) { 
        p = p->next; 
    }
    p->next = l2;
    return l1;
}
/* 
    Add all the elements of l2 to the end of l1 in the same order. 
*/

elem index(list l, unsigned int n) {
    assert(length(l) > n);
    
    node *p;
    p = malloc(sizeof(node));
    p = l;

    unsigned int i = 1u;
    while(i < n) {
        p = p->next;
        i++;
    }
    return p->elem;
}
/* 
    Returns the nth element of the list l.
    PRE: length(l) > n
*/

list take(list l, unsigned int n) {
    node *p;
    p = l;
    unsigned int i = 0u;

    while(i < n && p->next != NULL) {
        p = p->next;
        i++;
    }
    destroy_list(p->next);
    return l;
}
/* 
    Leave only the first n elements in l, removing the rest.
*/

list drop(list l, unsigned int n) {
    node *p;
    unsigned int i = 0u;
    while(i < n && p->next != NULL) {
        p = l;
        l = l->next;
        free(p);
        i++;
    }
    return l;
}
/* 
    Remove the first n elements from l.
*/

list copy_list(list l) {
    list copy = empty_list();
    list p = l;
    while(p != NULL) {
		copy = addr(copy, p->elem);
		p = p->next;
	}
	return copy;
}
/* 
    Copy all elements from l to the new list. 
*/

void list_dump(list l) {
    printf("\nThe elements of the list are: \n");
    list l_copy = copy_list(l);
    while(l_copy != NULL) {
        printf("%d --> ", l_copy->elem);
        l_copy = l_copy->next;
    }
    printf("\n");
}
/*
    Show the elements of the list in the screen.
*/