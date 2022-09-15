/*
 * @author Anger
 * @date 2022/9/14
 * @brief 对数组进行排序
 */
#include <stdio.h>

void quick_sort(int *a, int *low, int *high);
int* split(int *low, int *high);

int main(void) {
    int arr[] = {10, 8, 9, 2, 3, 7},
                *low = &arr[0], *high = &arr[5];
    quick_sort(arr, low, high);
    for (int *q = arr; q < arr + 6; q++)
        printf("%d ", *q);
    return 0;
}

void quick_sort(int *a, int *low, int *high) {
    int *middle;
    if (low - high >= 0) return;
    middle = split(low, high);
    quick_sort(a, low, middle);
    quick_sort(a, middle + 1, high);
}

int* split(int *low, int *high) {
    int part_element = *low;
    for (;;) {
        while (low < high && part_element <= *high)
            high--;
        if (low >= high) break;
        *low++ = *high;

        while (low < high && *low <= part_element)
            low++;
        if (low >= high) break;
        *high-- = *low;
    }

    *high = part_element;
    return high;
}
