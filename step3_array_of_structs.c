//
// Created by Mael Kerichard on 20/12/2021.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char iso[10];
    char name[50];
    float consumption_co2;
    int year, population;
    float co2, cumulative_co2;
} country;

int const line_count = 215;

/**
* Display country data
*/
void display_country(country c) {
    if (c.consumption_co2 == -1) {
        printf("No data available on the consumption CO2 caused by %s in %d.\n", c.name,
               c.year); //print message if consumption_co2 not available
    } else {
        printf("%s caused %f million tons of CO2 in %d.\n", c.name, c.consumption_co2,
               c.year); //print message if consumption_co2 available
    }
}

int main() {
    FILE *file;
    file = fopen("/Users/maelkerichard/CLionProjects/sys-tp-10-11-12/owid-co2-data-excerpt.csv", "r");
    if (file) {
        char line[1024];
        fgets(line, sizeof(line), file); //skip first line

        country countries[line_count];

        // fill the array
        for (int i = 0; i < line_count; ++i) {
            fgets(line, sizeof(line), file);
            char consumption_co2_char[10];
            sscanf(line, "%[^,],%[^,],%d,%f,%[^,],%f,%d", countries[i].iso, countries[i].name, &countries[i].year,
                   &countries[i].co2, consumption_co2_char,
                   &countries[i].cumulative_co2, &countries[i].population);
            countries[i].consumption_co2 = consumption_co2_char[0] == '?' ? -1 : atof(consumption_co2_char);
        }

        // print the array
        for (int i = 0; i < line_count; ++i) {
            display_country(countries[i]);
        }

        fclose(file);
    } else {
        printf("File not found");
    }
}


