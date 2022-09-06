/*
 * 函数的实参
 * 函数的形参：出现在函数的定义中，以假的名字来表示函数调用时需要提供的值
 * 函数的实参：出现在函数调用中的表达式
 * 形参和实参差异不是很重要的时候，使用参数表示二者中的任意一个
 */
#include <stdio.h>

int power(int x, int p);

/**
 * 计算 x 的 p 次幂
 * @param x 原始数值
 * @param p 次幂
 * @return x ^ p
 *
 * c 语言中
 * 实参是值传递的
 * 调用函数时计算出每个实参表达式的值
 * 将其赋值给形参
 * 在函数执行的过程中
 * 形参的变化不会影响实参的值
 * 因为形参中包含的是实参的副本
 * 从效果上来说
 * 每个形参的行为好像是把变量初始化为与之相匹配的实参的值
 * 实参的值传递有利有弊
 * 因为形参的修改不会改变实参的值
 * 所以可以把形参当做函数的变量来使用
 * 可以减少真正需要的变量的数量
 */
int power(int x, int p) {
    int result = 1;
    /* 因为形参 p 不会改变实参的值
     * 可以对其在函数内进行修改
     * 可以减少变量的数量 */
    while (p-- > 0)
        result *= x;
    return result;
}

/**
 * 尝试将一个浮点数值分解成整数和小数部分
 * 因为函数无法返回两个数
 * 可以尝试把两个变量传递给函数
 * 分别在函数中修改为整数部分和小数部分
 * 但是下面这种做法其实是无效的
 * @param x 浮点数
 * @param int_part 整数部分变量
 * @param frac_part 小数部分变量
 * 因为函数参数是值传递的
 * 实参不会因为形参在函数内部的修改受到影响
 * 所以函数调用前后实参的值是不会发生变化的
 */
void decompose(double x, long int_part, double frac_part) {
    /*尝试将浮点数 x 分解成整数部分和小数部分*/
    int_part = (long) x;
    frac_part = x - (double)int_part;
    printf("decompose %f int part : %ld\n"
           "fraction part : %f\n",
           x, int_part, frac_part);
}

/* 测试对形参的修改不会影响实参的值 */
void test_ineffective_modify() {

    double x = 3.14, frac_part = 0;
    long int_part = 0;

    decompose(x, int_part, frac_part);

    printf("test decompose %f int part : %ld\n"
           "fraction part : %f\n",
           x, int_part, frac_part);
}

/**
 * 计算一个数的平方值
 */
int square(int n) {
    return n * n;
}

/* 测试实参类型转换 */
void test_argument_transform() {
    /*
     * 实参的类型与形参的类型可以不同
     * 管理实参的转换与编译器是否在调用前遇到函数的原型有关
     * 编译器在调用前遇到函数原型：
     * 就像使用赋值一样
     * 每个实参的值都被隐式转换为形参的类型
     * 编译器在调用前没有遇到原型
     * 编译器执行默认的参数提升
     * (1) 把 float 提升为 double
     * (2) 执行整值提升 把 char short 转为 int 类型
     * C99 实现整值提升
     */
    double d = 10;
    printf("square of %f : %d", d, square(d));
}

int main(void) {

    printf("%d to the power of %d : %d\n", 2, 3, power(2, 3));

    test_ineffective_modify();

    test_argument_transform();

    return 0;
}