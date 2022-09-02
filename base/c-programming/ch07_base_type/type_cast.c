/*
 * @author Anger
 * @date 2022/9/2
 * @brief 类型转换
 */
#include <stdio.h>

/**
 * 隐式转换
 * 当发生下列情况会进行隐式转换
 * 算术表达式或者逻辑表达式中的操作数类型不相同时
 * 赋值运算符右侧的表达式类型和左侧的变量类型不匹配时
 * 函数调用中的实参类型和漆对应的形参类型不匹配时
 * return 语句中的表达式的类型和函数返回值类型不匹配时
 *
 * 算术转换
 * 常用的算术转换策略是将操作数转换成可以安全地适用于两个数值的最狭小的数值类型
 * 如果某种类型要求的存储字的字节数比另一种字节数更少
 * 那么这种类型就比另一种更狭小
 * 为了统一操作数的类型，通常可以将狭小的操作数转换成另一操作数的类型来实现（提升）
 */
void arithmatic_cast() {
    char c;
    short int s;
    int i;
    unsigned int u;
    long int l;
    unsigned long int ul;
    float f;
    double d;
    long double ld;
    i = i + c; /* c is converted to int */
    i = i + s; /* s is converted to int */
    u = u + i; /* i is converted to unsigned int */
    l = l + u; /* u is converted to long int */
    ul = ul + l;  /* l is converted to unsigned long int */
    f = f + ul; /* ul is converted to float */
    d = d + f; /* f is converted to double */
    ld = ld + d; /* d is converted to long double */
}

/**
 * 赋值转换
 * 将右边表达式的结果值类型转换成左值类型
 */
void assignment_cast() {
    double d = 2.11;
    int i = d;
    printf("%d\n", i);
}

/**
 * 强制类型转换
 * (类型名) 表达式
 * c 语言把 类型名视为一元运算符
 * 一元运算符的优先级高于二元运算符
 */
void force_type_cast() {
    float f1 = 1.22 , f2 = 2.22;
    f1 = (int) f2 + f1;
    printf("f1 = %f\n", f1);
}

int main(void) {

    assignment_cast();

    force_type_cast();
}