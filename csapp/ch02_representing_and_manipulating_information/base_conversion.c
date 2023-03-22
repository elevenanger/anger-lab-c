/*
 * @author Anger
 * @date 2023/3/22
 * @brief  进制转换
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 基于 2 的指数进行转换
 * @param power 次幂
 */
void power_conversion(int power);

/**
 * 基于 10 进制进行转换
 * @param decimal
 */
void decimal_conversion(int decimal);

/**
 * 十进制的数字以二进制输出
 * @param decimal
 */
void decimal_to_binary(int decimal);

void mixed_addition();

int main() {

    int powers[] = {5, 23, 15, 13, 12, 6, 8};

    for (int i = 0; i < sizeof(powers) / sizeof(powers[0]); ++i)
        power_conversion(powers[i]);

    int decimals[] = {158, 76, 145, 174, 60, 241, 117, 189, 245};

    for (int i = 0; i < sizeof(decimals) / sizeof(decimals[0]); ++i)
        decimal_conversion(decimals[i]);

    mixed_addition();

    return 0;
}

void power_conversion(int power) {
    int num;
    if (power == 0)
        num = 0;
    else
        num = 1 << power;
    printf("2^%d:\n", power);
    printf("decimal => %d\n", num);
    printf("hexadecimal => %x\n", num);
}

void decimal_conversion(int decimal) {
    printf("十进制 => %d\n", decimal);
    printf("二进制 => ");
    decimal_to_binary(decimal);
    printf("十六进制 => %x\n", decimal);
}

void decimal_to_binary(int decimal) {
    char *s = malloc(sizeof(char) * 64), i;

    for (i = 0; decimal != 0; ++i) {
        s[i] = (char) (decimal % 2);
        decimal /=2;
    }

    while (--i >= 0)
        printf("%d", s[i]);

    printf("\n");
}

void mixed_addition() {
    printf("%x + %x = %x\n", 0x605c, 0x5, 0x605c + 0x5);
    printf("%x - %x = %x\n", 0x605c, 0x20, 0x605c - 0x20);
    printf("%x + %d = %x\n", 0x605c, 32, 0x605c + 32);
    printf("%x - %x = %x\n", 0x60fa, 0x605c, 0x60fa - 0x605c);
}
