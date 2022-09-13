/*
 * @author Anger
 * @date 2022/9/13
 * @brief 指针的算数运算
 * c 语言允许对于指针使用算数运算（加法和减法）
 * 通过算数运算可以使用指针替代数组下标对数组进行处理
 * 指针的算数运算包括：
 * 1、指针加上整数
 * 2、指针减去整数
 * 3、两个指针相减
 * 指针的比较：
 * 指针可以使用关系运算符 (< <= > >=) 和判等运算符 (== !=) 进行比较
 * 只有在两个指针指向同一个数组时，用关系运算符比较指针才有意义
 */
#include <stdio.h>

#define SIZE(a) (int) (sizeof(a) / sizeof(a[0]))

void pointer_add_integer(void);

void pointer_sub_integer(void);

void pointer_sub_pointer(void);

void pointer_compare(void);

void pointer_to_compound_literal(void);

int main(void) {
    pointer_add_integer();
    pointer_sub_integer();
    pointer_sub_pointer();
    pointer_compare();
    pointer_to_compound_literal();
    return 0;
}

void pointer_add_integer(void) {
    int a[10] = {0}, *p, *q, i;
    /* 将 p 赋值为数组中第二个元素的指针 */
    p = &a[1];
    /* 使用间接寻址运算符对数组中的第二个元素进行操作 */
    *p += 3;
    /* 指针加上整数，产生指向特定元素的指针
     * 这个特定元素是 p 原来指向的那个元素后的第 j 个位置
     * 如果 p 指向 a[i]
     * 那么 p + j 指向 a[i + j]
     * 前提是 a[i + j] 必须存在
     * 所以 q 指向的数组中的第五个元素 */
    q = p + 3;
    *q += 3;
    p += 6;
    *p += 3;
    for (i = 0; i < SIZE(a); ++i)
        printf("%d ", a[i]);
    puts("");
}

void pointer_sub_integer(void) {
    int a[10] = {0}, *p, *q, i;
    p = &a[9];
    *p += 3;
    /* 如果 p 指向的元素是 a[i]
     * 那么 p - j 指向的元素就是 a[i - j]*/
    q = p - 3;
    *q += 3;
    for (i = 0; i < SIZE(a); ++i)
        printf("%d ", a[i]);
    puts("");
}

void pointer_sub_pointer(void) {
    int a[10] = {0}, *p, *q;
    p = &a[9];
    q = &a[1];
    /* 两个指针相减的结果是两个指针之间的距离（用数组的元素个数来度量）
     * p 指向 a[i] q 指向 a[j]
     * p - q = i - j
     * 指针指向的元素必须是数组中存在的元素
     * 两个指针需要指向同一个数组，它们之间相减才有意义 */
    printf("p - q => %ld\n", p - q);
}

/**
 * 指针比较
 * 只有在同一个数组中使用指针的比较运算符才有意义
 * 使用比较运算符比较的结果依赖于数组中两个指针的相对位置
 * 使用判等运算符比较的结果依赖于两个指针的相对位置
 */
void pointer_compare(void) {
    int a[10] = {0}, *p, *q;
    p = &a[9];
    q = &a[1];
    /* 使用比较运算符比较指针 */
    printf("p > q => %d\n", p > q);
    printf("p >= q => %d\n", p >= q);
    printf("p < q => %d\n", p < q);
    printf("p <= q => %d\n", p <= q);
    /* 使用判等运算符比较指针 */
    printf("p == q => %d\n", p == q);
    printf("p != q => %d\n", p != q);
}

/**
 * C99 特性
 * 指向复合字面量的指针
 */
void pointer_to_compound_literal(void) {
    /* 定义 p 指针，指向匿名数组（复合字面量）
     * 此时 p 指向的是数组中的第一个元素 */
    int *p = (int []) {3, 2, 1, 4, 5};
    printf("*p => %d\n", *p);
    printf("*(p + 1) => %d\n", *(p + 1));
}
