/*
 * 整数类型
 * 整数类型分为两大类
 * 有符号整数和无符号整数
 * 默认情况下 c 语言的整数都是有符号的
 * 如果需要无符号的整数
 * 需要声明为 unsigned 类型
 */
#include <stdio.h>

void integer_type() {
    /* 只有这几种整数类型是有意义的 */
    int i;
    unsigned int ui;
    short int si; /* 短整型 */
    unsigned short int us;
    long int li; /* 长整型 */
    unsigned long int ul;
    /* c 语言允许省略 int 来声明整数类型 */
    short int s;
    long int l;
    /* C99 标准额外的两种整数类型 */
    long long int lli;
    unsigned long long int ulli;
    long long ll;
    unsigned long long ull;
}

/**
 * c 语言中常量以整数的形式出现
 * 而不是读、写或者计算出来的数
 * C 语言允许十进制、八进制和十六进制形式书写整数常量
 */
void integer_constant_value() {
    123456789; /* 十进制由 0~9 的数字组成 */
    01234567; /* 八进制以 0 开头， 0 ~ 7 的数字的数字组成 */
    0x123456789abcdef; /* 十六进制以 0x 开头 0~9 和 a~f 组成,字母可以是大写也可以是小写 */

    0xFFFL; /* 在常量后面加上 L 强制编译器将常量当做长整型来处理 */
    123U; /* 在常量后面加上 U 强制编译器将常量当做无符号数来处理 */
    0xFFFUL; /* UL可以组合使用，说明常量是无符号的长整型 */
}

/**
 * 对整数进行读写时
 * 需要一些新的转换说明符
 * u 表示无符号
 * o 表示八进制形式
 * x 表示十六进制形式
 * h 表示短整数
 * l 表示长整数
 * ll 表示 C99 长长整数
 */
void read_and_write_integer() {
    unsigned int u;
    puts("Enter unsigned int : ");
    scanf("%u", &u);
    printf("unsigned int u : %u\n", u);
    printf("unsigned int u octal : %o\n", u);
    printf("unsigned int u hex : %x\n", u);

    /*
     * 读写短整型在 u o x d 前面加上 h
     */
    unsigned short s = 1234;
    printf("unsigned short s : %hu\n", s);
    printf("unsigned short s octal : %ho\n", s);
    printf("unsigned short s hex : %hx\n", s);

    /* 读写长整型在 d o u x 前面加上 l */
    long l = 12345l;
    printf("long l : %ld\n", l);
    printf("long l octal : %lo\n", l);
    printf("long l hex : %lx\n", l);

    /* 读写长长整型在前面加上 ll */
    long long ll = 1234567ll;
    printf("long long ll : %lld\n", ll);
    printf("long long ll octal : %llo\n", ll);
    printf("long long ll hex : %llx\n", ll);
}

int main(void) {

    read_and_write_integer();

    return 0;
}