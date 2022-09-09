/*
 * @author Anger
 * @date 2022/9/9
 * @brief 局部变量
 */
#include <stdio.h>

int sum_digits(int a);

/**
 * 计算一个十进制数每位的和
 * @param a 形参
 * @return 和
 * 形参具有和局部变量相同的临时存储器和块作用域
 * 形参和局部变量的唯一区别是
 * 形参在函数调用时进行初始化
 */
int sum_digits(int a) {
    /* 局部变量
     * 自动存储期 ：变量的存储期是程序执行时，能过确保变量存储空间一定存在的那一部分时间
     * 通常来说，局部变量的存储空间是在包含该变量的函数被调用时自动分配的
     * 函数返回时回收空间
     * 所以这种变量具有自动存储期
     * 块作用域 ：变量的作用域是可以引用该变量的那一部分程序文本
     * 局部变量具有块作用域
     * 从变量声明开始一直到函数的结尾
     * 在这个例子中 sum 变量从函数开始声明
     * 一直到函数结束返回
     * 作用域是从函数的开始到结束
     * C99 允许不在函数一开始就声明变量
     * 局部变量的作用域可能非常小
     * */
    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

void test_local_variable(void) {
    int n = 123;
    printf("sum digit of %d => %d\n", n, sum_digits(n));
}

void human_life(void) {
    /*
     * 在变量之前添加 static 关键字
     * 使变量具有静态存储期
     * 静态存储器的变量具有永久的存储单元
     * 在整个程序执行期间都会保留该变量的值
     * 静态变量始终具有块作用域
     * 所以它对于其它的函数是不可见的
     * 静态变量是对于其它函数隐藏数据的地方
     * 但是它会为将来同一个函数的再调用保留这份数据
     */
    static int human_life;
    if (!human_life) {
        human_life = 100;
        printf("initializing human life ==> %d\n",human_life);
    } else {
        printf("human life => %d\n", human_life);
    }
}

void test_static_variable() {
    human_life();
    human_life();
}

int main(void) {

    test_local_variable();

    test_static_variable();

    return 0;
}