/*
 * @author Anger
 * @date 2022/10/24
 * @brief 错误
 */
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void error_check(double d);

void perror_check(double d);

void strerror_check(double d);

int main(void) {

    double d = -1.0;

    error_check(d);

    perror_check(d);

    strerror_check(d);
    return 0;
}

void error_check(double d) {
    double x;
    /* errno 是一个宏
     * 假设使用的库函数通过给 errno 赋值来检查函数调用是否正常
     * 将 errno 置位 0
     * 函数执行完成后检查 errno 是否为 0 */
    errno = 0;
    x = sqrt(d);
    if (errno != 0) {
        fprintf(stderr, "sqrt 函数调用失败\n");
        exit(EXIT_FAILURE);
    }

    printf("x = sqrt(%lf) = %lf\n", d, x);
}


void perror_check(double d) {
    double x;
    errno = 0;
    x = sqrt(d);

    if (errno != 0) {
        /* perror 根据 errno 显示错误信息 */
        perror("sqrt error");
        exit(EXIT_FAILURE);
    }
    printf("x = sqrt(%lf) = %lf\n", d, x);
}

void strerror_check(double d) {
    double x;
    errno = 0;
    x = sqrt(d);

    if (errno != EDOM) {
        /* strerror 当以错误码为参数调用函数
         * 会返回一个指针
         * 指向描述这个错误的字符串 */
        puts(strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("x = sqrt(%lf) = %lf\n", d, x);
}
