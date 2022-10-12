/*
 * @author Anger
 * @date 2022/10/12
 * @brief C11 _Noreturn 关键字
 * 如果一个函数声明里有这个关键字，表示它不返回调用者
 */
#include <stdio.h>
#include <stdnoreturn.h>
#include <stdlib.h>

noreturn void f(void);

int main(void) {
    f();
}

noreturn void f(void) {
    printf("not return to caller.\n");
    exit(0);
}
