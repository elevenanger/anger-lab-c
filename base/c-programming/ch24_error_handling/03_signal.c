/*
 * @author Anger
 * @date 2022/10/24
 * @brief 信号
 * 信号分为两种
 * 运行时错误
 * 发生在程序以外的事件
 * 当有错误或者外部事件发生时
 * 产生了一个信号
 * 大多数信号是异步的
 * 它们可以在程序执行的过程中的任意时刻发生
 * 必须使用一种独特的方式来处理信号
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/* 信号宏 */
void signal_macro(void);
/* 信号函数 */
void signal_function(void);
void sigterm_handler(int sig);
/* 触发信号 */
void raise_function(void);

int main(void) {
    signal_macro();
    signal_function();
    raise_function();
    return 0;
}

void signal_macro(void) {
    printf("SIGABRT 异常终止                        => %d\n", SIGABRT);
    printf("SIGFPE  算数运算发生错误                 => %d\n", SIGFPE);
    printf("SIGILL  无效指令                        => %d\n", SIGILL);
    printf("SIGINT  中断                            => %d\n", SIGINT);
    printf("SIGSEGV 无效存储访问                     => %d\n", SIGSEGV);
    printf("SIGTERM 终止请求                        => %d\n", SIGTERM);
}

void signal_function(void) {
    /* signal 函数第一个参数是特定的信号编码
     * 第二个参数是一个指向信号发生时处理这一信号的函数指针
     * 安装信号处理函数 */
    signal(SIGTERM, sigterm_handler);
}

void sigterm_handler(int sig) {
    fprintf(stderr, "sigterm handled.\n");
}

void raise_function(void) {
    /* raise 函数用于触发信号 */
    raise(SIGTERM);
}
