/*
 * @author Anger
 * @date 2023/3/23
 * @brief 值交换
 */
#include <stdio.h>

void inplace_swap(int *x, int *y);

void reverse_array(int a[], int cnt);

int main() {

    int a[] = {1, 2, 3, 4, 5};

    reverse_array(a, 5);

    int b[] = {1, 2, 3, 4};

    reverse_array(b, 4);

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
        printf("%d ", a[i]);

    printf("\n");

    for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i)
        printf("%d ", b[i]);

    return 0;
}

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y; /* 第一步 */
    *x = *x ^ *y; /* 第二步 */
    *y = *x ^ *y; /* 第三步 */
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first < last; ++first, --last)
        inplace_swap(&a[first], &a[last]);
}
