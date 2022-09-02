/*
 * @author Anger
 * @date 2022/9/2
 * @brief 类型定义
 */
#include <stdio.h>
#include <stdint.h>

/*
 * 类型定义使得程序更加易于理解
 * 假设变量 cash_in cash_out 用来存储人民币数量
 * 把 Yuan 使用以下代码声明
 * 这种写法更有实际意义
 * 类型定义使得程序更加易于修改
 * 如果以后 Yuan 的类型需要修改为 double 类型
 * 只需要修改类型定义即可
 */
typedef float Yuan;

/*
 * c 语言会使用类型定义来解决部分场景的可移植性问题
 * c 语言会为那些根据 c 语言的实现不同而不同的类型创建类型名
 * 这些类型通常以 t 结尾
 */
size_t size;
int32_t int32;

Yuan cash_in, cash_out;

void cash_operation() {
    cash_in = 100;
    cash_out = 50;
    Yuan balance = 0;
    balance += cash_in;
    balance -=cash_out;
    printf("balance : %.2f\n", balance);
}

int main(void) {

    cash_operation();

}