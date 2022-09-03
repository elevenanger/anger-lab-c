/*
 * 浮点型
 */
#include <stdio.h>

/**
 * 三种浮点格式
 * float 单精度浮点型
 * double 双精度浮点型
 * long double 扩展精度浮点型
 * c 语言没有说明浮点型的精度具体是多少
 * 因为不同的计算机使用不同的方法存储浮点数
 * 大多数现代计算机都遵循 IEEE 754 标准
 * 标准定义了单精度和双精度两种主要的浮点格式
 * 单精度 32 位 双精度 64 位
 * 数值以科学计数法的形式存储
 * 每一个数由三个部分组成
 * 符合 指数 和 小数
 * 单精度格式中
 * 指数长度为 8 位
 * 小数部分为 23 位
 */
void float_type() {
    float f = 1.22f;
    double d = 1.22;
    long double ld = 1.22l;
}

/**
 * 浮点数常量的书写格式
 * 浮点常量必须包括小数或者指数
 * 指数说明了对前面的数进行缩放所需的10的幂次
 * 如果有指数需要再指数次幂前面放置 E 或者 e
 * 可选符号放在 e(E) 后面
 * 浮点常量默认以双精度格式 double 进行存储
 * 为了表明单精度可以在常量后面加上 f 或者 F
 * 为了说明常量必须以长双精度进行存储需在常量后面加上 l
 */
void float_type_constant() {
    1.22;
    1.22e0; /* 对前面进行缩放的10的次幂 */
    122e-2;
    0.122e+1;
    1.22F; /* 表明单精度 */
    1.22L;
}

/**
 * 读写浮点数需要加上转换说明符
 * e f g 用于读写单精度浮点数
 */
void read_and_write_float() {
    float f = 1.22f;
    printf("float f %f : \n", f);
    printf("float f %e : \n", f);
    printf("float f %g : \n", f);

    /*
     * 读写 double 类型浮点数
     * 在 e f g 前面加上 l
     * @notice 只能在 scanf() 函数格式串中使用 l
     * 在 printf() 函数中 e f g 可以用来转换 float 或者 double 类型数值
     * C99 允许在 printf() 函数中使用 l 但是实际上不起作用
     */
    double d;
    puts("input double float number : ");
    scanf("%lf", &d);
    printf("double d : %f\n", d);
    printf("double d : %lf\n", d);

    /*
     * 读写 long double 类型值
     * 加上大写 L
     */
    long double ld = 1.22e3l;
    printf("long double ld : %Lf", ld);
}

int main(void) {
    read_and_write_float();
    return 0;
}