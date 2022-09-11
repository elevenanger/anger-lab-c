/*
 * @author Anger
 * @date 2022/9/8
 * @brief 用户输入一串整数（存储在数组中）
 * 通过调用 selection_sort 函数排序这些整数
 * 搜索数组找出最大的整数，把它移动到数组的最后
 * 递归调用函数本身来对前 n - 1 个数字排序
 */
#include <stdio.h>

void selection_sort(int n, int a[]) {
    int max = a[0], i = 0;
    for (int j = 1; j < n; ++j)
        if (max < a[j]) {
            max = a[j];
            i = j;
        }
    a[i] = a[n - 1];
    a[n - 1] = max;
    if (--n > 0)
        selection_sort(n, a);
}

int main(void) {

    int a[100], n, i = 0;

    printf("Enter a series integer : ");
    while (getchar() != '\n') {
        scanf("%d", &n);
        a[i] = n;
        i++;
    }

    selection_sort(i, a);

    for (int j = 0; j < i; ++j) {
        printf("%d ",a[j]);
    }

    return 0;
}
