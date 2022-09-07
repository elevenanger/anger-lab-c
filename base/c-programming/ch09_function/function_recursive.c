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
    int part_element = a[low];
    for (;;) {
        while (low < high && part_element <= a[high])
            high--;
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= part_element)
            low++;
        if (low >= high) break;
        a[high--] = low;
    }

    a[high] = part_element;
    return high;
}

int main(void) {

    int n = 5;

    printf("factorial of %d => %d\n", n, factorial(n));
    printf(" %d power to %d => %d\n", n, n, power(n, n));

    return 0;
}
