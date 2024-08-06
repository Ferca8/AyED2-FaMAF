// ---------------------------------- PART B: Data analysis ----------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "weather_utils.h"

/* 'lower_MinTemp' is function that obtains the historical lowest minimum temperature recorded in the city of Córdoba according to the data in the array. */
int lower_MinTemp(WeatherTable a) {
    int minTemp = __INT_MAX__;

    for(unsigned int year =  0; year < YEARS; year++) {
        for(unsigned int month = 0; month < MONTHS; month++) {
            for(unsigned day = 0; day < DAYS; day++){
                if(a[year][month][day]._min_temp < minTemp){
                    minTemp = a[year][month][day]._min_temp;
                }
            }
        }
    }
return minTemp;
}

/* 'higher_MaxTemp_per_year' is a 'procedure' that records for each year between 1980 and 2016 the highest maximum temperature recorded during that year. */
void higher_MaxTemp_per_year(WeatherTable a, int output[YEARS]) {
    int maxTemp = -(__INT_MAX__);

    for(unsigned int year = 0; year < YEARS; year++){
        for(month_t month = january; month < MONTHS; month++){
            for(unsigned int day = 0; day < DAYS; day++){
                if(a[year][month][day]._max_temp > maxTemp){
                    maxTemp = a[year][month][day]._max_temp;
                }
            }
        } 
        output[year] = maxTemp;
    }
}

/* 'month_higher_Rainfall_per_year' is a procedure that records for each year between 1980 and 2016 the month of that year in which the highest monthly rainfall was recorded. */
void month_higher_Rainfall_per_year(WeatherTable a, unsigned int output[YEARS]) {
    unsigned int sum_rainfall, max_rainfall = 0u;
    month_t month_max_rainfall = january;

    for(unsigned int year = 0; year < YEARS; year++){        
        for(month_t month = january; month < MONTHS; month++){
            sum_rainfall = 0u;

            for(unsigned int day = 0; day < DAYS; day++){
                sum_rainfall = sum_rainfall + a[year][month][day]._rainfall;
            }

            if(sum_rainfall > max_rainfall){
                max_rainfall = sum_rainfall;
                month_max_rainfall = month+1;
            }
        }
        output[year] = month_max_rainfall;
        max_rainfall = 0u;
    }
}
