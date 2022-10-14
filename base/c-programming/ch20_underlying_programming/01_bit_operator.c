/*
 * @author Anger
 * @date 2022/10/14
 * @brief 位运算符
 */
#include <stdio.h>

void shift_operators(void);
void bit_reverse_operator(void);
void bit_and_operator(void);
void bit_or_operator(void);
void bit_xor_operator(void);

int main(void) {

    shift_operators();

    bit_reverse_operator();

    bit_and_operator();

    bit_or_operator();

    bit_xor_operator();

    return 0;
}

/**
 * 移位运算符，可以是任意整数类型
 * 移位运算符的优先级低于算术运算符
 * 如果操作数是负数
 * 移位运算符的结果视具体的实现而定
 * 为了可移植性，最好仅对无符号数进行移位运算
 * << 左移位
 * i << j 将 i 中的位左移 j 位后的结果
 * 每次从 i 的最左端溢出一位
 * 在 i 的最右端补一个 0 位
 * >> 右移位
 */
void shift_operators(void) {
    int i = 9, j = 2;

    printf("%d << %d = %d\n", i, j, i << j);
    printf("%d >> %d = %d\n", i, j, i >> j);

    /* 移位运算符不会改变操作数
     * 如果需要移位改变变量，需要使用复合运算符 <<= >>= */
    i <<= j;
    printf("i = %d\n", i);
    i >>= j;
    printf("i = %d\n", i);
}

/**
 * 按位取反运算符 ~
 * 一元运算符
 */
void bit_reverse_operator(void) {
    int i = 0;
    printf("~%d = %d\n", i, ~i);
}

/**
 * 按位与运算符 &
 */
void bit_and_operator(void) {
    int i = 3, j = 5;
    printf("%d & %d = %d\n", i, j, i & j);
    i &= j;
    printf("i = %d\n", i);
}

/**
 * 按位或运算符 |
 */
void bit_or_operator(void) {
    int i = 3, j = 5;
    printf("%d | %d = %d\n", i, j, i | j);
    i |= j;
    printf("i = %d\n", i);
}

/**
 * 按位异或运算符 ^
 */
void bit_xor_operator(void) {
    int i = 3, j = 5;
    printf("%d ^ %d = %d\n", i, j, i ^ j);
    i ^= j;
    printf("i = %d\n", i);
}