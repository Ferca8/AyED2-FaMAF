/*
  @file array_helpers.d
  @brief Array Helpers method implementation.
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"


/**
 * @brief returns true when reach last line in weather file.
 * @param[in] year Year array position (start in 0 ends with YEARS - 1).
 * @param[in] month Month of the year (december is last month 11u).
 * @param[in] day Day of the month. We assume all month have 28 days.
 * @return True when is the last line of the file, False otherwise.
 */
static bool is_last_line(unsigned int year, unsigned int month, unsigned int day)
{
    return  year == YEARS - 1u && month == december && day == DAYS - 1u;
}


void array_dump(WeatherTable a) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                fprintf(stdout, "%u %u %u ", year + FST_YEAR, month + 1, day + 1);
                weather_to_file(stdout, a[year][month][day]);
                if (!is_last_line(year, month, day))
                {
                    fprintf(stdout, "\n");
                }
            }
        }
    }
}

// ---------------------------------- PART A: Data upload ----------------------------------
void array_from_file(WeatherTable array, const char *filepath) {
    /* Creation of the file pointer and opening of this file. Also checks whether the file address exists or not. */
    FILE *file = NULL;

    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    /* Variable declarations. */
    unsigned int k_year = 0u;
    unsigned int k_month = 0u;
    unsigned int k_day = 0u;

    /* This loop reads elements until it reaches the end of the file, and stores them in an array. */
    while (!feof(file)) {

        /* Initialization of a variable 'res', which is responsible for reading the date of the data to be copied. */
        int res = fscanf(file, " %u %u %u ", &k_year, &k_month, &k_day);

        /* With a condition, I verify that the read data consists of year, month, and day (3), and no more or less. */
        if (res != 3) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }

        /* 
            Initialization of a variable 'weather' of type Weather, a structure defined in weather.h as:

            typedef struct _weather {
                int _average_temp; (temperatura media)
                int _max_temp; (temperatura máxima)
                int _min_temp; (temperatura mínima)
                unsigned int _pressure; (presión)
                unsigned int _moisture; (humedad)
                unsigned int _rainfall; (precipitaciones)
            } 
            Weather; 
        
            Where I store all the respective weather values ​​for the read date. 
        */
        Weather weather = weather_from_file(file);

        /* 
            The parameter 'array' is of type Weathertable[YEARS][MONTHS][DAYS], where:
                    - YEARS = 37, so the indexes used are 0..36.
                    - MONTHS = MONTHS = 12, so the indexes used are 0..11.
                    - DAYS = 28, so the indexes used are 0..27. 
            Since the year numbers in the file range from 1980 to 2016, I subtract FST_YEAR(1980) to manipulate the indexes from 0 to 36.
            Since the month numbers in the file range from January(1) to December(12), I subtract 1 to manipulate the indexes from 0 to 11.
            Since the day numbers in the file range from 1 to 28, I also subtract 1 (or FST_DAY) to manipulate the indexes from 0 to 27.
            The weather data is assigned to the corresponding position in the array table using the year, month, and day values as indexes. 
        */
        array[k_year-FST_YEAR][k_month-1][k_day-FST_DAY] = weather;      
    }

    /* Closing the file. */
    fclose(file);
}

// ---------------------------------- PART B: Data analysis ----------------------------------
/* 
    'dump_MaxTemp' displays an array whose elements are the maximum temperature of each year from 1980 to 2016. 
    It simply displays the temperature values accompanied by the symbol °C. 
*/
void dump_MaxTemp(int a[], unsigned int length) {
    if(length == 0u) {
        printf("[]\n");
    }
    else {
        printf("[");
        for(unsigned int i = 0; i < length-1; i++){
            printf("%d°C  ", a[i]);
        }
        printf("%d°C]\n", a[length-1]);
    }
} 

/* 
    dump_rainfall' displays an array whose elements are the months with the highest rainfall for each year. 
    This function has a slight modification, where based on the value of the element, it is changed to its equivalent month. 
    For example, January is month 1, November is month 11, and so on, respectively. 
*/
void dump_rainfall(unsigned int a[], unsigned int length) {
    if(length == 0u) {
        printf("[]\n");
    }
    else {
        printf("[");
        for(unsigned int i = 0; i < length-1; i++){
            if(a[i] == 1){printf("Ene/%d  ", FST_YEAR+i);}
            else if(a[i] == 2){printf("Feb/%d  ", FST_YEAR+i);}
            else if(a[i] == 3){printf("Mar/%d  ", FST_YEAR+i);}
            else if(a[i] == 4){printf("Abr/%d  ", FST_YEAR+i);}
            else if(a[i] == 5){printf("May/%d  ", FST_YEAR+i);}
            else if(a[i] == 6){printf("Jun/%d  ", FST_YEAR+i);}
            else if(a[i] == 7){printf("Jul/%d  ", FST_YEAR+i);}
            else if(a[i] == 8){printf("Ago/%d  ", FST_YEAR+i);}
            else if(a[i] == 9){printf("Set/%d  ", FST_YEAR+i);}
            else if(a[i] == 10){printf("Oct/%d  ", FST_YEAR+i);}
            else if(a[i] == 11){printf("Nov/%d  ", FST_YEAR+i);}
            else{printf("Dic/%d  ", FST_YEAR+i);}
        }
        if(a[length-1] == 1){printf("Ene/%d]\n", FST_YEAR+(length-1));}
            else if(a[length-1] == 2){printf("Feb/%d]\n", FST_YEAR+(length-1));}
            else if(a[length-1] == 3){printf("Mar/%d]\n", FST_YEAR+(length-1));}
            else if(a[length-1] == 4){printf("Abr/%d]\n", FST_YEAR+(length-1));}
            else if(a[length-1] == 5){printf("May/%d]\n", FST_YEAR+(length-1));}
            else if(a[length-1] == 6){printf("Jun/%d]\n", FST_YEAR+(length-1));}
            else if(a[length-1] == 7){printf("Jul/%d]\n", FST_YEAR+(length-1));}
            else if(a[length-1] == 8){printf("Ago/%d]\n", FST_YEAR+(length-1));}
            else if(a[length-1] == 9){printf("Set/%d]\n", FST_YEAR+(length-1));}
            else if(a[length-1] == 10){printf("Oct/%d]\n", FST_YEAR+(length-1));}
            else if(a[length-1] == 11){printf("Nov/%d]\n", FST_YEAR+(length-1));}
            else{printf("Dic/%d]\n", FST_YEAR+(length-1));}
    }
}