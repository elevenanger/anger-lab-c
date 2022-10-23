/*
 * @author Anger
 * @date 2022/10/23
 * @brief 数学计算
 */
#include <stdio.h>
#include <math.h>

/* 三角函数 */
void trigonometric_function(void);
/* 双曲函数 */
void hyperbolic_function(void);
/* 指数函数和对数函数 */
void exponential_and_logarithmic_function(void);
/* 幂函数 */
void power_function(void);
/* 舍入函数 */
void rounding_function(void);
/* 绝对值函数 */
void abs_function(void);
/* 余数函数 */
void mod_function(void);

int main(void) {

    trigonometric_function();

    hyperbolic_function();

    exponential_and_logarithmic_function();

    power_function();

    rounding_function();

    abs_function();

    mod_function();

    return 0;
}

void trigonometric_function(void) {
    printf("三角函数：\n");
    printf("余弦 cos(PI/4)                => %g\n", cos(M_PI_4));
    printf("正弦 sin(PI/4)                => %g\n", sin(M_PI_4));
    printf("正切 tan(PI/4)                => %g\n", tan(M_PI_4));
    printf("反余弦 acos(PI/4)             => %g\n", acos(M_PI_4));
    printf("反正弦 asin(PI/4)             => %g\n", asin(M_PI_4));
    printf("反正切 atan(PI/4)             => %g\n", atan(M_PI_4));
}

void hyperbolic_function(void) {
    printf("双曲函数：\n");
    printf("双曲余弦 cosh(0.5)            => %g\n", cosh(0.5));
    printf("双曲正弦 sinh(0.5)            => %g\n", sinh(0.5));
    printf("双曲正切 tanh(0.5)            => %g\n", tanh(0.5));
}

void exponential_and_logarithmic_function(void) {
    double int_part;

    printf("指数和对数函数：\n");
    printf("返回 e 的幂 exp(3.0)          => %g\n", exp(3.0));
    printf("以 e 为底的对数 log(20.0855)   => %g\n", log(20.0855));
    printf("以 10 为底的对数 log10(1000)   => %g\n", log10(1000));

    printf("modf(x, &a) = b 将 x 分成整数部分和小数部分\n"
           "将整数部分赋值为第二个参数所指的对象中\n"
           "返回小数部分的值\n"
           "modf(PI, &intpart)            => %g\n"
           "intpart                       => %g\n",
           modf(M_PI, &int_part), int_part);
}

void power_function(void) {
    printf("pow(a, b) 计算 a 的 b 次幂\n"
           "pow(3, 2)                     => %g\n", pow(3, 2));
    printf("sqrt(a) 计算 a 的平方根n"
           "sqrt(3)                       =>%g\n", sqrt(3));
}

void rounding_function(void) {
    printf("舍入函数\n");
    printf("向上取整 ceil(8.3)              => %g\n", ceil(8.3));
    printf("向下取整 floor(8.3)             => %g\n", floor(8.3));
}

void abs_function(void) {
    printf("绝对值函数\n");
    printf("fabs(-8.3)                      => %g\n", fabs(-8.3));
    printf("fabs(8.3)                       => %g\n", fabs(8.3));
}

void mod_function(void) {
    printf("取余数函数\n");
    printf("fmod(5.5, 2.2)                  => %g\n", fmod(5.5, 2.2));
}