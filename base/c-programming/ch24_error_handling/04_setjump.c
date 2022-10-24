/*
 * @author Anger
 * @date 2022/10/24
 * @brief 非局部跳转
 */
#include <setjmp.h>
#include <stdio.h>

jmp_buf env;

void f1(void);
void f2(void);

int main(void) {

    if (setjmp(env) == 0)
        printf("setjmp returned 0\n");
    else {
        printf("program terminates: longjmp called\n");
        return 0;
    }

    f1();
    printf("program terminates normally\n");

    return 0;
}

void f1(void) {
    printf("f1 begins \n");
    f2();
    printf("f1 return\n");
}

void f2(void) {
    printf("f2 begins\n");
    longjmp(env, 1);
    printf("f2 returns\n");
}