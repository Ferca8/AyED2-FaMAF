/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    return (x->rank <= y->rank);
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

static void swap(player_t atp[], unsigned int i, unsigned int j) {
    player_t aux = atp[i];
    atp[i] = atp[j];
    atp[j] = aux;
}

static unsigned int min_pos_from_player_atp(player_t atp[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(atp[min_pos],atp[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void sort(player_t atp[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from_player_atp(atp, i, length);
        swap(atp, i, min_pos);
    }
}

/* 
    CPU time used to sort the array: 0.019496 seconds. (Laboratorio 3, ejercicio 3) 
    CPU time used to sort the array: 0.006516 seconds. (Laboratorio 4, ejercicio 3)
*/

