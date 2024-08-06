#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;                  // Elemento del nodo
    struct _s_abb *left;            // Rama derecha
    struct _s_abb *right;           // Rama izquierda
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
    else {          // !abb_is_empty(tree)
        if(elem_less(e,tree->elem)) {    // e < tree->elem => Seguí por izquierda
            tree->left = abb_add(tree->left,e);
        }
        if(!elem_less(e,tree->elem) && !elem_eq(e,tree->elem)) {   // tree->elem < e => Seguí por derecha
            tree->right = abb_add(tree->right,e);
        }
        if(elem_eq(e,tree->elem)){
            // Si son iguales significa que ya existe. Como funciona similar a un conjunto, no lo agrego
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
            if(abb_is_empty(tree->left) && abb_is_empty(tree->right)) {      // Caso sin hijos
                free(tree);
                tree = NULL;
            }
            else if(!abb_is_empty(tree->left) && abb_is_empty(tree->right)) {   // Caso con un hijo (izquierda)
                abb temp = tree;
                tree = tree->left;
                free(temp);
                temp = NULL;
            }
            else if(abb_is_empty(tree->left) && !abb_is_empty(tree->right)) {   // Caso con un hijo (derecha)
                abb temp = tree;
                tree = tree->right;
                free(temp);
                temp = NULL;
            }
            else if(!abb_is_empty(tree->left) && !abb_is_empty(tree->right)) {  // Caso con dos hijos
                abb_elem min_inorder = abb_min(tree->right);    // Busco el menor elemento de la rama derecha, con in-order

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

// #include "abb.h"
// //#include "strfuncs.h"
// #include <assert.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct _s_abb {
//   abb_elem elem;
//   struct _s_abb *left;
//   struct _s_abb *right;
// };

// typedef abb node_t;

// static bool elem_eq(abb_elem a, abb_elem b) { return a == b; }

// static bool elem_less(abb_elem a, abb_elem b) { return a < b; }

// static bool invrep(abb tree) {
//   bool b = true;

//   if (abb_is_empty(tree)) {
//     b = true;
//   }

//   if (!abb_is_empty(tree)) {
//     if (!abb_is_empty(tree->left)) {
//       b = (!elem_less(tree->elem, tree->left->elem) && invrep(tree->left));
//     }
//     if (!abb_is_empty(tree->right)) {
//       b = (elem_less(tree->elem, tree->right->elem) && invrep(tree->right));
//     }
//   }

//   return b;
// }

// abb abb_empty(void) {
//   abb tree = NULL;
//   assert(invrep(tree) && abb_is_empty(tree));
//   return tree;
// }

// abb abb_add(abb tree, abb_elem e) {
//   assert(invrep(tree));

//   if (abb_is_empty(tree)) { // Si esta vacio lo agrego de una
//     tree = malloc(sizeof(*tree));
//     assert(tree != NULL);
//     tree->elem = e;
//     tree->left = NULL;
//     tree->right = NULL;
//   }

//   else { // NOTE: !abb_is_empty(tree)

//     if (elem_less(e, tree->elem)) {
//       // recorro por izquierda
//       tree->left = abb_add(tree->left, e);
//     }

//     if (!elem_less(e, tree->elem) && !elem_eq(e, tree->elem)) {
//       // recorro por derecha
//       tree->right = abb_add(tree->right, e);
//     }

//     if (elem_eq(e, tree->elem)) {
//       // ya existe ==> no agrego
//     }
//   }

//   assert(invrep(tree) && abb_exists(tree, e));
//   return tree;
// }

// bool abb_is_empty(abb tree) { return tree == NULL; }

// bool abb_exists(abb tree, abb_elem e) {
//   assert(invrep(tree));

//   bool exists = false;

//   if (!abb_is_empty(tree)) {
//     exists = (elem_eq(e, tree->elem)) || abb_exists(tree->left, e) ||
//              abb_exists(tree->right, e);
//   }

//   assert(abb_length(tree) != 0 || !exists);
//   return exists;
// }

// unsigned int abb_length(abb tree) {
//   assert(invrep(tree));

//   unsigned int length = 0;

//   if (!abb_is_empty(tree)) {
//     length = 1 + abb_length(tree->left) + abb_length(tree->right);
//   }

//   assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
//   return length;
// }

// abb abb_remove(abb tree, abb_elem e) {
//   assert(invrep(tree));

//   if (!abb_is_empty(tree)) {
//     if (elem_less(tree->elem, e)) {
//       tree->right = abb_remove(tree->right, e);
//     }

//     if (elem_less(e, tree->elem)) {
//       tree->left = abb_remove(tree->left, e);
//     }

//     if (elem_eq(tree->elem, e)) {
//       if (abb_is_empty(tree->left) && abb_is_empty(tree->right)) {
//         // si no tiene hijos, lo elimino directamente
//         free(tree);
//         tree = NULL;
//       }

//       else if (!abb_is_empty(tree->left) && abb_is_empty(tree->right)) {
//         // si solo tiene elementos a la izquierda
//         abb temp = tree;
//         tree = tree->left;
//         free(temp);
//         temp = NULL;
//       }

//       else if (abb_is_empty(tree->left) && !abb_is_empty(tree->right)) {
//         // si solo tiene elementos a la derecha
//         abb temp = tree;
//         tree = tree->right;
//         free(temp);
//         temp = NULL;
//       }

//       else if (!abb_is_empty(tree->left) && !abb_is_empty(tree->right)) {

//         abb_elem min = abb_min(tree->right);

//         tree->elem = min;

//         tree->right = abb_remove(tree->right, min);
//       }
//     }
//   }

//   assert(invrep(tree) && !abb_exists(tree, e));
//   return tree;
// }
// abb_elem abb_root(abb tree) {
//   abb_elem root;
//   assert(invrep(tree) && !abb_is_empty(tree));

//   root = tree->elem;

//   assert(invrep(tree) && abb_exists(tree, root));
//   return root;
// }

// abb_elem abb_max(abb tree) {
//   abb_elem max_e;
//   assert(invrep(tree) && !abb_is_empty(tree));

//   max_e = abb_is_empty(tree->right) ? tree->elem : abb_max(tree->right);

//   assert(invrep(tree) && abb_exists(tree, max_e));
//   return max_e;
// }

// abb_elem abb_min(abb tree) {
//   abb_elem min_e;
//   assert(invrep(tree) && !abb_is_empty(tree));

//   min_e = abb_is_empty(tree->left) ? tree->elem : abb_min(tree->left);

//   assert(invrep(tree) && abb_exists(tree, min_e));
//   return min_e;
// }

// // void dibujar_ABB(char *prefijo, abb tree, bool es_mayor, abb_ordtype ord) {
// //   if (tree != NULL) {
// //     printf("%s", prefijo);

// //     printf("%s", (es_mayor ? "├──" : "╰──"));

// //     printf("%d\n", tree->elem);

// //     char *barra = "│   ";
// //     char *espacios = "    ";
// //     char *nuevo_prefijo = string_concat(prefijo, (es_mayor ? barra : espacios));

// //     dibujar_ABB(nuevo_prefijo, tree->left, true, ord);
// //     dibujar_ABB(nuevo_prefijo, tree->right, false, ord);

// //     free(nuevo_prefijo);
// //   }
// // }

// // void printRecorrido(abb tree, abb_ordtype ord) {
// //   if (tree != NULL) {
// //     if (ord == ABB_PRE_ORDER) {
// //       printf("%d ", tree->elem);
// //       printRecorrido(tree->left, ord);
// //       printRecorrido(tree->right, ord);
// //     }

// //     if (ord == ABB_IN_ORDER) {
// //       printRecorrido(tree->left, ord);
// //       printf("%d ", tree->elem);
// //       printRecorrido(tree->right, ord);
// //     }

// //     if (ord == ABB_POST_ORDER) {
// //       printRecorrido(tree->left, ord);
// //       printRecorrido(tree->right, ord);
// //       printf("%d ", tree->elem);
// //     }
// //   }
// // }

// void abb_dump(abb tree, abb_ordtype ord) {
//      assert(invrep(tree) && (ord==ABB_IN_ORDER  || 
//                              ord==ABB_PRE_ORDER ||
//                              ord==ABB_POST_ORDER));
//      /*
//       * c) Needs implementation: use the dump order indicated by `ord`
//       *
//       */

//      // Implementing in-order as default
//     if (tree != NULL) {
//          abb_dump(tree->left, ord);
//          printf("%d ", tree->elem);
//          abb_dump(tree->right, ord);
//      }
//  }

// abb abb_destroy(abb tree) {
//   assert(invrep(tree));

//   if (!abb_is_empty(tree)) {
//     tree->left = abb_destroy(tree->left);
//     tree->right = abb_destroy(tree->right);
//     free(tree);
//     tree = NULL;
//   }

//   assert(tree == NULL);
//   return tree;
// }
