/*
 * @author Anger
 * @date 2022/9/13
 * @brief 数组名作为指针
 */
#include <stdio.h>

void array_name_as_pointer(void);

void pointer_as_array_name(void);

int find_largest(const int *a, int n);

int main(void) {
    array_name_as_pointer();
    pointer_as_array_name();
    printf("largest number => %d\n", find_largest((int []){0, 1, 2}, 3));
    int a[5] = {1, 2, 3, 4, 5};
    /* 将数组的片段作为实参传递给数组变量 */
    printf("largest number => %d\n", find_largest(&a[2], 3));
    return 0;
}

/**
 * 可以把数组的名字作为指向数组第一个元素的指针
 */
void array_name_as_pointer(void) {
    int a[5] = {};
    /* *a 指向数组的第一个元素
     * *(a+i) 等价于 a[i] */
    *a = 7;
    printf("a[0] => %d\n", a[0]);
    *(a + 1) = 10;
    printf("a[1] => %d\n", a[1]);

    int sum = 0;
    for (int *p = a; p < a + 5; p++)
        sum += *p;
    printf("sum => %d\n", sum);
}

/**
 * 查找数组中的最大值
 * 通过将数组的某个元素的指针赋值给指针变量改进数组作为参数的写法
 * 把数组形参视为指针将产生很多重要的结果：
 * 给函数传递普通变量时，变量的值会被复制
 * 任何相应的形参的变化都不会影响到变量
 * 因为没有对数组本身进行复制
 * 所以作为实参的数组是可能被改变的
 * 为了指明数组不会被改变可以加上 const 关键字
 * 给函数传递数组所需的时间与数组的大小无关
 * 因为没有对数组进行复制
 * 所以传递大数组也不会有什么影响
 * 可以给形参为数组的函数传递数组的 片段
 * 所谓片段就是指连续的数组元素组成的序列
 * @param a 将数组的第一个元素的指针赋值给 a
 * @param n 数组长度
 * @return 最大的元素
 */
int find_largest(const int *a, int n) {
    int largest = *a;
    for (const int *p = a; p < a + n; p++)
        if (largest < *p)
            largest = *p;
    return largest;
}

/**
 * 将指针作为数组名
 */
void pointer_as_array_name(void) {
    int *p, a[5] = {1, 2, 3, 4, 5}, sum = 0;
    p = a;
    for (int i = 0; i < 5; ++i)
        /* 将指针作为数组名使用
         * p[i] 等价于 *(p + i)*/
        sum += p[i];
    printf("sum => %d\n", sum);
}
