/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods.
*/
#include <stdlib.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6 ;

// ---------------------------------- PART A: Data upload ----------------------------------
/* 'weather_from_file' reads weather data from a file and stores it in a Weather object. */
Weather weather_from_file(FILE* file) {
    /* Variable declaration. */
    Weather weather;

    /* Reading weather data from the file following the format EXPECTED_WEATHER_FILE_FORMAT ("%d %d %d %u %u %u"). */
    int res = fscanf(file, EXPECTED_WEATHER_FILE_FORMAT, &weather._average_temp, &weather._max_temp,
                                                         &weather._min_temp, &weather._pressure,
                                                         &weather._moisture, &weather._rainfall);
    
    /* 
        Verification of whether fscanf was able to read the expected amount of weather variables. 
        If not, an error message is printed and the program stops. 
    */
    if(res != AMOUNT_OF_WEATHER_VARS) {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    
    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp, 
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
