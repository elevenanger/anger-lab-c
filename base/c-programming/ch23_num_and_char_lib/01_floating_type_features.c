/*
 * @author Anger
 * @date 2022/10/23
 * @brief 浮点类型特性
 */
#include <stdio.h>
#include <float.h> /* 用来定义 float double 和 long double 类型的范围及精度的宏 */

/* 舍入方向 */
void rounding_direction(void);
/* 指数中的基数 */
void radix_number(void);
/* 数字宏 */
void digital_macro(void);
/* 指数宏 */
void exponential_macro(void);
/* 最大值宏 */
void max_val_macro(void);
/* 最小正值宏 */
void min_val_macro(void);
/* 最小差值宏 */
void min_diff_value(void);
/* c99 求值方法宏 */
void eval_method_macro(void);

int main(void) {

    rounding_direction();

    radix_number();

    digital_macro();

    exponential_macro();

    max_val_macro();

    min_val_macro();

    min_diff_value();

    eval_method_macro();

    return 0;
}

void rounding_direction(void) {
    printf(" 浮点加法的舍入方向 => %d\n"
           "-1 不确定\n"
           " 0 趋零截尾\n"
           " 1 向最近的整数舍入\n"
           " 2 向正无穷的方向舍入\n"
           " 3 向负无穷的方向舍入\n",
           FLT_ROUNDS);
}

void radix_number(void) {
    printf("指数中的基数 => %d \n", FLT_RADIX);
}

void digital_macro(void) {
    printf("有效数字个数 基数 FLT_RADIX : \n");
    printf("float 有效数字 => %d\n", FLT_MANT_DIG);
    printf("double 有效数字 => %d\n", DBL_MANT_DIG);
    printf("long double 有效数字 => %d\n", LDBL_MANT_DIG);
    printf("有效数字个数(十进制)：\n");
    printf("float 有效数字 => %d\n", FLT_DIG);
    printf("double 有效数字 => %d\n", DBL_DIG);
    printf("long double 有效数字 => %d\n", LDBL_DIG);
}

void exponential_macro(void) {
    printf("FLT_RADIX 最小（负）次幂：\n");
    printf("float 最小次幂 => %d\n", FLT_MIN_EXP);
    printf("double 最小次幂 => %d\n", DBL_MIN_EXP);
    printf("long double 最小次幂 => %d\n", LDBL_MIN_EXP);
    printf("10 进制的最小次幂：\n");
    printf("float 最小次幂 => %d\n", FLT_MIN_10_EXP);
    printf("double 最小次幂 => %d\n", DBL_MIN_10_EXP);
    printf("long double 最小次幂 => %d\n", LDBL_MIN_10_EXP);
    printf("FLT_RADIX 最大次幂：\n");
    printf("float 最大次幂 => %d\n", FLT_MAX_EXP);
    printf("double 最大次幂 => %d\n", DBL_MAX_EXP);
    printf("long double 最大次幂 => %d\n", LDBL_MAX_EXP);
    printf("10 进制最大次幂：\n");
    printf("float 最大次幂 => %d\n", FLT_MAX_10_EXP);
    printf("double 最大次幂 => %d\n", DBL_MAX_10_EXP);
    printf("long double 最大次幂 => %d\n", LDBL_MAX_10_EXP);
}

void max_val_macro(void) {
    printf("最大值的宏定义：\n");
    printf("float 最大值 => %f\n", FLT_MAX);
    printf("double 最大值 => %f\n", DBL_MAX);
    printf("long double 最大值 => %Lf\n", LDBL_MAX);
}

void min_val_macro(void) {
    printf("最小正值的宏定义：\n");
    printf("float 最小值 => %f\n", FLT_MIN);
    printf("double 最小值 => %f\n", DBL_MIN);
    printf("long double 最小值 => %Lf\n", LDBL_MIN);
}

void min_diff_value(void) {
    printf("最小差值的宏定义：\n");
    printf("float 最小差值 => %f\n", FLT_EPSILON);
    printf("double 最小差值 => %f\n", DBL_EPSILON);
    printf("long double 最小差值 => %Lf\n", LDBL_EPSILON);
}

void eval_method_macro(void) {
    printf("C99 定义的求值方法：\n");
    printf("FLT_EVAL_METHOD => %d 值说明具体的实现中是否用到了超过实际需要的范围和精度的浮点运算\n"
           "-1 不确定\n"
           "0 根据类型的范围和精度对所有运算和常量求值\n"
           "1 根据 double 类型的范围和精度对所有的 float 和 double 类型的运算和常量求值\n"
           "2 根据 long double 类型的范围和精度对所有的类型的运算和常量求值\n",
           FLT_EVAL_METHOD);
}
