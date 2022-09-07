/*
 * @author Anger
 * @date 2022/9/7
 * @brief 函数终止
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * main 函数返回值是状态码
 * 如果函数正常终止 main 函数返回 0
 * 如果是非正常终止 main 函数返回非 0 值
 * 程序有两种终止方式
 * return 表达式;
 * exit(表达式);
 * 二者的作用是等价的
 * return 语句和 exit 语句的差异：
 * 不管什么函数调用 exit 都会导致程序终止
 * return 语句仅当在 main 函数中调用时才会导致程序终止
 */
int main(void) {

    printf("exit process ... ");
    /*
     * 使用 exit 函数是终止程序的另一种方法
     * 传递给 exit 函数的值和 main 函数的返回值具有相同的含义
     * 两者都说明了程序终止时的状态
     */
    exit(EXIT_SUCCESS);
}