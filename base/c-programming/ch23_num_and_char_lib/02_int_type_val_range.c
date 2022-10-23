/*
 * @author Anger
 * @date 2022/10/23
 * @brief 整数类型的取值范围
 */
#include <stdio.h>
#include <limits.h>

/* 字符类型宏 */
void char_macro(void);
/* 整数类型宏 */
void int_limits_macro(void);

int main(void) {

    char_macro();

    int_limits_macro();

    return 0;
}

void char_macro(void) {
    printf("字符类型宏：\n");
    printf("CHAR_BIT 每个字符包含的位数                            => %d\n",   CHAR_BIT);
    printf("SCHAR_MIN 最小的 signed char 类型值                   => %d\n",   SCHAR_MIN);
    printf("SCHAR_MAX 最大的 signed char 类型值                   => %d\n",   SCHAR_MAX);
    printf("UCHAR_MAX 最大的 unsigned char 类型值                 => %d\n",   UCHAR_MAX);
    printf("CHAR_MIN 最小的 char 类型值                           => %d\n",   CHAR_MIN);
    printf("CHAR_MAX 最大的 char 类型值                           => %d\n",   CHAR_MAX);
    printf("MB_LEN_MAX 多字节字符最多包含的字节数                   => %d\n",   MB_LEN_MAX);
}

void int_limits_macro(void) {
    printf("整数类型宏：\n");
    printf("SHRT_MIN 最小的 short int 类型值                      => %d\n",   SHRT_MIN);
    printf("SHRT_MAX 最大的 short int 类型值                      => %d\n",   SHRT_MAX);
    printf("USHRT_MAX 最大的 unsigned short int 类型值            => %d\n",   USHRT_MAX);
    printf("INT_MIN 最小的 int 类型值                             => %d\n",   INT_MIN);
    printf("INT_MAX 最大的 int 类型值                             => %d\n",   INT_MAX);
    printf("UINT_MAX 最大的 unsigned int 类型值                   => %ud\n",  UINT_MAX);
    printf("LONG_MIN 最小的 long int 类型值                       => %ld\n",  LONG_MIN);
    printf("LONG_MAX 最大的 long int 类型值                       => %ld\n",  LONG_MAX);
    printf("ULONG_MAX 最大的 unsigned long int 类型值             => %lu\n",  ULONG_MAX);
    /* C99 新增 long long int 相关的宏 */
    printf("LLONG_MIN 最小的 long long int 类型值                 => %lld\n", LLONG_MIN);
    printf("LLONG_MAX 最大的 long long int 类型值                 => %lld\n", LLONG_MAX);
    printf("ULLONG_MAX 最大的 unsigned long long int 类型值       => %llu\n", ULLONG_MAX);
}
