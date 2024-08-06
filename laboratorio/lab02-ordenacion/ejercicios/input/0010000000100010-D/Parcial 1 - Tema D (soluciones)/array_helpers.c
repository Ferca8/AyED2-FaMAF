/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "flight.h"

/**
* @brief returns true when reach last line in flight file
* @return True when is the last line of the file, False otherwise
*/
static bool is_last_line(unsigned int hour, unsigned int type) {
  return  hour == HOURS - 1u && type == TYPE - 1u;
}

void array_dump(DelayTable a) {
  for (unsigned int type = 0u; type < TYPE; ++type) {
    for (unsigned int hour = 0u; hour < HOURS; ++hour) {
      Flight f = a[type][hour];
      fprintf(stdout, "%c: %s flight with %u passengers arrived at %u:00, with %u delay.",
        f.code,
        f.type == 0 ? "last_mile" : "layover",
        f.passengers_amount,
        f.hour, /*- 1   Borro el -1 para abarcar las horas de 01:00 a 24:00 y no de 00:00 a 23:00 */
        f.delay
      );
      if (!is_last_line(hour, type))
      {
        fprintf(stdout, "\n");
      }
    }
  }
}

unsigned int compensation_cost (DelayTable a, unsigned int h) {
  unsigned int compensation = 0u;
  unsigned int total_cost_lastmile = 0u;
  unsigned int total_cost_layover = 0u;
  
    for(unsigned int i = 0u; i < h; i++) {
      if(a[last_mile][i].delay > MAX_LM_DELAY_ALLOWED) {
        total_cost_lastmile = 
        ((a[last_mile][i].delay - MAX_LM_DELAY_ALLOWED) *
        (a[last_mile][i].passengers_amount * COMPENSATION_PER_MINUTE)) + total_cost_lastmile;
      }

      if(a[layover][i].delay > MAX_LAYOVER_DELAY_ALLOWED) {
        total_cost_layover = 
        ((a[layover][i].delay - MAX_LAYOVER_DELAY_ALLOWED) *
        (a[layover][i].passengers_amount * COMPENSATION_PER_MINUTE)) + total_cost_layover;
      }
    }

    compensation = total_cost_lastmile + total_cost_layover;

  return compensation;
}


void array_from_file(DelayTable array, const char *filepath) {
  FILE *file = NULL;

  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  char code;
  int i = 0;

  while (!feof(file)) {
    /* COMPLETAR: lectura de cada vuelo */
    Flight last_mile_info = flight_from_file(file);
    Flight layover_info = flight_from_file(file);

    int res = fscanf(file, " #%c#\n", &code);
    if (res != 1) {
      fprintf(stderr, "Invalid file.\n");
      exit(EXIT_FAILURE);
    }

    last_mile_info.code = code;
    last_mile_info.type = last_mile;
    layover_info.code = code;
    layover_info.type = layover;

    array[last_mile_info.type][last_mile_info.hour - 1] = last_mile_info;
    array[layover_info.type][layover_info.hour - 1] = layover_info;
    
    i++;
  }
  fclose(file);
}
