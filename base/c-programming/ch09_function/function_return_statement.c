/*
 * @author Anger
 * @date 2022/9/7
 * @brief return 语句格式 return 表达式;
 */
#include <stdio.h>

int sum(int a, int b);
void print_int(int);

int sum(int a, int b) {
    /*
     * return 语句表达式经常是常量或者变量
     * 但是也可以是更复杂的表达式
     */
    return a + b;
}

/*
 * 返回值类型为 void 的函数
 * 不需要 return 语句
 * 也可在函数的末尾使用 return 关键字
 */
void print_int(int i) {
    printf("int i = %d\n", i);
}

int main(void) {

    print_int(sum(1, 2));

    return 0;
}