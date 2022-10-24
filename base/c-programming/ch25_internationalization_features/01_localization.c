/*
 * @author Anger
 * @date 2022/10/24
 * @brief 本地化
 */
#include <stdio.h>
#include <locale.h>

/* 类项 */
void category_macro(void);
/* 修改当前地区函数 */
void setlocale_func(void);
void localeconv_func(void);


int main(void) {
    category_macro();
    setlocale_func();
    localeconv_func();
    return 0;
}

void category_macro(void) {
    printf("LC_COLLATE 影响两个字符串的比较函数 => %d\n", LC_COLLATE);
    printf("LC_CTYPE 影响 ctype.h 中函数的行为 => %d\n", LC_CTYPE);
    printf("LC_MONETARY 影响由 localeconv 函数返回的货币格式 => %d\n", LC_MONETARY);
    printf("LC_NUMERIC 影响格式化输入/输出函使用的小数点字符\n"
           "           影响 stdlib.h 中的数值转换函数\n"
           "            影响 localeconv 函数返回的非货币格式信息 => %d\n", LC_NUMERIC);
    printf("LC_TIME 影响 strftime 的行为，该函数将时间转换成字符串\n"
           "C99 中还影响 wcsftime 函数 => %d\n", LC_TIME);
    printf("LC_ALL 影响以上所有的选项    => %d\n", LC_ALL);
}

void setlocale_func(void) {
    /* setlocale 函数修改当前的地区
     * 第二个参数仅提供 "C" 和 " " 两种可能值
     * 任意程序开始执行时，都会隐式调用 setlocale(LC_ALL, "C")
     * 地区设置为 C 时，库函数按照正常的方式执行
     * 如果第二个参数设置为 " " 则会切换到本地模式
     * 这种模式下程序会适应本地环境
     * 如果第二个参数是空指针 setlocale 会返回一个指向字符串的指针
     * 这个字符串与当前地区相关联 */
    printf("%s\n", setlocale(LC_ALL, NULL));
}

void localeconv_func(void) {
    /* lconv 结构成员存储了地区信息
     * 调用 localeconv() 函数返回这些信息 */
    struct lconv *conv = localeconv();
    printf("currency symbol => %s\n", conv->currency_symbol);
    printf("decimal point => %s\n", conv->decimal_point);
}