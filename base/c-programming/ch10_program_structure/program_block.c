/*
 * @author Anger
 * @date 2022/9/10
 * @brief 程序块
 */
#include <stdio.h>

void switch_number(int i, int j);

int main(void) {

    switch_number(10,  20);
    switch_number(20,  10);

    return 0;
}

/**
 * 交换两个变量的值
 */
void switch_number(int i, int j) {
    printf("i => %d j => %d\n", i, j);
    /* 一个复合语句是一个程序块
     * 单并非只有这一种程序块
     * 在下面的例子中
     * 一份 if 语句是一个程序块
     * if 语句的每一个子句也是一个程序块
     * 默认情况下
     * 声明程序块的变量是自动存储期的
     * 进入程序块分配存储单元
     * 离开程序块回收分配的空间
     * 程序块拥有作用域，不能在程序块之外引用 */
    if (i < j) {
        /* 程函本身是一个程序块
         * 但是需要局部变量时
         * 函数体内的程序块也非常有用
         * 在程序块中放置局部变量有两个好处 ：
         * 1、避免函数体起始位置的声明与只是临时使用的变量相混淆
         * 2、减少名字冲突
         * 在这个例子中，if else 两个子语句中都有 tmp 临时变量
         * 它们之间互不冲突*/
        int tmp;
        tmp = i;
        i = j;
        j = tmp;
    } else {
        int tmp;
        tmp = i * 2;
        i = j;
        j = tmp;
    }
    printf("i => %d j => %d\n", i, j);
}
