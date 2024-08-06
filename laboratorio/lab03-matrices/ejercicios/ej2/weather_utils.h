#ifndef _WEATHER_UTILS_
#define _WEATHER_UTILS_

#include "array_helpers.h"

int lower_MinTemp(WeatherTable a);

void higher_MaxTemp_per_year(WeatherTable a, int output[YEARS]);

void month_higher_Rainfall_per_year(WeatherTable a, unsigned int output[YEARS]);

#endif