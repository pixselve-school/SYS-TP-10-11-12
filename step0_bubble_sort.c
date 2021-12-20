#include <stdio.h>
#include <stdbool.h>

/**
 * @note https://fr.wikipedia.org/wiki/Tri_%C3%A0_bulles
 */
int *bubble_sort(int array_to_be_sort[], int size) {
    for (int i = size; i > 1; --i) {
        for (int j = 0; j <= i; ++j) {
            if (array_to_be_sort[j + 1] < array_to_be_sort[j]) {
                int temp = array_to_be_sort[j];
                array_to_be_sort[j] = array_to_be_sort[j + 1];
                array_to_be_sort[j + 1] = temp;
            }
        }
    }
    return array_to_be_sort;
}
/**
 * @note https://fr.wikipedia.org/wiki/Tri_%C3%A0_bulles
 */
int *bubble_sort_opti(int array_to_be_sort[], int size) {
    for (int i = size; i > 1; --i) {
        bool sorted = true;
        for (int j = 0; j <= i; ++j) {
            if (array_to_be_sort[j + 1] < array_to_be_sort[j]) {
                int temp = array_to_be_sort[j];
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


int main() {
    int array_to_be_sorted[] = {9, 2, 1, 15, 25, 27, 20, 0, 14, 9, 2, 12, 21, 40, 23, 5, 17, 29, 22, 30};
    int array_size = sizeof(array_to_be_sorted) / sizeof(array_to_be_sorted[0]);
    int* sorted_array = bubble_sort(array_to_be_sorted, array_size);
    int* sorted_array_opti = bubble_sort_opti(array_to_be_sorted, array_size);
    for (int i = 0; i < array_size; ++i) {
        printf("%d ", sorted_array[i]);
    }

    for (int i = 0; i < array_size; ++i) {
        printf("%d ", sorted_array_opti[i]);
    }

}

