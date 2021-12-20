//
// Created by Mael Kerichard on 20/12/2021.
//

#include <stdio.h>
#include "utils.h"

int const line_count = 215;

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