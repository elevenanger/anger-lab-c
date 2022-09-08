/*
 * @author Anger
 * @date 2022/9/7
 * @brief 函数递归 如果函数调用它本身，那么此函数就是递归的
 */
#include <stdio.h>

int split(int a[], int low, int high);
void quick_sort(int a[], int low, int high);

/**
 * 递归计算阶乘
 * 为了防止无线递归
 * 所有的递归函数都需要有某种类型的终止条件
 */
int factorial(int n) {
    return n<= 1? 1 :n * factorial(n - 1);
}

/**
 * 递归求次幂
 */
int power(int x, int n) {
    return n == 0 ? 1: x * power(x, n - 1);
}

/**
 * 快速排序算法
 * 递归经常作为分治法的结果自然出现
 * 分治法指的是将一个大问题分割为多个较小的问题
 * 然后采用相同的算法分别解决这些小问题
 * 1、low 指向数组的第一个元素 high 指向数组的最后一个元素
 * 2、把第一个元素作为分割元素，将其复制给其它地方的一个临时存储单元，在数组中留下一个空位
 * 3、然后从右向左移动 high 直到 high 指向小于分割元素的数时停止然后把这个数复制给空出来的空位
 * 4、这时 high 指向的位置将会变成空位
 * 5、从左到右移动 low 寻找大于分割元素的数
 * 6、一旦找到，将这个数复制到 high 空位指向的位置
 * 7、重复执行此过程，直到 low 和 high 两者在数组中的某处相遇时停止
 * 8、此时 low 和 high 都指向空位，只要把分割元素复制给空位即可
 * @param a 需要排序的数组
 * @param low 低位标记
 * @param high 高位标记
 */
void quick_sort(int a[], int low, int high) {
    int middle;
    if (low >= high) return;
    middle = split(a, low, high);
    quick_sort(a, low, middle);
    quick_sort(a, middle + 1, high);
}

int split(int a[], int low, int high) {
    /* 将低位的元素提取出来 */
    int part_element = a[low];
    for (;;) {
        /* 循环比较低位元素和高位元素的值
         * 每次比较完高位索引减一
         * 比较低位索引是否小于高位索引
         * 如果二者相等则说明已经遍历了中间所有的元素,终止当前 while 循环
         * 并且低位的值是否小于当前高位索引的值
         * 如果找到高位索引的值小于低位索引的值则终止当前 while 循环
         */
        while (low < high && part_element <= a[high])
            high--;
        /* 如果最终低位索引等于或者大于高位索引，说明遍历完所有元素，直接终止整个循环*/
        if (low >= high) break;
        /* 将低位索引的值替换为高位索引的值
         * 低位索引 + 1*/
        a[low++] = a[high];

        /* 低位索引的值与元素比较
         * 是否低位索引的值小于元素
         * 每次比较完低位索引 +1
         * 直到低位索引的值大于高位索引的值或者低位索引与当前高位重合
         */
        while (low < high && a[low] <= part_element)
            low++;
        if (low >= high) break;
        /* 将高位索引的值替换为低位索引的值
         * 高位索引 -1*/
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}

void test_quick_sort() {
    int a[5] = {1, 3, 2, 10, 7};
    quick_sort(a, 0, 4);
    for (int i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }
}

int main(void) {

    int n = 5;

    printf("factorial of %d => %d\n", n, factorial(n));
    printf(" %d power to %d => %d\n", n, n, power(n, n));

    test_quick_sort();

    return 0;
}
