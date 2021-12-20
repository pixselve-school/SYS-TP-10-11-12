//
// Created by Mael Kerichard on 20/12/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char iso[10];
    char name[50];
    float consumption_co2, co2, cumulative_co2, consumption_co2_per_citizens;
    int year, population;
} country;

int const line_count = 215;

/**
* Display country data
*/
void display_country(country *country_to_display) {
    if (country_to_display->consumption_co2 == -1) {
        printf("No data available on the consumption CO2 caused by %s in %d.\n", country_to_display->name,
               country_to_display->year); //print message if consumption_co2 not available
    } else {
        printf("%s caused %f million tons of CO2 in %d.\n", country_to_display->name, country_to_display->consumption_co2,
               country_to_display->year); //print message if consumption_co2 available
    }
}

/**
 * Sort countries by consumption_co2
 * @param c1  country 1
 * @param c2  country 2
 * @return > 0 if c1 > c2 or < 0 if c1 < c2
 */
int sort_by_consumption_co2(country *c1, country *c2) {
    return c1->consumption_co2 - c2->consumption_co2;
}

/**
 * Sort countries by co2
 * @param c1 country 1
 * @param c2 country 2
 * @return > 0 if c1 > c2 or < 0 if c1 < c2
 */
int sort_by_co2(country *c1, country *c2) {
    return c1->co2 - c2->co2;
}

/**
 * sort countries by cumulative_co2
 * @param c1 country 1
 * @param c2 country 2
 * @return > 0 if c1 > c2 or < 0 if c1 < c2
 */
int sort_by_cumulative_co2(country *c1, country *c2) {
    return c1->cumulative_co2 - c2->cumulative_co2;
}

/**
 * sort countries by consumption_co2_per_citizens
 * @param c1 country 1
 * @param c2 country 2
 * @return > 0 if c1 > c2 or < 0 if c1 < c2
 */
int sort_by_consumption_co2_per_citizens(country *c1, country *c2) {
    return c1->consumption_co2_per_citizens - c2->consumption_co2_per_citizens;
}

/**
 * Sort countries with a comparator function
 *
 * @note https://fr.wikipedia.org/wiki/Tri_%C3%A0_bulles
 */
country *bubble_sort_opti(country array_to_be_sort[], int size, int comparator(country *, country *)) {
    for (int i = size; i > 1; --i) {
        bool sorted = true;
        for (int j = 0; j <= i; ++j) {
            if (comparator(&array_to_be_sort[j], &array_to_be_sort[j + 1]) < 0) {
                country temp = array_to_be_sort[j];
                array_to_be_sort[j] = array_to_be_sort[j + 1];
                array_to_be_sort[j + 1] = temp;
                sorted = false;
            }
        }
        if (sorted) {
            break;
        }
    }
    return array_to_be_sort;
}

/**
 * Extract country data from a line
 * @param line line to extract data from
 * @param current_country country to fill
 */
void extract_data_from_line(char *line, country *current_country) {
    char consumption_co2_char[10];
    sscanf(line, "%[^,],%[^,],%d,%f,%[^,],%f,%d", current_country->iso, current_country->name, &current_country->year,
           &current_country->co2, consumption_co2_char,
           &current_country->cumulative_co2, &current_country->population);
    current_country->consumption_co2 = consumption_co2_char[0] == '?' ? -1 : atof(consumption_co2_char);
    current_country->consumption_co2_per_citizens = current_country->consumption_co2 == -1 ? -1 :
                                                    current_country->consumption_co2 / current_country->population *
                                                    1000000;
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
            extract_data_from_line(line, &countries[i]);
        }

        bubble_sort_opti(countries, line_count, &sort_by_consumption_co2);

        printf("\n\nSorted by consumption CO2:\n");
        // print the 15 first countries
        for (int i = 0; i < 15; ++i) {
            display_country(&countries[i]);
        }

        bubble_sort_opti(countries, line_count, &sort_by_co2);
        printf("\n\nSorted by CO2:\n");
        // print the 15 first countries
        for (int i = 0; i < 15; ++i) {
            display_country(&countries[i]);
        }

        bubble_sort_opti(countries, line_count, &sort_by_cumulative_co2);
        printf("\n\nSorted by cumulative CO2:\n");
        // print the 15 first countries
        for (int i = 0; i < 15; ++i) {
            display_country(&countries[i]);
        }

        bubble_sort_opti(countries, line_count, &sort_by_consumption_co2_per_citizens);
        printf("\n\nSorted by consumption CO2 per citizens:\n");
        // print the 15 first countries
        for (int i = 0; i < 15; ++i) {
            display_country(&countries[i]);
        }

        fclose(file);
    } else {
        printf("File not found");
    }
}



