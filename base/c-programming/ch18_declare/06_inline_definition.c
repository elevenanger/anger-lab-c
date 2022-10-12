/*
 * @author Anger
 * @date 2022/10/12
 * @brief C99 内联定义
 */
#include <stdio.h>

static inline double average(double a, double b);

int main(void) {
    printf("\n内联定义 => %s\n", __FILE_NAME__);

    printf("average(10, 13) => %g\n", average(10, 13));

    return 0;
}

/**
 * 内联函数使用 inline 作为一个声明指定符
 * 内联表明编译器将函数的每一次调用都用函数的机器指令来代替
 * 内联函数是内联定义
 * 不能有外部链接，视图在别的文件中调用内联函数将被当做错误
 * 为了避免这种情况可以在函数定义中增加 static 关键字，使其具有内部链接
 */
static inline double average(double a, double b) {
    return (10.0 + b) / 2;
}
