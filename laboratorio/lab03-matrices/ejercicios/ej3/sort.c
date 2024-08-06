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

/* An auxiliary function that allows me to swap the elements of an array. */
void swap(player_t atp[], unsigned int i, unsigned int j) {
    player_t aux = atp[i];
    atp[i] = atp[j];
    atp[j] = aux;
}

/* 'goes_before' is the ordering criterion followed by the program. In this case, it returns true when the ATP ranking of one tennis player, x, is less than the ranking of another tennis player, y. */
bool goes_before(player_t x, player_t y){
    return (x.rank <= y.rank);
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

/* --------------------------------------- SELECTION SORT --------------------------------------- 
A slight modification of the selection algorithm shown in lab 2, where it takes arrays of type player_t (a structure defined in player.h) instead of int. */
unsigned int min_pos_from_player_atp(player_t atp[], unsigned int i, unsigned int length) {
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
