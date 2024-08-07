/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered. */
#include "array_helpers.h"
#include "weather_utils.h"

/**
 * @brief print usage help.
 * @param[in] program_name Executable name.
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "The dimensions of the array are given by the macro tclimate.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line.
 *
 * @param[in] argc amount of command line arguments.
 * @param[in] argv command line arguments.
 *
 * @return An string containing read filepath.
 */
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

// ---------------------------------- PART B: Data analysis ----------------------------------
/**
 * @brief Main program function.
 *
 * @param[in] argc amount of command line arguments.
 * @param[in] argv command line arguments.
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise.
 */
int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* Parse the filepath given in command line arguments. */
    filepath = parse_filepath(argc, argv);

    int value_lower_MinTemp = 0;
    int array_higher_MaxTemp_per_year[YEARS];
    month_t array_month_higher_Rainfall_per_year[YEARS];

    /* Create an array with the type of tclimate. */
    WeatherTable array;

    /* Parse the file to fill the array and obtain the actual length. */
    array_from_file(array, filepath);
    
    /* Storing the historical lowest temperature in a variable 'value_lower_MinTemp' and printing the result. */
    value_lower_MinTemp = lower_MinTemp(array);
    printf("The lowest historical minimum temperature recorded in the city of Cordoba is %d°C.\n", value_lower_MinTemp);

    /* Storing the highest temperature of each year in an array, with one element for each year, and printing it. */
    higher_MaxTemp_per_year(array, array_higher_MaxTemp_per_year);
    printf("\nThis is the highest maximum temperature recorded per year, from 1980 to 2016, in the city of Cordoba:\n");
    dump_MaxTemp(array_higher_MaxTemp_per_year, YEARS);

    /* Storing the month with the most precipitation of each year in an array, where each element corresponds to a month and year, and printing it. */
    printf("\nThese are the months of each year that had the highest rainfall in the city of Córdoba:\n");
    month_higher_Rainfall_per_year(array, array_month_higher_Rainfall_per_year);
    dump_rainfall(array_month_higher_Rainfall_per_year,YEARS);

    return (EXIT_SUCCESS);
}
