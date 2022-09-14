/**
 * 修改 11.4 的 max_min() 函数
 * 使用指针而不是整数来追踪数组中的当前位置
 */
#include <stdio.h>

void max_min(const int *a, int n, int *max, int *min);

int main(void) {
    int arr[] = {35, 23, 32, 232, 32323},
                max, min, n = 5;
    max_min(arr, n, &max, &min);

    printf("max => %d min => %d\n", max, min);
    return 0;
}

void max_min(const int *a, int n, int *max, int *min) {
    *max = *min = a[0];
    while (n-- > 0) {
        if (*max < a[n])
            *max = a[n];
        if (*min > a[n])
            *min = a[n];
    }
}
