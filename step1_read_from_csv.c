#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    file = fopen("/Users/maelkerichard/CLionProjects/sys-tp-10-11-12/owid-co2-data-excerpt.csv", "r");
    if (file) {
        char line[1024];
        fgets(line, sizeof(line), file); //skip first line
        while (fgets(line, sizeof(line), file)) {
            char iso[10];
            char country[50];
            char consumption_co2_char[10];
            float consumption_co2;
            int year, population;
            float co2, cumulative_co2;

            sscanf(line, "%[^,],%[^,],%d,%f,%[^,],%f,%d", iso, country, &year, &co2, consumption_co2_char,
                   &cumulative_co2, &population); //extract data from line

            // if consumption_co2 is missing, set it to -1
            if (consumption_co2_char[0] == '?') {
                consumption_co2 = -1;
            } else {
                consumption_co2 = atof(consumption_co2_char);
            }

            if (consumption_co2 == -1) {
                printf("No data available on the consumption CO2 caused by %s in %d.\n", country,
                       year); //print message if consumption_co2 not available
            } else {
                printf("%s caused %f million tons of CO2 in %d.\n", country, consumption_co2,
                       year); //print message if consumption_co2 available
            }

        }
        fclose(file);
    } else {
        printf("File not found");
    }
}