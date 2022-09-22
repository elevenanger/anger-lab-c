/*
 * @author Anger
 * @date 2022/9/22
 */
#include <stdio.h>
#include "quicksort.h"

int main(void) {
    int a[5] = {1, 3, 2, 10, 7};
    quick_sort(a, 0, 4);
    for (int i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}