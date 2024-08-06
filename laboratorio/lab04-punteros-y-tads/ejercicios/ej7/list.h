#ifndef _LIST_H
#define _LIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// List as a pointer to structs to guarantee encapsulation. 
typedef struct node *list;
typedef int elem;

// ---------------------------------------- CONSTRUCTORS ----------------------------------------
list empty_list();
/* 
    Create an empty list. 
*/

list addl(elem e, list l);
/* 
    Adds element e to the beginning of list l. 
*/

// ------------------------------------------ DESTROY ------------------------------------------
list destroy_list(list l);
/* 
    Free memory if necessary. 
*/

// ---------------------------------------- OPERATIONS -----------------------------------------
bool is_empty_list(list l);
/* 
    Returns True if l is empty. 
*/

elem head(list l);
/* 
    Returns the first element of the list l.
    PRE: not is_empty_list(l)
*/

list tail(list l);
/* 
    Delete the first element of the list l.
    PRE: not is_empty_list(l)
*/

list addr(list l, elem e);
/* 
    Adds element e to the end of list l. 
*/

unsigned int length(list l);
/* 
    Returns the number of elements in the list l. 
*/

list concat(list l1, list l2);
/* 
    Add all the elements of l2 to the end of l1 in the same order. 
*/

elem index(list l, unsigned int n);
/* 
    Returns the nth element of the list l.
    PRE: length(l) > n
*/

list take(list l, unsigned int n);
/* 
    Leave only the first n elements in l, removing the rest.
*/

list drop(list l, unsigned int n);
/* 
    Remove the first n elements from l.
*/

list copy_list(list l);
/* 
    Copy all elements from l to the new list. 
*/

void list_dump(list l);
/*
    Show the elements of the list in the screen.
*/

#endif