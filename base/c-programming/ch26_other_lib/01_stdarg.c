/*
 * @author Anger
 * @date 2022/10/26
 * @brief 可变参数
 */
#include <stdarg.h>
#include <stdio.h>

/* 传入一系列的整数，返回其中的最大值 */
int max_int(int n, ...);

int main(void) {

    printf("max number => %d\n", max_int(6, 1, 2, 3, 10, 5, 6));

    return 0;
}

/**
 *
 * @param n 表示参数格式
 * @param ... 任意数量的参数
 * @return 最大的数值
 */
int max_int(int n, ...) {
    /* 声明 va_list 变量 */
    va_list ap;
    int i, current, largest;

    /* 使函数可以访问到 n 后面的实参*/
    va_start(ap, n);
    /* 第一个 int 类型参数 */
    largest = va_arg(ap, int);

    for (i = 1; i < n; ++i) {
        /* 遍历所有参数 */
        current = va_arg(ap, int);
        if (current > largest)
            largest = current;
    }

    /* 函数返回之前，需要使用 va_end(ap) 进行清理 */
    va_end(ap);
    return largest;
}
