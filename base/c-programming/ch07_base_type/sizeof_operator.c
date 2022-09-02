/*
 * @author Anger
 * @date 2022/9/2
 * @brief sizeof 运算符
 * sizeof 运算符允许程序存储指定类型值所需空间的大小
 */
#include <stdio.h>

int main(void) {
    /*
     * sizeof 表达式的值是一个无符号整数
     * 单表存储属于类型名的值所需要的字节数
     * sizeof 可以用于常量、变量和表达式
     * 应用于类型
     */
    printf("sizeof(char) : %lu\n", sizeof(char));
    /* 应用于变量 */
    double d;
    printf("sizeof(d) : %lu\n", sizeof(d));
    /* 应用于常量 */
    printf("sizeof(12.0e2) : %lu\n", sizeof(12.0e2));
    /* 应用于表达式 */
    printf("sizeof(d > 1) : %lu\n", sizeof(d > 1));

}