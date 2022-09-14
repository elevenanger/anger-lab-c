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
    /* 将低位的元素提取出来 */
    int part_element = *low;
    for (;;) {
        /* 循环比较低位元素和高位元素的值
         * 每次比较完高位索引减一
         * 比较低位索引是否小于高位索引
         * 如果二者相等则说明已经遍历了中间所有的元素,终止当前 while 循环
         * 并且低位的值是否小于当前高位索引的值
         * 如果找到高位索引的值小于低位索引的值则终止当前 while 循环
         */
        while (low < high && part_element <= *high)
            high--;
        /* 如果最终低位索引等于或者大于高位索引，说明遍历完所有元素，直接终止整个循环*/
        if (low >= high) break;
        /* 将低位索引的值替换为高位索引的值
         * 低位索引 + 1*/
        *low++ = *high;

        /* 低位索引的值与元素比较
         * 是否低位索引的值小于元素
         * 每次比较完低位索引 +1
         * 直到低位索引的值大于高位索引的值或者低位索引与当前高位重合
         */
        while (low < high && *low <= part_element)
            low++;
        if (low >= high) break;
        /* 将高位索引的值替换为低位索引的值
         * 高位索引 -1*/
        *high-- = *low;
    }

    *high = part_element;
    return high;
}
