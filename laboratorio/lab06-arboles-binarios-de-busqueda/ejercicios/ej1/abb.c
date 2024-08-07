#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;                  /* Node element. */
    struct _s_abb *left;            /* Left branch. */
    struct _s_abb *right;           /* Right branch. */
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    // Needs implementation
    bool invariant = true;

    if(abb_is_empty(tree)) {
        invariant = true;
    }
    if(!abb_is_empty(tree)) {
        if(!abb_is_empty(tree->left)) {
            invariant = (!elem_less(tree->elem, tree->left->elem) && invrep(tree->left));
        }
        if(!abb_is_empty(tree->right)) {
            invariant = (elem_less(tree->elem, tree->right->elem) && invrep(tree->right));
        }
    }
    // Needs implementation

    return invariant;
}

abb abb_empty(void) {
    abb tree;

    // Needs implementation
    tree = NULL;
    // Needs implementation

    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}


abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    
    // Needs implementation
    if(abb_is_empty(tree)) {
        tree = malloc(sizeof(*tree));
        assert(tree != NULL);
        tree->elem = e;
        tree->left = NULL;
        tree->right = NULL;
    }
    else {    /*  not abb_is_empty(tree) */
        if(elem_less(e,tree->elem)) {    /* If e < tree->elem, then go down the left branch. */
            tree->left = abb_add(tree->left,e);
        }
        if(!elem_less(e,tree->elem) && !elem_eq(e,tree->elem)) {    /* If e > tree->elem, then go down the right branch. */   
            tree->right = abb_add(tree->right,e);
        }
        if(elem_eq(e,tree->elem)){
            /* If e = tree->elem, it means the element already exists and shouldn't be added. */
        }
    }
    // Needs implementation

    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    return (tree == NULL);
}

bool abb_exists(abb tree, abb_elem e) {
    assert(invrep(tree));
    bool exists = false;

    // Needs implementation
    if(!abb_is_empty(tree)) {
        exists = elem_eq(e,tree->elem) || abb_exists(tree->left, e) || abb_exists(tree->right, e);
    }
    // Needs implementation

    assert(abb_length(tree)!= 0 || !exists);
    return exists;
}

unsigned int abb_length(abb tree) {
    assert(invrep(tree));
    unsigned int length = 0;

    // Needs implementation
    if(!abb_is_empty(tree)) {
        length = 1 + abb_length(tree->left) + abb_length(tree->right);
    }
    // Needs implementation

    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));

    // Needs implementation
    if(!abb_is_empty(tree)) {
        if(elem_less(tree->elem, e)) {
            tree->right = abb_remove(tree->right, e);
        }
        if(elem_less(e, tree->elem)) {
            tree->left = abb_remove(tree->left, e);
        }
        if(elem_eq(tree->elem, e)) {
            if(abb_is_empty(tree->left) && abb_is_empty(tree->right)) {      /* Case without children. */
                free(tree);
                tree = NULL;
            }
            else if(!abb_is_empty(tree->left) && abb_is_empty(tree->right)) {   /* Case with one child (left). */
                abb temp = tree;
                tree = tree->left;
                free(temp);
                temp = NULL;
            }
            else if(abb_is_empty(tree->left) && !abb_is_empty(tree->right)) {   /* Case with one child (right). */
                abb temp = tree;
                tree = tree->right;
                free(temp);
                temp = NULL;
            }
            else if(!abb_is_empty(tree->left) && !abb_is_empty(tree->right)) {  /* Case with two children. */
                abb_elem min_inorder = abb_min(tree->right);    /* Find the smallest element of the right branch, using in-order. */

                tree->elem = min_inorder;
                tree->right = abb_remove(tree->right,min_inorder);
            }
        }
    }

    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));

    // Needs implementation
    root = tree->elem;
    // Needs implementation

    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));

    // Needs implementation
    max_e = abb_is_empty(tree->right) ? tree->elem : abb_max(tree->right);
    // Needs implementation

    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));

    // Needs implementation
    min_e = abb_is_empty(tree->left) ? tree->elem : abb_min(tree->left);
    // Needs implementation

    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree, abb_ordtype ord) {
    assert(invrep(tree) && (ord==ABB_IN_ORDER  || 
                            ord==ABB_PRE_ORDER ||
                            ord==ABB_POST_ORDER));

    // c) Needs implementation: use the dump order indicated by `ord`
    if(ord == ABB_IN_ORDER) {
        if (tree != NULL) {
            abb_dump(tree->left, ord);
            printf("%d ", tree->elem);
            abb_dump(tree->right, ord);
        }
    }
    else if(ord == ABB_PRE_ORDER) {
        if (tree != NULL) {
            printf("%d ", tree->elem);
            abb_dump(tree->left, ord);
            abb_dump(tree->right, ord);
        }
    }
    else if(ord == ABB_POST_ORDER) {
        if (tree != NULL) {
            abb_dump(tree->left, ord);
            abb_dump(tree->right, ord);
            printf("%d ", tree->elem);
        }
    }
    // c) Needs implementation: use the dump order indicated by `ord`
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));

    // Needs implementation
    if(!abb_is_empty(tree)) {
        tree->left = abb_destroy(tree->left);
        tree->right = abb_destroy(tree->right);
        free(tree);
        tree = NULL;
    }
    // Needs implementation

    assert(tree == NULL);
    return tree;
}