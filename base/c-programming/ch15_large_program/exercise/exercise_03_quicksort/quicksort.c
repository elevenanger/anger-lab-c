/*
 * @author Anger
 * @date 2022/9/22
 */
#include "quicksort.h"

void quick_sort(int a[], int low, int high) {
    int middle;
    if (low >= high) return;
    middle = split(a, low, high);
    quick_sort(a, low, middle);
    quick_sort(a, middle + 1, high);
}

int split(int a[], int low, int high) {

    int part_element = a[low];

    for (;;) {
        while (low < high && part_element <= a[high])
            high--;

        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= part_element)
            low++;
        if (low >= high) break;
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}
