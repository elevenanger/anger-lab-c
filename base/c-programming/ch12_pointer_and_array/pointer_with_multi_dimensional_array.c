/*
 * @author Anger
 * @date 2022/9/13
 * @brief 指针与多维数组
 */
#include <stdio.h>
#define ROW 2
#define COL 3

void manipulate_multi_dimensional_array_element_with_pointer(void);

void manipulate_multi_dimensional_array_rows_with_pointer(void);

void manipulate_multi_dimensional_array_cols_with_pointer(void);

void multi_dimensional_array_name_as_pointer(void);

int main(void) {
    manipulate_multi_dimensional_array_element_with_pointer();
    manipulate_multi_dimensional_array_rows_with_pointer();
    manipulate_multi_dimensional_array_cols_with_pointer();
    multi_dimensional_array_name_as_pointer();
    return 0;
}

/**
 * 使用指针处理多维数组的元素
 * c 语言按照行序存储多维数组中的元素
 * 将指针指向多维数组的第一个元素
 * 可以使用自增指针来遍历多维数组中的每一个元素
 */
void manipulate_multi_dimensional_array_element_with_pointer(void) {
    printf("manipulate_multi_dimensional_array_element_with_pointer\n");
    int *p, a[ROW][COL] = {0};

    /* 精简多维数组遍历的写法，不需要嵌套多个 for 循环
     * 一个 for 循环即可
     * 将指针 p 指向多维数组的第一个元素
     * 指针 p <= 多维数组的最后一个元素的指针
     * 遍历数组
     */
    for (p = &a[0][0]; p <= &a[ROW - 1][COL - 1]; p++)
        *p = 1;
}

/**
 * 使用指针操作多维数组中某一行的元素
 * p = &a[i][0] 指向第 i 行的第一个元素
 * p = &a[i][col - 1] 指向第 i 行的最后一个元素
 */
void manipulate_multi_dimensional_array_rows_with_pointer(void) {
    printf("manipulate_multi_dimensional_array_rows_with_pointer\n");
    int *p, a[ROW][COL] = {0};
    for (p = &a[1][0]; p < &a[1][COL]; p++)
        *p = 1;
}

/**
 * 处理多维数组的列
 */
void manipulate_multi_dimensional_array_cols_with_pointer(void) {
    printf("manipulate_multi_dimensional_array_cols_with_pointer\n");
    /* 首先将 p 声明为指向长度为 COL 列数的数组的指针 i 是要处理的列索引*/
    int a[ROW][COL] = {0}, (*p)[COL], i = 2;
    /* p 首先指向多维数组 a[0] 代表 a 的第一行
     * 表达式 p++ 将 p 移动到下一行的起始位置
     * i 表示需要操作的列数
     * p[i] 即表示当前行的第 i 个元素
     * (*p)col 是需要括号的
     * 如果没有括号，编译器会认为 p 是指针数组
     * 这里需要的是这一行的数组，即 *p
     * 而不是指向数组的指针 */
    for (p = &a[0]; p < &a[ROW]; p++)
        (*p)[i] = 1;

    for (int *q = &a[0][0]; q <= &a[ROW - 1][COL - 1]; q++)
        printf("%d ", *q);
    puts("");
}

/**
 * 使用多维数组名作为指针
 * 数组名 a 指向的不是 a[0][0] 的指针
 * 而是指向 a[0] 的指针
 * C 语言认为 a 是一个一维数组
 * 而这个数组的每个元素又是元素个数为 COL 的一维数组
 * 用作指针时 a 的类型是 int(*)[COL]
 * 知道这个特性可以简化对于多维数组的列操作
 */
void multi_dimensional_array_name_as_pointer(void) {
    int a[ROW][COL] = {0}, (*p)[COL];
    for (p = &a[0]; p < &a[ROW]; p++)
        (*p)[1] = 2;
    for (int *q = &a[0][0]; q <= &a[ROW - 1][COL - 1]; q++)
        printf("%d ", *q);
    puts("");
}
