/*
 * @author Anger
 * @date 2022/9/10
 * @brief 作用域
 * 当程序块内声明了一个标识符
 * 如果此标识符已经是可见的
 * 新的声明（同样的标识符）临时隐藏了旧的声明
 * 在程序块的末尾，标识符重新获得含义
 */
#include <stdio.h>

/*
 * 第一次声明
 * 声明一个全局变量 i
 * 此时 i 是具有整个文件的作用域的变量
 * */
int i = 0;

void f(int i);
void g(void);
void h(void);

int main(void) {

    f(3);
    printf("i => %d\n", i);
    g();
    printf("i => %d\n", i);
    h();
    printf("i => %d\n", i);

    return 0;
}

/**
 * 在第二次声明中
 * i 是具有块作用域的函数的形参
 * 在形参的作用域内隐藏了第一次的声明
 * 在函数调用结束后 i 重新获得旧的含义
 */
void f(int i) {
    i = 1;
    printf("i => %d\n", i);
}

void g(void) {
    /* 这个声明中 i 是具有块作用域的函数内的局部变量 */
    int i = 2;
    printf("i => %d\n", i);
    if (i > 0) {
        /* 这个声明中 i 是具有块作用域的函数内的局部变量 */
        int i;
        i = 3;
        printf("i => %d\n", i);
    }
    i = 4;
    printf("i => %d\n", i);
}

void h(void) {
    /* 这里不进行声明，对全局变量 i 进行赋值*/
    i = 5;
    printf("i => %d\n", i);
}
