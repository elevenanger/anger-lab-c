/*
 * @author Anger
 * @date 2022/10/16
 * 使得一个 32 的值即可以看做一个 float 类型的值
 * 也可以看做 14 中定义的结构
 * 写一个程序，将 1 存储在结构中的符号字段
 * 将 128 存储在指数字段
 * 0 存储在小数字段
 * 然后按 float 值的形式显示存储在联合的值
 */
#include <stdio.h>

typedef struct {
    unsigned int decimal:23;
    unsigned int exponent:8;
    unsigned int sign:1;
} float_struct;

typedef union {
    float f;
    float_struct value;
} float_type;

int main(void) {

    float_type ft;
    ft.value.sign = 1;
    ft.value.decimal = 0;
    ft.value.exponent = 128;

    printf("ft.f = %g", ft.f);
    return 0;
}