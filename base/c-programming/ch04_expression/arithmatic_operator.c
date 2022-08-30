/*
 * @author 刘昂林 
 * @date 2022/8/30
 * @brief 算数运算符
 */
#include <stdio.h>

/**
 * 一元运算符 + -
 * 只操作一个数
 * 一元运算符什么都不做
 * 只是用来表示一个数的正负
 */
void unary_operator() {
    int i, j;

    i = +1;
    j = -i;

    printf("%d %d\n", i, j);
}

/**
 * 二元运算符 + - * / %
 * 除了 % 运算符之外,其它的运算符既可以操作整数也可以操作浮点数
 * 运算符 / 操作两个整数时，会丢弃分数部分的结果，只截取整数部分的结果
 * 把 0 用于 % 和 /  的右操作数是会产生未定义的结果
 * 运算符 / 和 % 用于操作负数时，结果难以确定
 * C 语言中由实现定义行为的特性
 * C 标准故意对一部分的标准未加指定
 * 并认为其细节可以由实现来具体定义
 * 实现指的是程序在特定平台上的编译、链接和执行所需要的软件
 * 因此，根据实现的不同程序的行为可能会有所区别
 */
void binary_operator() {
    int i, j;
    float f;

    i  = j = 10;
    f = 2.5f;

    printf("i + f = %5.2f\n"
           "i - f = %5.2f\n"
           "i * f = %5.2f\n"
           "i / f = %5.2f\n"
           "i %% j = %5d\n",
           i + f, i - f, i * f, i / f, i % j);
}

/**
 * 作为通用的规则，c 语言允许使用圆括号对于表达式进行分组
 * 如果没有使用圆括号进行分组，c 语言采用运算符优先级规则来解决这些二义性的问题
 * 算数符的相对优先级如下：
 * 最高优先级 - + (一元运算符)
 * * / %
 * 最低优先级 + - (二元运算符)
 */
void operator_precedence() {
    int i, j;
    i = 4;
    j = 2;

    /* i + j * j 等价于 i + (j * j) */
    printf("i + j * j = %d\n", i + j * j);
    /* -i * -j 等价于 (-i) * (-j) */
    printf("-i * -j = %d\n", -i * -j);

    /*
     * 当表达式中包括两个或者以上的同级别的运算符时
     * 运算符的结合性开始发挥作用
     * 如果运算符是从左往右结合的，那么称这种运算符具备左结合性，二元运算符是左结合的
     * 如果运算符从右往左结合，那么这种运算符是右结合的，一元运算符具备右结合性
     * j % i * j 等价于 (j % i) * j
     * -+i 等价于 -(+i)
     * 如果分不清楚结合性，则使用括号将表达式括起来以显示指定操作顺序
     */
    printf("j %% i * j = %d\n", j % i * j);
    printf("-+i = %d\n", -+i);
}

void cal_product_code_check_digit() {
    puts("Calculate product code check digit number.");
    int d, i1, i2, i3, i4, i5,
            j1, j2, j3, j4, j5,
            first_sum, second_sum,
            check_digit_number;

    puts("Enter first number : ");
    /* %d 表示读取一位整数 d 表示第一位数字*/
    scanf("%1d", &d);
    puts("Enter first group of five digits : ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    puts("Enter second group of five digits : ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

    /*
     * 计算 1 3 5 7 9 11 位整数值的和
     * 计算 2 4 6 8 10 位整数的和
     */
    second_sum = i1 + i3 + i5 + j2 + j4;
    first_sum = d + i2 + i4 + j1 + j3 + j5;

    check_digit_number =
            9 - (first_sum * 3 + second_sum - 1) % 10;

    printf("check digit number : %d\n", check_digit_number);

    printf("Product Code : %d %d%d%d%d%d %d%d%d%d%d %d\n",
           d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, check_digit_number);
}

int main(void) {

    unary_operator();

    binary_operator();

    operator_precedence();

    cal_product_code_check_digit();

    return 0;
}