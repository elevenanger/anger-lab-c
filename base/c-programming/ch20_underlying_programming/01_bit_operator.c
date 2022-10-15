/*
 * @author Anger
 * @date 2022/10/14
 * @brief 位运算符
 */
#include <stdio.h>
#include <ctype.h>

void shift_operators(void);
void bit_reverse_operator(void);
void bit_and_operator(void);
void bit_or_operator(void);
void bit_xor_operator(void);
void access_bit_by_bit_operator(void);
void access_bit_field_by_bit_operator(void);
void xor_encrypt(char *orig_str, const char xor_char);

int main(void) {

    shift_operators();

    bit_reverse_operator();

    bit_and_operator();

    bit_or_operator();

    bit_xor_operator();

    access_bit_by_bit_operator();

    access_bit_field_by_bit_operator();

    char *message = "this is the one .";
    char xor_char = '&';
    xor_encrypt(message, xor_char);
    xor_encrypt("RNOU OU RNC IHC .", xor_char);

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

/**
 * 使用位运算符访问位
 */
void access_bit_by_bit_operator(void) {
    printf("用位运算符访问位\n");
    /* 位的设置
     * 需要设置数值的第 i 位
     * 则湿的数值与第 i 位为 1 的数值进行或运算*/
    unsigned short s = 0x0000, i = 0x0010, j = 4;
    printf("%d |= %d  = %d\n", s, i, s |= i);
    s = 0x0000;
    /* 惯用法，j 为需要操作的位数 */
    printf("%d |= 1 << %d = %d\n", s, j, s |= 1 << j);

    /* 位的清除
     * 清楚第 i 位
     * 使用第 i 位为 0 ，其余位为 1 的掩码进行与运算
     * 0x00ff => 0000 0000 1111 1111
     * 0x0010 => 0000 0000 0001 0000
     * ~0x0010 => 1111 1111 1110 1111
     * 清除第 4 位 */
    s = 0x00ff;
    i = 0x0010;
    printf("%d & ~%d = %d\n", s, i, s & ~i);
    /* 以上运算可以相应进行简化
     * s &= ~(1 << j)
     * j 是需要清除的位数 */
    j = 4;
    printf("%d & ~(1 << %d) = %d\n", s, j, s &= ~(1 << j));

    /* 检查第 i 位有没有被设置
     * s & 1 << i */
    printf("%d & 1 << %d = %d\n", s, j, s & 1 << j);
}

void access_bit_field_by_bit_operator(void) {
    printf("用位运算符访问位域\n");
    /* 位域:一组连续的位
     * 修改位域
     * 修改位域需要将位域先按位与（用来清除位）
     * 接着按位或来将新的位存入位域
     * 将二进制值 1001 设置为 0x0019 的 4-7 位
     * 0x0019 0000 0000 0001 1001
     * 0x0090 0000 0000 1001 0000
     * 0x00f0 0000 0000 1111 0000
     * 0x0099 0000 0000 1001 1001
     * 先清除 0x0019 要设置的位
     * 要设置的位数为 4-7 位
     * 则将 0x0019 和 ~0x00f0 进行与运算
     * 0x0019 & ~0x00f0
     * 然后将需要设置的值设置到指定的位
     * 1001 设置到 4-7 位
     * 对应 0x0090 0000 0000 1001 0000
     * 将 0x0019 & ~0x00f0 和 0x0090 进行或运算
     * 0x0019 & ~0x00f0 | 0x0090 */
    short i = 0x0019;
    printf("i & ~0x00f0 | 0x0090 = %d\n",
           i & ~0x00f0 | 0x0090);
    printf("0x0099 = %d\n", 0x0099);

    /* 获取位域
     * i = 0x00f9 0000 0000 1111 1001
     * 获取 i 的 0-3 位 : i & 0x000f
     * 获取 i 的 4-7 位
     * 因为不是在数值的最右端，需要先把其实位置移动到最右边
     * 将 i 的第 4 位移动到最右边（第 1 位）i >> 4
     * 然后与 0x000f 进行与运算 (i >> 4) & 0x000f */
    i = 0x00f9;
    printf("获取 i 的第 0 ~ 3 位：i & 0x000f = %d\n",
           i & 0x000f);
    printf("获取 i 的第 4 ~ 7 位：(i >> 4) & 0x000f = %d\n",
           (i >> 4) & 0x000f);
}

void xor_encrypt(char *orig_str, const char xor_char) {
    for (char *p = orig_str; *p != '\0'; p++) {
        if (isprint(*p) && isprint(*p ^ xor_char))
            putchar(*p ^ xor_char);
        else
            putchar(*p);
    }
    puts("");
}