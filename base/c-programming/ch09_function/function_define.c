/*
 * @author Anger
 * @date 2022/9/6
 * @brief 函数定义
 */
#include <stdio.h>

/**
 * 计算平均值的函数
 * @param a 第一个数值
 * @param b 第二个数值
 * @return 平均值
 *
 * 函数定义格式 返回值类型 函数名(形参类型2 形参名1,形参类型2, 形参名2,...) {复合语句}
 * 函数不能返回数组，但关于返回值类型没有其它的限制
 * 在 C89 中 变量声明必须出现在语句之前
 * 在 C99 中 变量声明和语句可以混合在一起，只要变量在第一次使用之前声明即可
 *
 * double average(double a, double b)
 * 第一个 double 是返回值的类型
 * a b 标识符是函数的形参(parameter)，表示在调用 average 函数需要提供的两个数
 * 每个形参都必须要有类型
 * 函数的形参本质上是变量
 * 它的值在调用函数时提供
 *
 * 花括号括起来的内容是函数的执行部分
 * 称为函数体
 * 每个函数体都是一个复合语句
 *
 * return 语句将会返回调用函数的地方
 *
 * 调用函数需要写出函数名以及实参(argument)列表
 * 实参用来给函数提供信息
 * 调用函数 average(x, y) 实际上就是把实参 x y 赋值给形参 a b
 * 实参不一定是变量
 * 任何符合形参类型的表达式都可以
 */
double average(double a, double b) {
    return (a + b) / 2;
}

/**
 * 调用 average 函数
 */
void average_invoke() {
    /*
     * 如果不需要非 void 函数的返回值
     * 可以将其丢弃
     *
     */
    average(1, 2);
    /* 可以在函数调用前显式加上 (void) 表示返回值是故意丢弃的
     * (void) 表示将返回值类型转换为 void 类型 */
    (void) average(1, 2);
    /* 使用常量作为函数的实参 */
    printf("%.2f\n", average(1, 2));

    /* 使用变量作为函数的实参 */
    float a = 2, b = 3;
    printf("%.2f\n", average(a, b));

    /* 使用符合形参的表达式作为函数的实参 */
    printf("%.2f\n", average(a + b, b * 2));
}

/**
 * 用户输入三个数值
 * 两两求平均数
 * 可以根据需要多次调用一个函数
 * 函数需要定义在 main() 函数前面
 * 不是所有的函数都需要返回一个值
 * 指明返回值类型为 void 表示函数不返回任何值
 */
void multi_average() {
    double x, y, z;
    printf("Enter 3 numbers : ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("average of x %g y %g : %g\n",x, y, average(x, y));
    printf("average of x %g z %g : %g\n",x, z, average(x, z));
    printf("average of y %g z %g : %g\n",y, z, average(y, z));
}

void print_count(int n) {
    printf("T minus %d and counting\n", n);
}

/**
 * 函数也可以没有形参
 * void 在此作为一个占位符
 * 表示不需要任何参数
 * 调用不带形参的函数只需要写函数名
 */
void countdown(void) {
    for (int i = 10; i > 0; i--)
        /* 函数执行完成后回到调用函数的地方 */
        print_count(i);
}

int main(void) {

    countdown();

    average_invoke();

    multi_average();

    return 0;
}