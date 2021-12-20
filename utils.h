//
// Created by Mael Kerichard on 20/12/2021.
//

#ifndef SYS_TP_10_11_12_UTILS_H
#define SYS_TP_10_11_12_UTILS_H

#endif //SYS_TP_10_11_12_UTILS_H

typedef struct {
    char iso[10];
    char name[50];
    float consumption_co2, co2, cumulative_co2, consumption_co2_per_citizens;
    int year, population;
} country;

extern void display_country(country *country);

extern int sort_by_consumption_co2(country *c1, country *c2);

extern int sort_by_co2(country *c1, country *c2);

extern int sort_by_cumulative_co2(country *c1, country *c2);

extern int sort_by_consumption_co2_per_citizens(country *c1, country *c2);

extern country *bubble_sort_opti(country array_to_be_sort[], int size, int comparator(country *, country *));

extern void extract_data_from_line(char *line, country *current_country);